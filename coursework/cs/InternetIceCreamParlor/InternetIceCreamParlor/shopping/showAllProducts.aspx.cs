using System;
using App_Code;
using System.Data.SqlClient;
using System.Web.UI.WebControls;
using System.Web.UI.HtmlControls;

namespace InternetIceCreamParlor.shopping {
	public partial class showAllProducts:System.Web.UI.Page {
		protected void Page_Load(object sender,EventArgs e) {
			// Verify a user is logged in
			if (Session["userID"] == null) {
				// Passing status to main page via GET to let it handle
				// the no logged in user situation.
				Response.Redirect("~/index.aspx?status=nologin");
			} else {
				//System.Diagnostics.Debug.WriteLine("######### id: " + Session["userID"].ToString());

				// Retrieve user's name
				string user = Session["fName"].ToString();

				// Greet user
				lblGreet.Text = user + ", here are our current products:";

				DBMaster dbm = new DBMaster();

				// Create Query
				string query = 
					"SELECT pid, productName, description, price " +
					"FROM products WHERE currentAmount > 0 ORDER BY productName ASC";
				//System.Diagnostics.Debug.WriteLine("######### query: " + query);

				// Open connection and execute Query.
				SqlDataReader reader = dbm.GetReader(query);

				// Display the found products
				while (reader.Read()) {
					double price2      = 0.0;
					// Get the current record
					string pid         = reader["pid"].ToString();
					string product     = reader["productName"].ToString();
					string description = reader["description"].ToString();
					string price       = reader["price"].ToString();
					HtmlAnchor link    = new HtmlAnchor();

					// Create the link control.
					link.HRef      = "oneclickBuy.aspx?id=" + pid;
					// Since I'm selling ice cream, humorously saying lick to buy.
					link.InnerText = "Single Lick Buy\x2122";

					// Let's see if I can successfully format the price as 00.00
					if (double.TryParse(price, out price2)) {
						price = string.Format("{0:C}",price2);
					} else {
						// The chances of this executing are slim to none since
						// price is in the database as a number.
						price = "$" + price;
					}

					// Create a Table Row and cells
					TableRow  trRow         = new TableRow();
					TableCell tcProduct     = new TableCell();
					TableCell tcDescription = new TableCell();
					TableCell tcPrice       = new TableCell();
					TableCell tcBuy         = new TableCell();

					// Populate the row cells
					tcProduct.Text          = product;
					tcDescription.Text      = description;
					tcPrice.Text            = price;
					tcBuy.Controls.Add(link);

					// Add the cells to the Row
					trRow.Cells.Add(tcProduct);
					trRow.Cells.Add(tcDescription);
					trRow.Cells.Add(tcPrice);
					trRow.Cells.Add(tcBuy);

					// And add the row to the table
					tblProducts.Rows.Add(trRow);
				}

				// Close the connection.
				dbm.CloseConnection();
			}
		}
	}
}