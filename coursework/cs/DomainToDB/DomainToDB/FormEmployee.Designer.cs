namespace DomainToDB
{
	partial class FormEmployee
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if(disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.dataGridViewEmployees = new System.Windows.Forms.DataGridView();
			this.textBoxFirstName = new System.Windows.Forms.TextBox();
			this.textBoxLastName = new System.Windows.Forms.TextBox();
			this.comboBoxDepartment = new System.Windows.Forms.ComboBox();
			this.lblFirstName = new System.Windows.Forms.Label();
			this.lblLastName = new System.Windows.Forms.Label();
			this.lblAge = new System.Windows.Forms.Label();
			this.lblDepartment = new System.Windows.Forms.Label();
			this.buttonAddEmployee = new System.Windows.Forms.Button();
			this.buttonDeleteEmployee = new System.Windows.Forms.Button();
			this.textBoxAge = new System.Windows.Forms.TextBox();
			this.labelInfo = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.dataGridViewEmployees)).BeginInit();
			this.SuspendLayout();
			// 
			// dataGridViewEmployees
			// 
			this.dataGridViewEmployees.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
			this.dataGridViewEmployees.Location = new System.Drawing.Point(13, 13);
			this.dataGridViewEmployees.Name = "dataGridViewEmployees";
			this.dataGridViewEmployees.Size = new System.Drawing.Size(552, 280);
			this.dataGridViewEmployees.TabIndex = 0;
			this.dataGridViewEmployees.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.enableDeleteButton);
			// 
			// textBoxFirstName
			// 
			this.textBoxFirstName.Location = new System.Drawing.Point(13, 330);
			this.textBoxFirstName.Name = "textBoxFirstName";
			this.textBoxFirstName.Size = new System.Drawing.Size(124, 20);
			this.textBoxFirstName.TabIndex = 2;
			this.textBoxFirstName.TextChanged += new System.EventHandler(this.validateBoxes);
			this.textBoxFirstName.Enter += new System.EventHandler(this.disableDeleteButton);
			// 
			// textBoxLastName
			// 
			this.textBoxLastName.Location = new System.Drawing.Point(151, 330);
			this.textBoxLastName.Name = "textBoxLastName";
			this.textBoxLastName.Size = new System.Drawing.Size(124, 20);
			this.textBoxLastName.TabIndex = 4;
			this.textBoxLastName.TextChanged += new System.EventHandler(this.validateBoxes);
			this.textBoxLastName.Enter += new System.EventHandler(this.disableDeleteButton);
			// 
			// comboBoxDepartment
			// 
			this.comboBoxDepartment.Location = new System.Drawing.Point(363, 330);
			this.comboBoxDepartment.Name = "comboBoxDepartment";
			this.comboBoxDepartment.Size = new System.Drawing.Size(124, 21);
			this.comboBoxDepartment.TabIndex = 8;
			this.comboBoxDepartment.SelectedIndexChanged += new System.EventHandler(this.validateBoxes);
			this.comboBoxDepartment.Enter += new System.EventHandler(this.disableDeleteButton);
			// 
			// lblFirstName
			// 
			this.lblFirstName.AutoSize = true;
			this.lblFirstName.Location = new System.Drawing.Point(13, 311);
			this.lblFirstName.Name = "lblFirstName";
			this.lblFirstName.Size = new System.Drawing.Size(57, 13);
			this.lblFirstName.TabIndex = 1;
			this.lblFirstName.Text = "&First Name";
			// 
			// lblLastName
			// 
			this.lblLastName.AutoSize = true;
			this.lblLastName.Location = new System.Drawing.Point(151, 311);
			this.lblLastName.Name = "lblLastName";
			this.lblLastName.Size = new System.Drawing.Size(58, 13);
			this.lblLastName.TabIndex = 3;
			this.lblLastName.Text = "&Last Name";
			// 
			// lblAge
			// 
			this.lblAge.AutoSize = true;
			this.lblAge.Location = new System.Drawing.Point(289, 311);
			this.lblAge.Name = "lblAge";
			this.lblAge.Size = new System.Drawing.Size(26, 13);
			this.lblAge.TabIndex = 5;
			this.lblAge.Text = "A&ge";
			// 
			// lblDepartment
			// 
			this.lblDepartment.AutoSize = true;
			this.lblDepartment.Location = new System.Drawing.Point(363, 311);
			this.lblDepartment.Name = "lblDepartment";
			this.lblDepartment.Size = new System.Drawing.Size(62, 13);
			this.lblDepartment.TabIndex = 7;
			this.lblDepartment.Text = "De&partment";
			// 
			// buttonAddEmployee
			// 
			this.buttonAddEmployee.Location = new System.Drawing.Point(13, 366);
			this.buttonAddEmployee.Name = "buttonAddEmployee";
			this.buttonAddEmployee.Size = new System.Drawing.Size(124, 23);
			this.buttonAddEmployee.TabIndex = 9;
			this.buttonAddEmployee.Text = "&Add Employee";
			this.buttonAddEmployee.UseVisualStyleBackColor = true;
			this.buttonAddEmployee.Click += new System.EventHandler(this.buttonAddEmployee_Click);
			// 
			// buttonDeleteEmployee
			// 
			this.buttonDeleteEmployee.Location = new System.Drawing.Point(13, 411);
			this.buttonDeleteEmployee.Name = "buttonDeleteEmployee";
			this.buttonDeleteEmployee.Size = new System.Drawing.Size(124, 23);
			this.buttonDeleteEmployee.TabIndex = 10;
			this.buttonDeleteEmployee.Text = "&Delete Employee";
			this.buttonDeleteEmployee.UseVisualStyleBackColor = true;
			this.buttonDeleteEmployee.Click += new System.EventHandler(this.buttonDeleteEmployee_Click);
			// 
			// textBoxAge
			// 
			this.textBoxAge.Location = new System.Drawing.Point(289, 330);
			this.textBoxAge.Name = "textBoxAge";
			this.textBoxAge.Size = new System.Drawing.Size(60, 20);
			this.textBoxAge.TabIndex = 6;
			this.textBoxAge.TextChanged += new System.EventHandler(this.validateBoxes);
			this.textBoxAge.Enter += new System.EventHandler(this.disableDeleteButton);
			// 
			// labelInfo
			// 
			this.labelInfo.AutoSize = true;
			this.labelInfo.Location = new System.Drawing.Point(289, 366);
			this.labelInfo.MaximumSize = new System.Drawing.Size(276, 68);
			this.labelInfo.Name = "labelInfo";
			this.labelInfo.Size = new System.Drawing.Size(210, 65);
			this.labelInfo.TabIndex = 11;
			this.labelInfo.Text = "To add an Employee, fill in the boxes and\r\nclick \"Add Employee\"\r\n\r\nTo delete an e" +
    "mployee, select them on grid\r\nand click \"Delete Employee\"";
			// 
			// FormEmployee
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(578, 458);
			this.Controls.Add(this.labelInfo);
			this.Controls.Add(this.textBoxAge);
			this.Controls.Add(this.buttonDeleteEmployee);
			this.Controls.Add(this.buttonAddEmployee);
			this.Controls.Add(this.lblDepartment);
			this.Controls.Add(this.lblAge);
			this.Controls.Add(this.lblLastName);
			this.Controls.Add(this.lblFirstName);
			this.Controls.Add(this.comboBoxDepartment);
			this.Controls.Add(this.textBoxLastName);
			this.Controls.Add(this.textBoxFirstName);
			this.Controls.Add(this.dataGridViewEmployees);
			this.Name = "FormEmployee";
			this.Text = "Employees";
			this.Load += new System.EventHandler(this.FormEmployee_Load);
			((System.ComponentModel.ISupportInitialize)(this.dataGridViewEmployees)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.DataGridView dataGridViewEmployees;
		private System.Windows.Forms.TextBox textBoxFirstName;
		private System.Windows.Forms.TextBox textBoxLastName;
		private System.Windows.Forms.ComboBox comboBoxDepartment;
		private System.Windows.Forms.Label lblFirstName;
		private System.Windows.Forms.Label lblLastName;
		private System.Windows.Forms.Label lblAge;
		private System.Windows.Forms.Label lblDepartment;
		private System.Windows.Forms.Button buttonAddEmployee;
		private System.Windows.Forms.Button buttonDeleteEmployee;
		private System.Windows.Forms.TextBox textBoxAge;
		private System.Windows.Forms.Label labelInfo;
	}
}

