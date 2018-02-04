/******************************************************************************
* Course: PROG 110
* Instructor: S. Unwin
* Term: Fall 2015
*
* Solution/Project Name: Bookstore/Bookstore
* File Name: Bookstore.cs
*
* This file defines the entry point method for the Console application.
*
* Programmer: Jon Killian
* Assigned Homework Number: Homework 9 (HW9)
*
* Revision Date Release Comment
* -------- ---------- ------------------------------------------------------
* 1.0      09/28/2015 Initial Release (HW1)
* 2.0      10/05/2015 Adding ability to accept and save user input. (HW2)
* 3.0      10/13/2015 Adding current purchase to on screen sales slip (HW3)
* 4.0      10/20/2015 Adding validation logic and screen clears. (HW4)
* 5.0      12/01/2015 Moving "screens" to their own method. (HW9)
*
* Class Name & Purpose (Description)
* Bookstore
* ---------------
* Display the main menu, and display the various screens as selectable from
* the proffered choices for the business _Vulcan Values Bookstore_.
*
* The choices are to purchase a book, reserver a book, add/edit/delete a book
* or to exit the program. Each has their own "screen" separated by screen
* clearing. At this time, one can only purchase 1 title, and returning to the
* same screen wipes the slate clean. The same for reserving a book, there is
* no indication of a previous reservation. The add/edit/delete inventory screen
* is "under construction" so only shows a selection confirmation line.
*
* At this time, there is validation on the screens with input, but only the menu
* screen will reprompt; the purchase and reserve screens will continue on and
* not display the sale slip or reservation respectively.
*
******************************************************************************/
using System;

namespace KillianHW9
{
	class Bookstore
	{
		enum MenuChoices
		{
			PURCHASE = 1, RESERVE, ADD, EDIT, DELETE, EXIT
		}

		/*
		 * Method:  Main
		 * Purpose: Provides the entry point into the program, displays a
		 *          greeting, controls the main loop (calling out to other
		 *          methods), and finally displays a closing message.
		 *
		 * Input:   none
		 * Output:  none (void)
		 */
		static void Main()
		{
			const string DEVELOPER = "Jon Killian";
			const string PROMPT = "\nEnter your choice: ";
			const double INVALID_MIN = 0.00;

			string[] mainMenu = new string[] {
				"Purchase a book",
				"Reserve a book",
				"Add a book",
				"Edit a book",
				"Delete a book",
				"Exit"};
			string purchased = "";
			int userSelection = 0;
			double total = 0.00;

			// Display initial welcome message
			Console.Write("Welcome to our neck of the galaxy!");

			do
			{
				// Show the menu and prompt for choice
				userSelection = PromptMenu(mainMenu, PROMPT);

				// Clear the screen in prep to move to new screen.
				Console.Clear();

				// Call the correct method based upon User's choice.
				switch((MenuChoices) userSelection)
				{
					case MenuChoices.PURCHASE:
						total = PurchaseBook();

						// Show a mock menu with choice showing
						ShowMenu(mainMenu, PROMPT);
						Console.WriteLine("{0}\n\n", userSelection);

						// Build up the string
						if (total != INVALID_MIN)
						{
							purchased = 
								centerLLAP(
									"Thank you again for your purchase of " +
									"{0:C}") + "\n\n\n";
						}
						else
						{
							purchased = 
								centerLLAP(
									"We are sorry we were unable to " +
									"process you order   ") + "\n" +
								centerLLAP(
									"of {0:C}. Were you able to enter " + 
									"everything proper?") + "\n\n";
						}

						// Display the purchased message and await keypress
						Console.WriteLine(purchased, total);
						WaitAndClear();
						break;
					case MenuChoices.RESERVE:
						ReserveBook();
						break;
					case MenuChoices.ADD:
					case MenuChoices.EDIT:
					case MenuChoices.DELETE:
						// Menu choices of add, edit and delete go to the same
						// screen. It will properly process the choice.
						Inventory(mainMenu[userSelection-1]);
						break;
					case MenuChoices.EXIT:
						ExitShop();
						break;
					default:
						// As the PromptMenu() handles validation, execution
						// should not reach this point.
						// I leave it as a sanity check.
						Console.WriteLine(
							"Unknown menu choice. Unable to process.");
						WaitAndClear();
						break;
				}
			} while (userSelection != (int) MenuChoices.EXIT);

			// Show program close and await key press
			Console.WriteLine(
				"\n\n\n\nThe program is reporting, \"all stop.\" " +
				"Press a key to close this window.\n" +
				"Thanks, -- " + DEVELOPER);
			Console.ReadKey();
		}

		/*
		 * Method:  ShowMenu
		 * Purpose: Shows the screen header and main menu.
		 *          Separated out here as called from 2 places
		 *
		 *          a prompt is passed in due to displaying a mock menu
		 *          after the PurchaseBook() method returns.
		 *
		 * Input:   menu (stringp[]), prompt (string)
		 * Output:  none (void)
		 */
		private static void ShowMenu(string[] menu, string prompt)
		{
			const int FIRST_CHOICE = 1;

			// Display screen/store header and screen title
			ShowHeader("Main Menu");

			for (int line = 0; line < menu.Length; ++line)
			{
				Console.WriteLine("{0}. {1}", line+FIRST_CHOICE, menu[line]);
			}

			// Display the first prompt.
			Console.Write(prompt);
		}

		/*
		 * Method:  PromptMenu
		 * Purpose: Shows menu, waits for User's response and validates
		 *          the choice. Assumes minimum valid choice is 1.
		 *
		 *          a prompt is passed in due to displaying a mock menu
		 *          after the PurchaseBook() method returns.
		 *
		 *          Which is also why the showing of the menu is split off.
		 *
		 * Input:   menu (string[]), prompt (string)
		 * Output:  choice (int)
		 */
		private static int PromptMenu(string[] menu, string prompt)
		{
			//const string PROMPT = "\nEnter your choice: ";
			const int MIN = 1;
			int choice = 0;
			int max = menu.Length;

			// Display screen header and menu
			ShowMenu(menu, prompt);

			// Display a prompt asking the user to make a selection.
			//Console.Write(PROMPT);
			int.TryParse(Console.ReadLine(), out choice);

			// Validate the choice
			while (choice < MIN || choice > max)
			{
				Console.Write(
					centerLLAP("Please select from {0} to {1} only.") + prompt,
					MIN, max);
				// Display a prompt asking the user to make a selection.
				int.TryParse(Console.ReadLine(), out choice);
			}

			return choice;
		}

		/*
		 * Method:  ShowHeader
		 * Purpose: To show the business name and screen title; called mostly
		 *          upon reaching a different screen. A secondary call is when
		 *          the sales slip is displayed.
		 *
		 *          Due to mulitple places calling this function, the screen
		 *          title is optional (use a "" to skip it).
		 *
		 * Input:   screenTitle (string)
		 * Output:  none (void)
		 */
		private static void ShowHeader(string screenTitle)
		{
			string header = "\n\n" +
				centerLLAP("Vulcan Values Bookstore") + "\n" +
				centerLLAP("The Logical Choice LLAP");

			if (screenTitle.Length > 0)
			{
				header += "\n\n" + centerLLAP(screenTitle) + "\n";
			}

			Console.WriteLine(header);
		}

		/*
		 * Method:  centerLLAP
		 * Purpose: To center a line of text across 80 characters for
		 *          displaying on the screen in between the "Vulcan LLAP"
		 *          salute
		 *
		 * Input:   line (string)
		 * Output:  centered (string)
		 */
		private static string centerLLAP(string line)
		{
			const string SPACING = 
				"                                        ";
			const string LLAP = "\\\\// {0} \\\\//";
			const int SCREEN_WIDTH = 80;
			const int IN_HALF = 2;

			string centered = "";
			int spaces = 0;

			// Place input string in between \\//s
			centered = string.Format(LLAP,line);

			// If combined string is under screen width, center it
			if (centered.Length < SCREEN_WIDTH)
			{
				// Calculate the offset spaces
				spaces = (SCREEN_WIDTH - centered.Length) / IN_HALF;
				centered = SPACING.Substring(0,spaces) + centered;
			}

			return centered;
		}

		/*
		 * Method:  WaitAndClear
		 * Purpose: To prompt the user to continue by pressing a key.
		 *          After key press, the screen is cleared for the next screen.
		 *
		 * Input:   No input
		 * Output:  none (void)
		 */
		private static void WaitAndClear()
		{
			Console.Write(
				"\n\n" + 
				centerLLAP("Press a key to return to the main menu."));
			Console.ReadKey();
			Console.Clear();
		}

		/*
		 * Method:  PurchaseBook
		 * Purpose: To allow a User to enter in information for a purchased
		 *          book. It will show a sales slip unless an entry error
		 *          was made.
		 *
		 * Input:   No input
		 * Output:  total (double)
		 */
		private static double PurchaseBook()
		{
			const string SALES_SLIP_TOTALS_SPACER =
				"                                                    ";
			const double TAX_RATE = 9.1;
			const double PERCENT_TO_DECIMAL = 100.0;
			const int MAX_ISBN_LENGTH = 17;
			const int INVALID_MIN = 0;

			int bookQuantity = 0;
			double taxRate = TAX_RATE / PERCENT_TO_DECIMAL;
			double bookUnitPrice = 0.00;
			double bookPrice = 0.00;
			double subTotal = 0.00;
			double tax = 0.00;
			double total = 0.00;
			string bookDate = "";
			string bookISBN = "";
			string bookTitle = "";

			string validEntry = centerLLAP(
				"Please provide a valid {0}.") + "\n";
			string positiveEntry = centerLLAP(
				"Please provide a positive {0} over 0.") + "\n";
			bool canProcess = true;

			ShowHeader("Purchase Information");

			// On separate lines, display the prompts for purchasing a book
			// and wait for user input.
			Console.Write("Date (mm/dd/yyyy): ");
			bookDate = Console.ReadLine();
			if (bookDate.Length == INVALID_MIN)
			{
				Console.WriteLine(validEntry, "date");
				canProcess = false;
			}
			Console.Write("Quantity (#).....: ");
			int.TryParse(Console.ReadLine(), out bookQuantity);
			if (bookQuantity <= INVALID_MIN)
			{
				Console.WriteLine(positiveEntry, "quantity");
				canProcess = false;
			}
			Console.Write("ISBN.............: ");
			bookISBN = Console.ReadLine();
			if (bookISBN.Length == INVALID_MIN ||
				bookISBN.Length > MAX_ISBN_LENGTH)
			{
				Console.WriteLine(validEntry, "ISBN");
				canProcess = false;
			}
			Console.Write("Title............: ");
			bookTitle = Console.ReadLine();
			if (bookTitle.Length == INVALID_MIN)
			{
				Console.WriteLine(validEntry, "title");
				canProcess = false;
			}
			Console.Write("Price (#.##).....: ");
			double.TryParse(Console.ReadLine(), out bookUnitPrice);
			if (bookUnitPrice <= INVALID_MIN)
			{
				Console.WriteLine(positiveEntry, "price");
				canProcess = false;
			}

			// If all the values are correct, display the sales slip.
			if (canProcess)
			{
				// Calculate total for this purchase.
				bookPrice = bookQuantity * bookUnitPrice;
				// Add to sub-total. This will make more sense when multiple
				// purchases are allowed.
				subTotal += bookPrice;
			
				// Display a header for the on-screen sales slip.
				// Empty string will not print a \// screen title \\//
				ShowHeader("");
				Console.WriteLine("{0,79}\n", bookDate);
				Console.WriteLine(
					" Qty  {0,-17}  {1,-33}  {2,-7}  {3,10}\n" +
					" ---------------------------------------" +
					"---------------------------------------\n" +
					" {4,-3}  {5,-17}  {6,-33}  {7,-7:C}  {8,10:C}",
					"ISBN", "Title", "Price", "Total",
					bookQuantity, bookISBN, bookTitle, bookUnitPrice,
					bookPrice);

				// Calculate tax and add subtotal + tax to total.
				tax = subTotal * taxRate;
				total = subTotal + tax;

				// Display sub-total, tax, total & thank you
				Console.WriteLine(
                    "{4,79}\n{5}SubTotal....: {0,13:N}\n" +
					"{5}Tax ({1}%)..: {2,13:N}\n" +
					"{5}Total.......: {3,13:C}\n\n" +
					centerLLAP("Thank you for shopping at " +
						"Vulcan Values Bookstore!"),
					subTotal, TAX_RATE, tax, total, 
					"===========", SALES_SLIP_TOTALS_SPACER);
			}
			else
			{
				// If any of the values were invalid, display an error help 
				// message instead.
				Console.WriteLine(
					"\n\n" + centerLLAP("Unable to display sales slip with " +
					"invalid information."));
			}

			// Let user see the screen
			//Console.Write("\n" + centerLLAP("Press a key to continue"));
			//Console.ReadKey();
			WaitAndClear();

			// And pass the total back to caller.
			return total;
		}

		/*
		 * Method:  ReerveBook
		 * Purpose: To allow entry of a title not in currently in system so
		 *          that it may be ordered.
		 *
		 * Input:   none
		 * Output:  none (void)
		 */
		private static void ReserveBook()
		{
			const double INVALID_MIN = 0.00;
			const int MAX_ISBN_LENGTH = 17;
			
			string validEntry = centerLLAP(
				"Please provide a valid {0}.") + "\n";
			string positiveEntry = centerLLAP(
				"Please provide a positive {0} over 0.") + "\n";
			string bookISBN = "";
			string bookTitle = "";
			string bookAuthor = "";
			string bookPublisher = "";
			double bookCost = 0.00;
			bool canProcess = true;

			// Display the screen header & title
			ShowHeader("Book Reservation");

			// On separate lines, display the prompts for reserving a book
			// and wait for user input.
			Console.Write("ISBN.................: ");
			bookISBN = Console.ReadLine();
			if (bookISBN.Length == INVALID_MIN ||
				bookISBN.Length > MAX_ISBN_LENGTH)
			{
				Console.WriteLine(validEntry, "ISBN");
				canProcess = false;
			}
			Console.Write("Title................: ");
			bookTitle = Console.ReadLine();
			if (bookTitle.Length == INVALID_MIN)
			{
				Console.WriteLine(validEntry, "title");
				canProcess = false;
			}
			Console.Write("Author...............: ");
			bookAuthor = Console.ReadLine();
			if (bookAuthor.Length == INVALID_MIN)
			{
				Console.WriteLine(validEntry, "author");
				canProcess = false;
			}
			Console.Write("Publisher............: ");
			bookPublisher = Console.ReadLine();
			if (bookPublisher.Length == INVALID_MIN)
			{
				Console.WriteLine(validEntry, "publisher");
				canProcess = false;
			}
			Console.Write("Wholesale Cost (#.##): ");
			double.TryParse(Console.ReadLine(), out bookCost);
			if (bookCost <= INVALID_MIN)
			{
				Console.WriteLine(positiveEntry, "cost");
				canProcess = false;
			}

			// If all the values are correct, display the reservation message.
			if (canProcess)
			{
				// Display the user's inputs for their review
				Console.WriteLine("\n" +
					centerLLAP("Set phasers to stun and fire at:") +
					"\n{0} by {1}\nPublished by {2}\n" +
					"with an ISBN of {3} for the low, low price of {4:C}" +
					"\n\n\n\n",
					bookTitle, bookAuthor, bookPublisher, bookISBN, bookCost);
			}
			else
			{
				// If any of the values were invalid, display an error help 
				// message instead.
				Console.WriteLine("\n\n" +
					centerLLAP(
						"Unable to display reservation with invalid data."));
			}

			// Let user read the screen
			WaitAndClear();
		}

		/*
		 * Method:  Inventory
		 * Purpose: To add, edit or delete books from the inventory.
		 *          Functionality not fully implemented at this time.
		 *          Currently, it prints a choice confirmation.
		 *
		 * Input:   bookChoice (string)
		 * Output:  none (void)
		 */
		private static void Inventory(string bookChoice)
		{
			// Display the screen header & title
			ShowHeader("Inventory");
			Console.WriteLine("\n\n\n\n" +
				centerLLAP("You selected \"" + bookChoice + "\"") +
				"\n\n\n\n\n\n\n\n\n");

			// Let the user see the screen before returning
			WaitAndClear();
		}

		/*
		 * Method:  ExitShop()
		 * Purpose: To show a thank you message in preparation to end
		 *          the program.
		 *
		 * Input:   none
		 * Output:  none (void)
		 */
		private static void ExitShop()
		{
			// Display the screen header & title
			// Why here? For grins & to match the other menu choices
			ShowHeader("Exit, stage left even");

			// Display a multi-line thank you
			Console.WriteLine("\n\n\n\n" + 
				centerLLAP("Thank you for doing business " +
					"with Vulcan Values Bookstore!") + "\n" +
				centerLLAP("We are here to help you with " +
					"your book purchases.         ") + "\n" +
				centerLLAP("It is the logical choice. LLAP" +
					"                            ") + "\n\n\n\n" +
				centerLLAP("Please come back again!"));
		}
	}
}
