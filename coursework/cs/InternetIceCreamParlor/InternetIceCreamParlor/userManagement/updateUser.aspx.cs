using System;
using System.Data.SqlClient;
using App_Code;

namespace InternetIceCreamParlor {
	public partial class updateUser:System.Web.UI.Page {
		protected void Page_Load(object sender,EventArgs e) {
			if (!IsPostBack) {
				// Retrieve the user's id.
				string id = Session["userId"].ToString();

				// Create the query
				string query = "SELECT * FROM person WHERE id = " + id;

				// Open a connection and execute the query.
				DBMaster dbm = new DBMaster();
				SqlDataReader reader = dbm.GetReader(query);

				// Read in the information
				reader.Read();
				txtFName.Text    = reader["firstName"].ToString();
				txtLName.Text    = reader["lastName"].ToString();
				txtUser.Text     = reader["userName"].ToString();
				txtPassword.Text = reader["password"].ToString();
				txtAddress.Text  = reader["address"].ToString();
				txtEmail.Text    = reader["email"].ToString();
				txtPhone.Text    = reader["phone"].ToString();

				// Close the connection; no longer needed in this method
				dbm.CloseConnection();
			}
		}

		protected void btnUpdate_Click(object sender, EventArgs e) {
			// Retrieve the "updated" info.
			string id       = Session["userId"].ToString();
			string fName    = txtFName.Text;
			string lName    = txtLName.Text;
			string user     = txtUser.Text;
			string password = txtPassword.Text;
			string address  = txtAddress.Text;
			string email    = txtEmail.Text;
			string phone    = txtPhone.Text;

			// Craft the query (Shouldn't send in plain text!)
			string query    = string.Format(
				"UPDATE person " +
				"SET firstName = '{0}', lastName = '{1}', userName = '{2}', " +
				"password = '{3}', address = '{4}', email = '{5}', phone = '{6}' " +
				"WHERE id = {7}",
				fName, lName, user, password, address, email, phone, id);

			DBMaster dbm = new DBMaster();				// Open a connection
			dbm.ExecuteNonQuery(query);					// Execute the query
			dbm.CloseConnection();						// Close the connection

			// Move to next web page
			Response.Redirect("showUserInfo.aspx");
		}
	}
}