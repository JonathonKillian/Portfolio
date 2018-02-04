using System;
using App_Code;
using System.Data.SqlClient;
using System.Net;
using System.Net.Mail;

namespace InternetIceCreamParlor.shopping  {
	public partial class oneclickBuy:System.Web.UI.Page {
		protected void Page_Load(object sender,EventArgs e) {
			// Verify a user is logged in
			if (Session["userID"] == null) {
				// Passing status to main page via GET to let it handle the no
				// logged-in user situation.
				Response.Redirect("~/index.aspx?status=nologin");
			} else {
				const string BUSINESS = "Ice Cream Internet Parlor";

				DBMaster dbm = new DBMaster();
				SqlDataReader reader = null;
				string query = "";
				string product = "";
				string price = "";
				string address = "";
				string email = "";
				string id = Session["UserID"].ToString();
				// Retrieve user's name from Session
				string fName = Session["fName"].ToString();
				string lName = "";
				// Get id from URL
				string pid = Request.QueryString["id"];
				string message = "Hi! " + fName;
				double price2 = 0.0;

				// First, get product name & price
				query = "SELECT productName, price FROM products WHERE pid = " + pid;

				// Execute the query
				reader = dbm.GetReader(query);

				if (reader.Read()) {
					product = reader["productName"].ToString();
					price   = reader["price"].ToString();

					// Make Price look like a proper price (2 significant digits)
					if (double.TryParse(price, out price2)) {
						price = string.Format("{0:C}",price2);
					} else {
						// The chances of this executing are slim to none since
						// price is in the database as a number.
						price = "$" + price;
					}
				}
				dbm.CloseReader();		// Done with the reader, for now.

				// Second, decrement the amount
				query = "UPDATE products SET currentAmount -= 1 WHERE pid = " + pid;
				dbm.ExecuteNonQuery(query);

				// Third, get user's address.
				query = "SELECT * FROM person WHERE id = " + id;

				// Get the needed info from the person table.
				reader = dbm.GetReader(query);
				if (reader.Read()) {
					address = reader["address"].ToString();
					email   = reader["email"].ToString();
					lName   = reader["lastName"].ToString();
				}

				// We have all the pieces we need from the database.
				dbm.CloseReader();
				dbm.CloseConnection();

				// Build up the message; the Greeting line is already added.
				message += string.Format(
					"<p>Thank you for purchasing <b>{0}</b>. " +
					"Your credit card on file will be charged <b>{1}</b><br/>" +
					"Your purchase will be shipped to: <b>{2}</b></p>" +
					"<p>Thanks for shopping at {3}! " +
					"It is a pleasure doing business with you.</p>",
					product, price, address, BUSINESS);
				divGreet.InnerHtml = message;

				/* No point in running the rest of the code if there is no from email and
				   password - JK
				// Get sender credentials
				string fromEmail    = "";
				string fromPassword = "";

				// Combine first and last names into one string
				string toName = string.Format("{0} {1}", fName, lName);

				// Create a MailMessage object
				MailAddress from = new MailAddress(fromEmail, BUSINESS);
				MailAddress to   = new MailAddress(email, toName);
				MailMessage mail = new MailMessage(from, to);

				// Build the email
				mail.Subject = "Your order from " + BUSINESS;
				mail.Body = message;
				// And tell message we're using HTML
				mail.IsBodyHtml = true;

				// Set SMTP for gmail
				SmtpClient smtp = new SmtpClient("smtp.gmail.com", 587);

				// Provide the credentials
				smtp.Credentials = new NetworkCredential(fromEmail, fromPassword);
				smtp.EnableSsl = true;

				// Send the email
				smtp.Send(mail);
				*/
			}
		}
	}
}