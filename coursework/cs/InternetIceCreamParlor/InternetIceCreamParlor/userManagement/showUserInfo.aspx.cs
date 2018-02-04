using System;
using System.Data.SqlClient;
using App_Code;

namespace InternetIceCreamParlor {
	public partial class showUserInfo:System.Web.UI.Page {
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
				lblFName.Text    = reader["firstName"].ToString();
				lblLName.Text    = reader["lastName"].ToString();
				lblUser.Text     = reader["userName"].ToString();
				lblPassword.Text = reader["password"].ToString();
				lblAddress.Text  = reader["address"].ToString();
				lblEmail.Text    = reader["email"].ToString();
				lblPhone.Text    = reader["phone"].ToString();
				dbm.CloseConnection();					// Close the connection
			}
		}
	}
}