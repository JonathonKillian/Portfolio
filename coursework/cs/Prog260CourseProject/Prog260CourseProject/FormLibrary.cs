using System;
using System.Drawing;
using System.Windows.Forms;
using BinarySearchTree;
using BookLibrary;

namespace Prog260CourseProject {
	public partial class FormLibrary : Form {
		const string DEFAULT_STATUS = "Please supply an ISBN to add, find or remove a book";

		BST<Book> books = new BST<Book>();

		public FormLibrary() {
			InitializeComponent();
		}

		// Clear all the text boxes
		private void ClearBoxes() {
			textBoxISBN.Text    = "";
			textBoxTitle.Text   = "";
			textBoxAuthor.Text  = "";
			textBoxRating.Text  = "";
			textBoxPubYear.Text = "";
		}

		// Called by a few methods to enable or disable the button that fills
		// the listbox
		private void ToggleGetAllISBNButton() {
			if (books.HasEntries) {
				buttonGetAllISBN.Enabled = true;
			} else {
				listBoxISBN.DataSource = null;	// Clear the listbox
				buttonGetAllISBN.Enabled = false;
				UpdateStatus(DEFAULT_STATUS);
			}
		}

		private int GetISBN() {
			return int.Parse(textBoxISBN.Text);
		}

		private Book GetBoxes() {
			Book book = new Book();

			book.Title   = textBoxTitle.Text;
			book.Author  = textBoxAuthor.Text;
			book.Rating  = textBoxRating.Text[0];	// Rating is just a char
			book.PubYear = int.Parse(textBoxPubYear.Text);

			return book;
		}

		// This method assumes the textboxes have been validated.
		private void FillBoxes(Book book) {
			textBoxTitle.Text   = book.Title;
			textBoxAuthor.Text  = book.Author;
			textBoxRating.Text  = book.Rating.ToString();
			textBoxPubYear.Text = book.PubYear.ToString();
		}

		private void UpdateStatus(string status) {
			labelStatus.ForeColor = DefaultForeColor;
			labelStatus.Text = status;
		}

		// Can be used like Console.WriteLine, i.e., initial string has
		// embedded {} that are replaced by the variable objects following
		private void UpdateStatus(string status, params object[] braceObjects) {
			if (braceObjects.Length > 0) {
				status = string.Format(status, braceObjects);
			}
			UpdateStatus(status);
		}

		private void UpdateErrorStatus(string status) {
			labelStatus.ForeColor = Color.Red;
			labelStatus.Text = status;
		}

		// Can be used like Console.WriteLine, i.e., initial string has
		// embedded {} that are replaced by the variable objects following
		private void UpdateErrorStatus(string status, params object[] braceObjects) {
			status = string.Format(status, braceObjects);
			UpdateErrorStatus(status);
		}

		private void RefreshISBNs() {
			listBoxISBN.DataSource = books.Keys;
			// ClearBoxes is second as setting the DataSource triggers the
			// SelectionChanged event, filling the boxes with the first found
			// book.
			ClearBoxes();
			listBoxISBN.ClearSelected();
			ToggleGetAllISBNButton();		// In case the BST is empty
		}

		private void FormLibrary_Load(object sender,EventArgs e) {
			// Nothing in the boxes, so prevent button clicks
			buttonAddBook.Enabled    = false;
			buttonFindBook.Enabled   = false;
			buttonRemoveBook.Enabled = false;
			ToggleGetAllISBNButton();

			// Show an initial request in the status, and also permit showing
			// ampersands (instead of Alt-letter shortcuts)
			UpdateStatus(DEFAULT_STATUS);
			labelStatus.UseMnemonic = false;
			listBoxISBN.DataSource = null;
		}

		// Validate the textboxes. If validated, enable the respected buttons.
		private void ValidateBoxes(object sender, EventArgs e) {
			bool isbnValid = ValidateBook.ISBN(textBoxISBN.Text);

			buttonAddBook.Enabled    = isbnValid
				&& ValidateBook.Title(textBoxTitle.Text)
				&& ValidateBook.Author(textBoxAuthor.Text)
				&& ValidateBook.Rating(textBoxRating.Text)
				&& ValidateBook.PubYear(textBoxPubYear.Text);

			// buttonGetAllISBN is enabled by Adding a book and disabled by
			// removing all books from the BST.
			buttonFindBook.Enabled   = isbnValid & books.HasEntries;
			buttonRemoveBook.Enabled = isbnValid & books.HasEntries;
		}

		private void buttonAddBook_Click(object sender,EventArgs e) {
			int isbn = GetISBN();
			// Create a book with the values from the textboxes
			Book book = GetBoxes();

			// Add the book
			try {
				books.Add(isbn, book);
				// Now clear the fields, update the status and set up for next action
				ClearBoxes();
				UpdateStatus("\"{0}\" with ISBN {1} added successfully",
					book.Title, isbn);
				ToggleGetAllISBNButton();		// Enable the button
			} catch (ArgumentException) {
				// Only current exception thrown by BST.Add is duplicate key
				UpdateErrorStatus("Unable to use ISBN {0}; it already exists.", isbn);
			}
			textBoxISBN.HighlightFocus();
		}

		private void buttonFindBook_Click(object sender,EventArgs e) {
			int isbn = GetISBN();
			Book book;

			try {
				book = books.Find(isbn);
				// Book found, fill in the details
				FillBoxes(book);
				UpdateStatus("ISBN {0}, \"{1},\" found", isbn, book.Title);
			} catch (ArgumentException) {
				// Possible exceptions are no tree (which shouldn't trigger do
				// to validation code) or no entry found with the key.

				// Clear the boxes, focus on ISBN with invalid entry
				// selected to allow User to edit or re-type
				ClearBoxes();
				UpdateErrorStatus("Unable to find ISBN {0}", isbn);
			}
			// Regardless of success, land the cursor back in the ISBN text box
			textBoxISBN.HighlightFocus();
		}

		private void buttonRemoveBook_Click(object sender,EventArgs e) {
			int isbn = GetISBN();
			Book book;

			// Get the book for status info; also will tell if the book is able
			// to be removed
			try {
				book = books.Remove(isbn);
				// If it can be found, it can be removed
				UpdateStatus("ISBN {0}, \"{1}\" removed", isbn, book.Title);
			} catch (ArgumentException) {
				// Ruh, roh, Raggy, ro rook ;) Current exceptions are no tree,
				// which shouldn't trigger do to the validation code, and not
				// found.

				UpdateErrorStatus("Unable to find and remove ISBN {0}",	isbn);
			}
			ToggleGetAllISBNButton();	// If BST empty, disable the button
			// Clear all the textboxes and set focus on ISBN
			ClearBoxes();				// Clear all textboxes
			textBoxISBN.Focus();
		}

		// Another level of validation. No point in moving to the "Book fields"
		// if there is no ISBN
		private void BookFields_Enter(object sender, EventArgs e) {
			if (ValidateBook.ISBN(textBoxISBN.Text)) {
				UpdateStatus("Please fill in a Title, Author, Rating & year published");
			} else {
				textBoxISBN.HighlightFocus();
				UpdateErrorStatus("Please supply a postive non-zero whole number ISBN first");
			}
		}

		private void buttonGetAllISBN_Click(object sender,EventArgs e) {
			RefreshISBNs();
			UpdateStatus(DEFAULT_STATUS);
		}

		private void listBoxISBN_SelectedIndexChanged(object sender,EventArgs e) {
			const int INVALID_SELECTION = -1;

			// Only time it is -1 is when the DataSource is set to null, thus
			// it does not qualify as an error to except. Instead, ignore the click
			if (listBoxISBN.SelectedIndex != INVALID_SELECTION) {
				int isbn = (int)listBoxISBN.SelectedValue;
				Book book;

				try {
					book = books.Find(isbn);
					FillBoxes(book);
					// Need to override the ISBN, since this time, it was not
					// User-entered.
					textBoxISBN.Text = isbn.ToString();
					listBoxISBN.ClearSelected();
					UpdateStatus(DEFAULT_STATUS);
				} catch (ArgumentException) {
					// No sense leaving the invalid ISBN in the list.

					// Only if the key is not found does this exception trigger
					// as an empty tree, a blank listbox, is not an error
					// condition (i.e., User can click on the empty listbox to
					// their hearts content)
					RefreshISBNs();
					UpdateErrorStatus("Book with ISBN {0} not found. List refreshed", isbn);
				}
			}

			// Most of the action results from modifying the ISBN text box, so
			// move cursor to it.
			textBoxISBN.HighlightFocus();
		}

		// If User clicks empty listbox, send cursor back to ISBN text box
		private void listBoxISBN_Enter(object sender,EventArgs e) {
			if (listBoxISBN.DataSource == null) {
				textBoxISBN.HighlightFocus();
			}
		}
	}
}
