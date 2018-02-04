using System;
using App_Code;

namespace InternetIceCreamParlor {
	public partial class confirmNewUser:System.Web.UI.Page {
		protected void Page_Load(object sender,EventArgs e) {
			if (!IsPostBack) {
				// Retrieve the info from page 1
				string fName     = Request.Form["txtFName"];
				string lName     = Request.Form["txtLName"];
				string user      = Request.Form["txtUser"];
				string password  = Request.Form["txtPassword"];
				string address   = Request.Form["txtAddress"];
				string email     = Request.Form["txtEmail"];
				string phone     = Request.Form["txtPhone"];

				// Show it to the user
				lblFName.Text    = fName;
				lblLName.Text    = lName;
				lblUser.Text     = user;
				lblPassword.Text = password;
				lblAddress.Text  = address;
				lblEmail.Text    = email;
				lblPhone.Text    = phone;

				// Save it to the database
				DBMaster dbm = new DBMaster();
				// Craft the query
				string values = string.Format("VALUES('{0}', '{1}', '{2}', '{3}', '{4}', '{5}', '{6}')",
					fName, lName, user, password, address, email, phone);
				string query = "INSERT INTO person (firstName, lastName, userName, password, address, email, phone) " +
					values;

				// Open a connection & execute the queries
				string id = dbm.ExecuteWithScope(query);

				// Save the user's ID for other pages.
				Session["userID"] = id;
				// Save the user's name as well, since the main index page responds to userID.
				Session["fName"] = fName;
				//System.Diagnostics.Debug.WriteLine("######### query: " + query);
				//System.Diagnostics.Debug.WriteLine("######### id: " + id.ToString());

				// Finally, close the connection.
				dbm.CloseConnection();
			}
		}
	}
}