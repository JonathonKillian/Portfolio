using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace PROG210LastHW
{
	public partial class Form1:Form
	{
		public Form1()
		{
			InitializeComponent();

			// The grids are just for selecting, so disallow edits and single
			// cell selections.
			dataGridViewProduct.MultiSelect           = false;
			dataGridViewProduct.ReadOnly              = true;
			dataGridViewProduct.SelectionMode         = DataGridViewSelectionMode.FullRowSelect;

			dataGridViewAccount.MultiSelect           = false;
			dataGridViewAccount.ReadOnly              = true;
			dataGridViewAccount.SelectionMode         = DataGridViewSelectionMode.FullRowSelect;

			// Status line shows this only until first purchase
			labelStatus.Text                          = "No purchases yet";
		}

		private void refreshGrid()
		{
			List<Product> products = SQL.GetProducts();
			List<Account> accounts = SQL.GetAccounts();

			dataGridViewProduct.DataSource = products;
			dataGridViewAccount.DataSource = accounts;
			// Part of the validation is forcing the User to explicitly make
			// selections
			dataGridViewProduct.ClearSelection();
			dataGridViewAccount.ClearSelection();
			buttonBuy.Enabled = false;
		}

		// For testing purposes, double clicking the grids or form background
		// will also trigger this event
		private void Form1_Load(object sender,EventArgs e)
		{
			refreshGrid();
		}

		// This event can only trigger if User selected a customer and a product
		// which enables the button that triggers this event
		private void buttonBuy_Click(object sender,EventArgs e)
		{
			// Only interested in the cell values
			DataGridViewCellCollection productRow = dataGridViewProduct.CurrentRow.Cells;
			DataGridViewCellCollection accountRow = dataGridViewAccount.CurrentRow.Cells;
			Product product = new Product();
			Account account = new Account();
			bool canBuy = true;

			// Load the objects for easier access
			product.ProductID      = (int)productRow["ProductID"].Value;
			product.ProductName    = productRow["ProductName"].Value.ToString();
			product.Price          = (decimal)productRow["Price"].Value;
			product.QuantityOnHand = (int)productRow["QuantityOnHand"].Value;
			account.CustomerID     = (int)accountRow["CustomerID"].Value;
			account.FirstName      = accountRow["FirstName"].Value.ToString();
			account.LastName       = accountRow["LastName"].Value.ToString();
			account.Balance        = (decimal)accountRow["Balance"].Value;

			// First validate against known data
			labelStatus.Text = "";
			if (account.Balance < product.Price) {
				labelStatus.Text += string.Format(
					"{0} {1}'s balance is not sufficient to purchase {2} for {3:C}\n",
					account.FirstName, account.LastName,
					product.ProductName, product.Price);
				canBuy = false;
			}
			if (product.QuantityOnHand == 0)
			{
				labelStatus.Text += string.Format(
					"{0} is currently out of stock; unable to proceed with purchase\n",
					product.ProductName);
				canBuy = false;
			}
			// If validation checks pass, we can send the purchase to the databases
			if (canBuy)
			{
				labelStatus.Text += "Attempting to validate purchase; please hold..\n";
				labelStatus.Text += SQL.Buy(product, account);
			}

			// Regardless of status of purchase, refresh the grid to update
			// numbers
			refreshGrid();
		}

		private void setBuyButton(object sender, EventArgs e)
		{
			// Only allow the button to be enabled if each DataGridView has a
			// row selected
			buttonBuy.Enabled = (dataGridViewProduct.SelectedRows.Count > 0) &&
								(dataGridViewAccount.SelectedRows.Count > 0);
		}
	}
}
