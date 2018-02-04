using System.Configuration;
using System.Data.SqlClient;

namespace App_Code {
	public class DBMaster {
		private SqlConnection conn;
		private string connStr = null;
		SqlDataReader reader = null;
		
		// Default constructor; reads the connection string from appSettings in Web.config
		public DBMaster() {
			connStr = ConfigurationManager.AppSettings["connectionString"];
			//System.Diagnostics.Debug.WriteLine("######### DBMaster(): connStr: " + connStr);
		}

		// Allow overriding the appSettings connection string.
		// Previous version: Allowed setting the server portion of string.
		public DBMaster(string connection) {
			connStr = connection;
			//System.Diagnostics.Debug.WriteLine("######### DBMaster(" + connection + "): connStr: " + connStr);
		}

		// 1. Create and open a connection.
		public SqlConnection GetConnection() {
			if (conn == null || conn.State == System.Data.ConnectionState.Closed) {
				// Connect to DB (Not safe! user name and password sent in plain text)
				conn = new SqlConnection(connStr);
				conn.Open();
			}

			return conn;
		}

		// 2. Create query
		public SqlCommand getCommand(string query) {
			// Create Query (Also not safe! plain text query can lead to SQL Injection)
			SqlCommand cmd = new SqlCommand(query);
			cmd.CommandType = System.Data.CommandType.Text;
			cmd.Connection = GetConnection();

			return cmd;
		}

		// 3. Execute query (multiple functions)

		// 3.1. Execute query that returns a set
		public SqlDataReader GetReader(string query) {
			// Create Query (Also not safe! plain text query can lead to SQL Injection)
			SqlCommand cmd = getCommand(query);

			CloseReader();						// Make sure reader is closed.
			reader = cmd.ExecuteReader();

			return reader;
		}

		// 3.2 Execute query that doesn't return a set
		public void ExecuteNonQuery(string query) {
			SqlCommand cmd = getCommand(query);

			cmd.ExecuteNonQuery();
		}

		// 3.3 Execute query that returns a set of 1, ergo a scalar
		// Up to the calling method to cast the scalar.
		public object ExecuteScalar(string query) {
			// Create Query (Also not safe! plain text query can lead to SQL Injection)
			SqlCommand cmd = getCommand(query);

			object scalar = cmd.ExecuteScalar();

			return scalar;
		}

		// 3.4 Execute queries and return new record id.
		// This method appends a select query to get back the new id from an
		// insert query.
		public string ExecuteWithScope(string query) {
			const string SCOPEID = ";SELECT SCOPE_IDENTITY()";
			string id = "";
			
			id = ExecuteScalar(query + SCOPEID).ToString();
			//System.Diagnostics.Debug.WriteLine("######### ScopeId: ID returned: " + id);

			return id;
		}

		// 4. Close connection.
		public void CloseConnection() {
			if (conn != null && conn.State == System.Data.ConnectionState.Open) {
				conn.Close();
			}
		}

		public void CloseReader() {
			if (reader != null) {
				reader.Close();
			}
		}
	}
}