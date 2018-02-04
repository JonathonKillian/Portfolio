using App_Code;
using System;

namespace InternetIceCreamParlor.productManagement
{
	public partial class newProduct:System.Web.UI.Page
	{
		protected void Page_Load(object sender,EventArgs e)
		{
			// Verify a user is logged in
			if (Session["userID"] == null)
			{
				// Passing status to main page via GET to let it handle
				// the no logged in user situation.
				Response.Redirect("~/index.aspx?status=nologin");
			}
			else
			{
				//System.Diagnostics.Debug.WriteLine("######### id: " + Session["userID"].ToString());

				// Retrieve user's name
				string user = Session["fName"].ToString();

				// Greet user
				lblGreet.Text = string.Format("{0}, Please enter a new product:", user);
			}
		}

		protected void btnProduct_Click(object sender, EventArgs e)
		{
			// Collect the inforation
			string product = txtProduct.Text;
			string description = txtDescription.Text;
			string price = txtPrice.Text;
			string amount = txtAmount.Text;

			// Save it to the database
			DBMaster dbm = new DBMaster();

			// Craft the query
			string query = string.Format("INSERT INTO products (productName, description, price, currentAmount) " +
				"VALUES('{0}', '{1}', '{2}', '{3}')",
				product, description, price, amount);

			// Execute the query
			string id = dbm.ExecuteWithScope(query);
			//System.Diagnostics.Debug.WriteLine("######### query: " + query);
			//System.Diagnostics.Debug.WriteLine("######### id: " + id);
			
			// Close the connection.
			dbm.CloseConnection();

			// Clear the fields to allow another entry.
			txtProduct.Text = "";
			txtDescription.Text = "";
			txtPrice.Text = "";
			txtAmount.Text = "";
		}
	}
}