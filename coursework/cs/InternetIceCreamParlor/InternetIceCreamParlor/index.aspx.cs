using App_Code;
using System;
using System.Configuration;
using System.Data.SqlClient;

namespace InternetIceCreamParlor {
	public partial class index:System.Web.UI.Page {
		protected void Page_Load(object sender,EventArgs e) {
			string status = Request.QueryString["status"];

			// This will not reprocess the status when clicking login.
			if (!IsPostBack) {
				switch (status) {
				case "nologin":
					// The pages that need a logged in user return this status.
					// Wanted to show User they need to log in instead of just
					// re-showing default screen.
					lblGreet.Text = "Unable to proceed without a login.";
					txtUser.Focus();
					break;
				case "logout":
					// If a user clicks to log out on another page, the page returns this status.
					// Going this route saves from having to move asp:form to top
					// of body on the other pages.
					LogOut();
					break;
				default:
					// If user is still logged in, acknowledge and hide login
					if (Session["userID"] != null) {
						// When coming from user management, the name may have been lost.
						if (Session["fName"] != null) {
							string fName = Session["fName"].ToString();

							lblGreet.Text = string.Format("{0}, what would you like to do? Click a link to the side.", fName);
							// Toggle login box and logout button
							ShowLogin(false);
						} else {
							// Pass true to LogOut to not show logging out confirmation.
							LogOut(true);
						}
					}
					break;
				}
			}
		}

		protected void btnLogin_Click(object sender, EventArgs e) {
			// Get login info
			string user = txtUser.Text;
			string password = txtPassword.Text;

			// Create query
			string query = string.Format(
				"SELECT firstName, id FROM person WHERE userName = '{0}' AND password = '{1}'",
				user, password);
			//System.Diagnostics.Debug.WriteLine("######### query: " + query);

			// Open connection and execute query
			DBMaster dbm = new DBMaster();
			SqlDataReader reader = dbm.GetReader(query);

			// If login is successful, reader will have data
			if (reader.Read()) {
				// Save user's name & id
				string fName = reader["firstName"].ToString();
				string id = reader["id"].ToString();

				// Save session info
				Session["fName"] = fName;
				Session["userID"] = id;

				// Greet user
				lblGreet.Text = string.Format("Welcome {0}!",fName);

				// Toggle login box and logout button
				ShowLogin(false);
			} else {
				// Display error message
				lblGreet.Text = "Sorry, the provided information did not match any of our records.";
			}

			// Close the connection
			dbm.CloseConnection();
		}

		// There are multiple places that adjust the status of the login box.
		protected void ShowLogin(bool login) {
			fstBox.Visible = login;
			btnLogout.Visible = !login;
		}

		// Only on the Main page is the log out a (link) button.
		// The other pages uses a redirect with GET
		protected void btnLogout_Click(object sender, EventArgs e) {
			LogOut();
		}

		// Both the Logout button and the page_load call for logout.
		// There is one case where the ID but not the name is known.
		// The parameter takes care of that one case.
		protected void LogOut(bool suppressMessage = false) {
			if (Session["userID"] != null) {
				if (!suppressMessage) {
					string fName = Session["fName"].ToString();

					// Acknowledge log out.
					lblGreet.Text = string.Format("Thank you for visiting, {0}. Please come back again.", fName);
				}

				// Clear the login info
				Session.Remove("userID");
				Session.Remove("fName");
			}

			// Hide the logout button and clear out username for security
			txtUser.Text = "";
			ShowLogin(true);
		}
	}
}