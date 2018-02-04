using System;
using System.Collections.Generic;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Windows.Forms;

namespace DomainToDB
{
	public partial class FormEmployee:Form
	{
		EmployeeModelContainer employees = new EmployeeModelContainer();
		// selectDepartment represents an invalid combobox item
		// either blank or "Select Department" (see constructor)
		// At the class level as it is used in 2 methods (validate.. & fill..)
		readonly Department selectDepartment = new Department();
		// Converted during validation, consumed by buttonAddEmployee_Click
		int age;

		public FormEmployee()
		{
			InitializeComponent();

			// Used by comboBoxDepartment as an invalid item
			selectDepartment.DepartmentID = -1;
			selectDepartment.DeptName = "Select Department...";
		}

		private void refreshGrid()
		{
			var employeeRoster =
				from employee in employees.Employees
				orderby employee.FirstName
				select new  {
					employee.EmployeeID,
					employee.FirstName,
					employee.LastName,
					employee.Age,
					employee.Department.DeptName
				};

			dataGridViewEmployees.DataSource = employeeRoster.ToList();
			allowDeletes(false);     // Force User to select Employee to delete
		}

		// Toggle the availability of buttonDeleteEmployee
		private void allowDeletes(bool allow)
		{
			if (allow)
			{
				// User can delete or add at a time.
				buttonDeleteEmployee.Enabled = true;
				clearBoxes();
			}
			else
			{
				// User is forced to select an Employee in the grid to delete
				// so if they leave the grid, disable the delete funtionality
				buttonDeleteEmployee.Enabled = false;
				dataGridViewEmployees.ClearSelection();
			}
		}

		// Different methods call to clear the 'boxes.
		private void clearBoxes()
		{
			// Clear the textboxes
			textBoxFirstName.Text = "";
			textBoxLastName.Text = "";
			textBoxAge.Text = "";
			// ComboBox isn't cleared, it's set to invalid selection
			comboBoxDepartment.SelectedItem = selectDepartment;
		}

		private void fillComboBoxDepartment()
		{
			// Query used just for the sort (orderby)
			var departments =
				from department in employees.Departments
				orderby department.DeptName
				select department;

			// Manually add an "invalid" department into the list followed by the
			// query (I haven't worked out adding it at the query level yet)
			List<Department> departmentList = new List<Department>();
			departmentList.Add(selectDepartment);
			// And bind the combined list
			departmentList.AddRange(departments.ToList());
			comboBoxDepartment.DataSource    = departmentList; //departments.ToList();
			comboBoxDepartment.DisplayMember = "DeptName";
			comboBoxDepartment.ValueMember   = "DepartmentID";
			// Only allow loaded values
			comboBoxDepartment.DropDownStyle = ComboBoxStyle.DropDownList;
		}

		// Called by the 'boxes change events
		private void validateBoxes(object sender, EventArgs e)
		{
			// Don't allow adding when the textboxes are empty,
			// the comboBox shows the invalid entry,
			// or, textBoxAge holds something besides a non-positive integer
			buttonAddEmployee.Enabled = 
				(Department)comboBoxDepartment.SelectedItem != selectDepartment &&
				!string.IsNullOrWhiteSpace(comboBoxDepartment.Text) &&
				!string.IsNullOrWhiteSpace(textBoxFirstName.Text) &&
				!string.IsNullOrWhiteSpace(textBoxLastName.Text) &&
				!string.IsNullOrWhiteSpace(textBoxAge.Text) &&
				int.TryParse(textBoxAge.Text, out age) &&
				age >  0;				// Check for valid value after converting
		}

		// When User clicks an employee in the DataGridView, the delete button will enable
		private void enableDeleteButton(object sender,DataGridViewCellEventArgs e)
		{
			allowDeletes(true);
		}

		// If the User clicks into any of the 'boxes, their intent is to add so
		// delete is disabled and employee selection in DataGridView unselected
		private void disableDeleteButton(object sender, EventArgs e)
		{
			allowDeletes(false);
		}

		private void FormEmployee_Load(object sender,EventArgs e)
		{
			// Finish setting up the DataGridView; whole row single selection and
			// alternating colors
			dataGridViewEmployees.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
			dataGridViewEmployees.MultiSelect = false;
			dataGridViewEmployees.AlternatingRowsDefaultCellStyle.BackColor = Color.PeachPuff;
			dataGridViewEmployees.RowsDefaultCellStyle.BackColor = Color.BlanchedAlmond;

			refreshGrid();							// Initial pull from the database
			fillComboBoxDepartment();				// Load the ComboBox from database
			buttonAddEmployee.Enabled = false;      // Disable Add until 'boxes validate
		}

		private void buttonAddEmployee_Click(object sender,EventArgs e)
		{
			Employee newEmployee   = new Employee();

			// Fill in the data from the already validated form 'boxes

			// Using the auto-built Employee object, its int properties default to 0
			// and the adding to database will overwrite those zeroes with proper values
			newEmployee.FirstName  = textBoxFirstName.Text;
			newEmployee.LastName   = textBoxLastName.Text;
			newEmployee.Age        = age;				// Saved during validation
			newEmployee.Department = (Department)comboBoxDepartment.SelectedItem;

			employees.Employees.Add(newEmployee);		// Save to entity
			employees.SaveChanges();					// And the database

			// Refresh form with updated data and clear boxes
			refreshGrid();
			clearBoxes();
		}

		private void buttonDeleteEmployee_Click(object sender,EventArgs e)
		{
			int deleteID = (int)dataGridViewEmployees.CurrentRow.Cells["EmployeeID"].Value;
			bool deleteFailed = false;

			try
			{
				var deleteEmployee =
					(from employee in employees.Employees
					where employee.EmployeeID == deleteID
					select employee).Single();

				DialogResult response = MessageBox.Show(
					"Delete " + deleteEmployee.FirstName + " " + deleteEmployee.LastName +
					" in " + deleteEmployee.Department.DeptName + "?",
					"Delete Confirmation",
					MessageBoxButtons.YesNo);
				if (response == DialogResult.Yes)
				{
					employees.Employees.Remove(deleteEmployee);
					employees.SaveChanges();
					refreshGrid();				// Only need to refresh grid if deleting
				}
			}
			catch (OptimisticConcurrencyException)
			{
				deleteFailed = true;
			}
			catch (InvalidOperationException)
			{
				// In trying to test for Concurrency exception, I got this exception
				// instead, so catching them both.
				deleteFailed = true;
			}

			if (deleteFailed)
			{
				MessageBox.Show(
					"Unable to delete employee.\nPlease verify and try again",
					"Delete unsuccessful",
					MessageBoxButtons.OK,
					MessageBoxIcon.Exclamation);
				// Reload data; most likely cause of delete fail is that the
				// employee is already deleted or the connection to the database
				// is lost
				refreshGrid();
			}
		}
	}
}
