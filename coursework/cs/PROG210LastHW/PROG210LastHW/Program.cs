using System;
using System.Windows.Forms;

namespace PROG210LastHW
{
	static class Program
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main()
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			//Application.SetUnhandledExceptionMode(UnhandledExceptionMode.CatchException);
			Application.ThreadException += Application_ThreadException;
			Application.Run(new Form1());
		}

		static void Application_ThreadException(object sender, System.Threading.ThreadExceptionEventArgs e) {
			MessageBox.Show(e.Exception.Message, "Application Exception caught");
		}
	}
}
