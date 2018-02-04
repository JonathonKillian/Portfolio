using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.IO;

namespace PROG210LastHW
{
	public static class SQL
	{
		const string AZURE_CONNECT = @"";
		const string DB_CONNECT = @"";

		public static List<Product> GetProducts()
		{
			const string QUERY = "SELECT * FROM Product";
			List<Product> products = new List<Product>();

			// Product table is stored in an Azure SQL database
			SqlConnection connection = new SqlConnection(AZURE_CONNECT);
			SqlCommand selectCommand = new SqlCommand(QUERY, connection);
			SqlDataReader reader = null;

			try
			{
				connection.Open();
				reader = selectCommand.ExecuteReader();

				while (reader.Read())
				{
					Product product = new Product();

					product.ProductID      = (int)reader["ProductID"];
					product.ProductName    = reader["ProductName"].ToString();
					product.Price          = (decimal)reader["Price"];
					product.QuantityOnHand = (int)reader["QuantityOnHand"];
					products.Add(product);
				}
			} finally {
				reader.Close();
				connection.Close();
			}

			return products;
		}

		public static List<Account> GetAccounts()
		{
			const string QUERY = "SELECT * FROM CustBankBalance";
			List<Account> accounts = new List<Account>();

			// Customer account table is stored on local SQL Server
			SqlConnection connection = new SqlConnection(DB_CONNECT);
			SqlCommand selectCommand = new SqlCommand(QUERY, connection);
			SqlDataReader reader = null;

			try
			{
				connection.Open();
				reader = selectCommand.ExecuteReader();

				while (reader.Read())
				{
					Account account = new Account();

					account.CustomerID = (int)reader["CustomerID"];
					account.FirstName  = reader["FirstName"].ToString();
					account.LastName   = reader["LastName"].ToString();
					account.Balance    = (decimal)reader["Balance"];
					accounts.Add(account);
				}
			} finally {
				reader.Close();
				connection.Close();
			}

			return accounts;
		}

		public static string Buy(Product product, Account account)
		{
			const int SUCCESSFUL_UPDATE = 1;
			const string AZURE_QUERY =
				"UPDATE Product SET QuantityOnHand = QuantityOnHand - 1 " +
				"WHERE ProductID = @ProductID AND QuantityOnHand > 0";
			const string DB_QUERY =
				"UPDATE CustBankBalance SET Balance = Balance - @Price " +
				"WHERE CustomerID = @CustomerID AND Balance >= @Price";

			StringWriter report = new StringWriter();
			// First part of the return string can be completed beforehand
			report.Write("{0} {1}'s purchase of {2} for {3:C} ",
				account.FirstName, account.LastName,
				product.ProductName, product.Price);

			SqlTransaction dbTransaction = null;

			// Prepare the SQL command for the Azure DB
			SqlConnection azureConnection = new SqlConnection(AZURE_CONNECT);
			SqlCommand    azureCommand    = new SqlCommand(AZURE_QUERY, azureConnection);
			azureCommand.Parameters.Add("@ProductID", SqlDbType.Int).Value = product.ProductID;

			// Prepar the SQL command for the Sql Server DB
			SqlConnection dbConnection    = new SqlConnection(DB_CONNECT);
			SqlCommand    dbCommand       = new SqlCommand(DB_QUERY, dbConnection);
			dbCommand.Parameters.Add("@CustomerID", SqlDbType.Int).Value = account.CustomerID;
			dbCommand.Parameters.Add("@Price", SqlDbType.Money).Value = product.Price;

			try
			{
				// Open connection and begin a transaction on it
				dbConnection.Open();
				dbTransaction = dbConnection.BeginTransaction();
				dbCommand.Transaction = dbTransaction;

				if (dbCommand.ExecuteNonQuery() == SUCCESSFUL_UPDATE)
				{
					// Inner try..finally is just to make sure connection to
					// Azure
					try
					{
						// Note: Azure doesn't allow distributed transactions
						// so no transaction binding here

						// Successfully modified the customer's balance, now
						// see if the product can still be "purchased"
						azureConnection.Open();
						if (azureCommand.ExecuteNonQuery() == SUCCESSFUL_UPDATE)
						{
							dbTransaction.Commit();
							report.WriteLine("completed successfully");
						} else {
							dbTransaction.Rollback();
							report.WriteLine("failed; not enough quantity on hand");
						}
					}
					// Catch exceptions in the outer try
					finally {
						azureConnection.Close();
					}
				} else {
					dbTransaction.Rollback();
					report.WriteLine("failed; not enough funds available.");
				}
			}
			catch (SqlException err)
			{
				if (dbTransaction != null) {
					dbTransaction.Rollback();
				}
				report.WriteLine("failed; SqlException occurred, \"{0}\"",
					err.Message);
			}
			finally {
				dbConnection.Close();
			}

			return report.ToString();
		}
	}
}
