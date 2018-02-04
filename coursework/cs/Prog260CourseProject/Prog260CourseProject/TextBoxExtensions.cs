using System.Windows.Forms;

namespace Prog260CourseProject {
	public static class TextBoxExtensions {
		// Thought I'd try out an extension, since I had repeated these commands
		// in multiple methods in the main form. It extends the TextBox control
		// object so one can use textBox1.HighlightFocus()
		public static void HighlightFocus(this TextBox textBox) {
			textBox.Focus();
			textBox.SelectAll();
		}
	}
}
