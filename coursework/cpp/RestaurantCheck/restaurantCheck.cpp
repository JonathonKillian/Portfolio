// Compile with "cl /EHsc PROG111_Project8_V2.cpp restaurantCheck.cpp

/*******************************************************************************
*      Class: RestaurantCheck
* Base Class: None
*
* Programmer: Jon Killian
*
* Revision     Date                          Release Comment
* --------  ----------  --------------------------------------------------------
*   1.0     11/10/2016  Initial Release
*
*
* File Description
* ----------------
* This file contains the external class method definitions and the
* initialization of any constant, "const" values declared at Class scope.
*
*
* ------------------------- Public Methods Interface ---------------------------
*      Method                            Description
* ----------------  ------------------------------------------------------------
* RestaurantCheck	Initiator/Default constructor.
* placeOrder		Displays the menu and prompts for orders
* issueCheck		Calculations for and displays the check
* testTaxRate		Validates the tax argument is within valid range.
* testTipRate		Validates the tip argument is within valid range.
*
* ----------------------------- Private Methods --------------------------------
*      Method                            Description
* ----------------  ------------------------------------------------------------
* saveOrder			Saves the User's menu selection to array
* clearOrder		Clears the order array for initialization and re-input.
* calculateTax		Calculates the tax on the check's subTotal
* calculateTip		Calculates the tip on the check's subTotal
* presentMenu		Displays the menu based on parallel arrays.
* promptChoice		Prompts, collects & validates the User's menu choice.
* promptYN			Prompts & collects the User for a yes/no response.
* displayMenuItem	Displays the information for a single menu item
* displayCheckItem	Displays the information for an item order on the Check
* processCheckTotals	Calculates and displays the Check's tax, tip & totals.
* displayAt			Displays a string at the supplied screen location
* displayAt			Displays a formatted double at the supplied screen location
* displayAt			Displays a formatted int at the supplied screen location
* setCursor			Moves the screen's cursor
* clearEOL			Clears from the cursor to the end of the same line/row
* clearStreamForInput	Restores input stream to good state and clears buffer
* checkStream		Checks the stream for errors or remaining char in the buffer
*
* ----------------------- Data Member Initializations --------------------------
* Unsure how to fill this section out; in previous project told to ignore.
* There are several static consts defined in this file dealing with screen
* coordinates, column offsets & widths, minimums, maximums, defaults, and a
* parallel array holding menu items and menu prices.
*
*******************************************************************************/

// External Definition files
#include <iostream>					// For I/O streams
#include <iomanip>					// For stream manipulators
#include <string>					// For string object
#include <cctype>					// For toupper()
#include <windows.h>
#include "restaurantCheck.h"

using namespace std;

// Percentage rates
const double RestaurantCheck::MIN_TAX_PERCENT     =   1.00;
const double RestaurantCheck::DEFAULT_TAX_PERCENT =   6.50;
const double RestaurantCheck::MAX_TAX_PERCENT     =  12.00;
const double RestaurantCheck::MIN_TIP_PERCENT     =   5.00;
const double RestaurantCheck::DEFAULT_TIP_PERCENT =  15.00;
const double RestaurantCheck::MAX_TIP_PERCENT     =  20.00;
const double RestaurantCheck::PERCENT_CONVERT     = 100.00;
// Array boundaries
const int    RestaurantCheck::NO_ORDER          =  0;
// the constant MAX_ORDER is set in the header due to use in order[] declaration
const int    RestaurantCheck::MIN_MENU          =  1;
const int    RestaurantCheck::MAX_MENU          = 10;
const int    RestaurantCheck::ORDER_COMPLETE    = MAX_MENU + 1;
// How many places past the decimal point for doubles & ints
const int    RestaurantCheck::PRECISION_DOUBLE  =  2;
const int    RestaurantCheck::PRECISION_INT     =  0;
// Screen coordinates grouped by col(umn) and row.
const short  RestaurantCheck::COL_CENTER_TITLE1 = 32;	// Business name
const short  RestaurantCheck::COL_CENTER_TITLE2 = 38;	// Screen title
const short  RestaurantCheck::COL_LEFT          =  2;	// Screen columns
const short  RestaurantCheck::COL_RIGHT         = 42;
const short  RestaurantCheck::OFFSET_SEPARATOR  =  2;
const short  RestaurantCheck::OFFSET_ITEM       =  4;	// Menu item description
const short  RestaurantCheck::OFFSET_TAX        = 15;	// Tax/Tip on check
const short  RestaurantCheck::OFFSET_TOTAL      = 18;	// Totals on check
const short  RestaurantCheck::OFFSET_SIGN       = 28;	// Dollar Sign for price
const short  RestaurantCheck::OFFSET_PRICE      = 29;	// Menu price
const short  RestaurantCheck::ROW_TITLE1        =  0;	// Business name
const short  RestaurantCheck::ROW_TITLE2        =  1;	// Screen title
const short  RestaurantCheck::ROW_ITEMS         =  4;	// Top row of menu
const short  RestaurantCheck::ROW_CHOICES       = 11;	// Top row of prompts
const short  RestaurantCheck::OFFSET_THANKS2    =  1;	// Offset rows
const short  RestaurantCheck::OFFSET_THANKS3    =  3;
// Column widths
const int    RestaurantCheck::WIDTH_ORDINAL     =  2;
const int    RestaurantCheck::WIDTH_ITEM        = 23;
const int    RestaurantCheck::WIDTH_PRICE       =  6;
const int    RestaurantCheck::WIDTH_TAX         =  5;
const int    RestaurantCheck::WIDTH_COLUMNS     =  2;	// How many columns?
// Static texts
const string RestaurantCheck::BUSINESS_NAME     = "Who-ville Grille";
const string RestaurantCheck::ORDINAL_SEPARATOR = ".";
const string RestaurantCheck::DOLLAR_SIGN       = "$";
const string RestaurantCheck::CANCEL_PROMPT     = "Cancel your order";
const string RestaurantCheck::CONFIRM_PROMPT    = "Is your order correct";
const string RestaurantCheck::TOTAL_BAR         = "------";
// Restaurant theme is Dr. Suess. Sources: 
// http://www.dartmouth.edu/~library/digital/collections/books/ocm45408191/ocm45408191.html
// http://spoonuniversity.com/lifestyle/how-to-celebrate-dr-seuss-day-with-classic-foods-from-his-best-stories
// Parallel arrays holding the menu items and prices.
const string RestaurantCheck::MENU_ITEMS[]
{
	"Green Eggs & Ham",
	"Roast Beast",
	"Wham Chops",
	"Glunker Stew",
	"Who Hash",
	"Truffula Fruit",
	"Choc'late Mush-Mush",
	"Blueberry Bumplings",
	"Goose Juice",
	"Butterfly Milk",
};
const double RestaurantCheck::MENU_PRICES[]
{
     9.99,				// Green Eggs & Ham
    15.98,				// Roast Beast
    13.29,				// Wham Chops
     7.35,				// Glunker Stew
     4.75,				// Who Hash
     4.48,				// Truffula Fruit
     6.49,				// Choc'late Mush-Mush
     5.55,				// Blueberry Bumplings
     1.99,				// Goose Juice
     2.49				// Butterfly Milk
};

/*******************************************************************************
*
* Class constructors
*
*******************************************************************************/

/***************
* Constructor:	Initializer/Default
* Description:	Initializes the private members to a good state. Doubles as a
*				default constructor in that the parameters have default values,
*				the same ones used if either parameter is invalid.
*
* Input(s):		double tax, tip (the tax rate % & tip rate %)
*
* Output(s):	None
****************/
RestaurantCheck::RestaurantCheck(double tax, double tip)
{
	// Validate the tax and tip, using the default values for invalid values.
    taxRate = (testTaxRate(tax)) ? tax : DEFAULT_TAX_PERCENT;
    tipRate = (testTipRate(tip)) ? tip : DEFAULT_TIP_PERCENT;

	// Technically, we can leave order[] uninitialized, but it wouldn't hurt
	clearOrder();

	// Need to get the screen handle for cursor manipulation
	screen = GetStdHandle(STD_OUTPUT_HANDLE);
}

// No other constructors needed at this time.

/*******************************************************************************
*
* Methods: Public Mutators
*
*******************************************************************************/

/***************
* Method:		placeOrder
* Description:	Displays an on-screen infterface to the User and controls the
*				prompting for menu selections.
*
* Input(s):		None
*
* Output(s):	(bool) the result of the count of orders being non-zero.
****************/
bool RestaurantCheck::placeOrder()
{
	int item = NO_ORDER;
	short row = ROW_CHOICES;
	bool orderCompleted = false;
	string confirm = CONFIRM_PROMPT;

	// Make sure the fixed stream modifier is set
	cout << fixed;

	// Display menu
	presentMenu();

	do
	{
		// Reset for the current iteration
		row = ROW_CHOICES;
		clearOrder();

		// Prompt User for menu selections, up to a maximum number of orders
		do
		{
			item = promptChoice(row);
			if (item != ORDER_COMPLETE)
			{
				// Save the order
				orderCompleted = saveOrder(item);

				// Display the menu item with dollar sign
				displayMenuChoice(row, COL_LEFT, item);

				++row;					// Move down a row for next iteration
			}
			else
			{
				orderCompleted = true;
			}
		} while (!orderCompleted);

		// Confirm the order to break out of the loop.
		if (orderCount == NO_ORDER)
		{
			confirm = CANCEL_PROMPT;
		}
		else
		{
			confirm = CONFIRM_PROMPT;
		}
		orderCompleted = promptYN(row, confirm);
	} while (!orderCompleted);

	// Return back if an order was placed at all
	return orderCount != NO_ORDER;
}

/*******************************************************************************
*
* Methods: Public
*
*******************************************************************************/

/***************
* Method:		issueCheck
* Description:	Displays the "check" for dues based on the order collected by
*				placeOrder().
*
* Input(s):		None
*
* Output(s):	(void)
****************/
void RestaurantCheck::issueCheck()
{
	const string AT = "at ";

	short colThankYou = COL_RIGHT + OFFSET_ITEM;
	short row = ROW_ITEMS;
	double subTotal = 0;
	double total = 0;
	double tax = 0;
	double tip = 0;

    // Clear the screen
	system("cls");

	// Make sure the fixed stream modifier is set
	cout << fixed;

	// Display Screen header
	displayAt(ROW_TITLE1, COL_CENTER_TITLE1, BUSINESS_NAME);
	displayAt(ROW_TITLE2, COL_CENTER_TITLE2, "Check");

	// Display the thank you message
	displayAt(ROW_ITEMS,                  colThankYou,
			  "Thank you for visiting us here");
	displayAt(ROW_ITEMS + OFFSET_THANKS2, colThankYou, AT + BUSINESS_NAME);
	displayAt(ROW_ITEMS + OFFSET_THANKS3, colThankYou,
			  "Please come again soon!");

	// Display the customer's order
	for (int item = 0; item < orderCount; ++item)
	{
		// Display the menu item
		displayCheckItem(row, COL_LEFT, order[item]);
		
		// Accumulate its price
		subTotal += MENU_PRICES[order[item]];

		// Advance the row (will need it even after the loop
		++row;
	}

	// Calculate and display the totals section
	processCheckTotals(row, COL_LEFT, subTotal);
}

/*******************************************************************************
*
* Methods: Public Static Validators
*
*******************************************************************************/

/***************
* Method:		testTaxRate
* Description:	Validates the passed-in argument is within a valid range as set
*				by class static constants.
*
* Input(s):		double percentage (The tax rate as a decimal percentage)
*
* Output(s):	(bool) (Is the argument within range?)
****************/
bool RestaurantCheck::testTaxRate(double percentage)
{
    return percentage >= MIN_TAX_PERCENT && percentage <= MAX_TAX_PERCENT;
}

/***************
* Method:		testTipRate
* Description:	Validates the passed-in argument is within a valid range as set
*				by class static constants.
*
* Input(s):		double percentage (The tipping rate as a decimal percentage)
*
* Output(s):	(bool) (Is the argument within range?)
****************/
bool RestaurantCheck::testTipRate(double percentage)
{
    return percentage >= MIN_TIP_PERCENT && percentage <= MAX_TIP_PERCENT;
}

/*******************************************************************************
*
* Methods: Private Mutators
*
*******************************************************************************/

/***************
* Method:		saveOrder
* Description:	Save the User's menu selection if there is room.
*
* Input(s):		int item	(The array element from the parallel arrays)
*
* Output(s):	(bool)		(Is the order complete; as in can't add anymore)
****************/
bool RestaurantCheck::saveOrder(int item)
{
	// Adjust for menu selections being 1-based and the array 0-based
	--item;

	// If we've room to save, save
	if (orderCount < MAX_ORDER)
	{
		order[orderCount++] = item;
	}

	return orderCount >= MAX_ORDER;
}

/***************
* Method:		clearOrder
* Description:	Sets the order[] array to NO_ORDER as there is a possiblity to
*				scratch the order and re-start it.
*
* Input(s):		None
*
* Output(s):	(void)
****************/
void RestaurantCheck::clearOrder()
{
	for (int o = 0; o < MAX_ORDER; ++o)
	{
		order[o] = NO_ORDER;
	}
	
	// Reset the count of orders
	orderCount = 0;
}

/*******************************************************************************
*
* Methods: Private Accessors/Helpers
*
*******************************************************************************/

/***************
* Method:		calculateTax
* Description:	Calculates the tax based on the check subtotal.
*
* Input(s):		double amount (The subtotal amount of the check)
*
* Output(s):	(double) (amount * taxRate)
****************/
double RestaurantCheck::calculateTax(double amount) const
{
    return amount * taxRate / PERCENT_CONVERT;
}

/***************
* Method:		calculateTip
* Description:	Calculates the tip based on the check subtotal
*
* Input(s):		double amount (The subtotal amount of the check)
*
* Output(s):	(double) (amount * tipRate)
****************/
double RestaurantCheck::calculateTip(double amount) const
{
    return amount * tipRate / PERCENT_CONVERT;
}

/*******************************************************************************
*
* Methods: Private screen menu/form
*
*******************************************************************************/

/***************
* Method:		presentMenu
* Description:	Displays the menu as on-screen form.
*
* Input(s):		None
*
* Output(s):	(void)
****************/
void RestaurantCheck::presentMenu()
{
	int maxRow = MAX_MENU / WIDTH_COLUMNS + ROW_ITEMS;
	int item = MIN_MENU;

    // Clear screen
	system("cls");

	// Display Screen header
	displayAt(ROW_TITLE1, COL_CENTER_TITLE1, BUSINESS_NAME);
	displayAt(ROW_TITLE2, COL_CENTER_TITLE2, "Menu");

	// Display the menu items across columns
	for (int row = ROW_ITEMS; row < maxRow; ++row)
	{
		displayMenuItem(row, COL_LEFT,  item++);
		displayMenuItem(row, COL_RIGHT, item++);
	}
}

/***************
* Method:		promptChoice
* Description:	Prints a prompt, awaits User input & validates the input.
*
* Input(s):		short row	(The screen row)
*
* Output(s):	int choice	(The User's input)
****************/
int RestaurantCheck::promptChoice(short row)
{
	short colPrompt = COL_LEFT + OFFSET_ITEM;
	short colError  = COL_RIGHT + OFFSET_ITEM;
	bool choiceInvalid = true;
	int choice = NO_ORDER;

	// Move the cursor and clear to end of line for prompt visibility.
	clearEOL(row, colPrompt);

	// Loop until User enters a valid choice.
	do
	{
		cout << "Enter Menu item #" << orderCount + 1 << " (" << ORDER_COMPLETE
			 << " to stop): ";
		cin  >> choice;

		// Validate the input. There is only 1 error message.
		if (!checkStream() ||						// Non-integer input
			choice < MIN_MENU ||					// Non-positive input
			choice > ORDER_COMPLETE)				// Too high an input
		{
			// Clear the state and the row
			clearStreamForInput();
			clearEOL(row, colPrompt);

			// Display the error message & re-setup for prompt.
			setCursor(row, colError) ;
			cout << "Please use a whole number, " << MIN_MENU
				 << "-" << ORDER_COMPLETE << endl;
			setCursor(row, colPrompt);
		}
		else
		{
			choiceInvalid = false;
		}
	} while (choiceInvalid);

	// Clear the line; the caller will display the outcome of the choice
	clearEOL(row, colPrompt);

	// Function completed, return choice back to caller.
	return choice;
}

/***************
* Method:		promptYN
* Description:	Prints a prompt, awaits User input & validates the input.
*
* Input(s):		short  row		(The screen row)
*				string prompt	(The prompt to the User)
*
* Output(s):	int choice	(The User's input)
****************/
bool RestaurantCheck::promptYN(short row, string prompt)
{
	const char YES = 'Y';
	const char OR  = '/';
	const char NO  = 'N';

	char choice = YES;
	short colPrompt = COL_LEFT + OFFSET_ITEM;
	short colError  = COL_RIGHT + OFFSET_ITEM;
	bool noYN = true;

	// Make sure the stream is good & empty
	clearStreamForInput();

	// Move the cursor and clear to end of line for prompt visibility.
	clearEOL(row, colPrompt);

	do
	{
		// Display the prompt
		cout << prompt << " (" << YES << OR << NO << ")? ";

		// Get User's answer
		choice = cin.get();

		// Validate
		if (checkStream())
		{
			// Convert to uppercase to match the valid choices.
			choice = toupper(choice);
			
			// And validate the range
			if (choice == YES || choice == NO)
			{
				noYN = false;
			}
		}
		else
		{
			// Clear the stream buffer
			clearStreamForInput();
		}

		if (noYN)
		{
			// Clear the line and print an error message
			clearEOL(row, colPrompt);
			setCursor(row, colError);
			cout << "Was that a " << YES << " or " << NO << "?" << endl;
			// Return the cursor to the prompt location for next iteration.
			setCursor(row, colPrompt);
		}
	} while (noYN);

	// Inform the caller of a yes or no.
	return choice == YES;
}

/***************
* Method:		displayMenuItem
* Description:	Displays a menu item, with its item number and price
*				The various columns are based on the original column argument
*				so as to allow this function to be used across  "menu columns."
*
* Input(s):		short  row		(The screen row)
*				short  column	(The starting screen column)
*				int    item		(The menu item represented as an array element)
*
* Output(s):	(void)
****************/
void RestaurantCheck::displayMenuItem(short row, short column, int item)
{
	// Display the item ordinal
	displayAt (row, column,                    item, WIDTH_ORDINAL);
	displayAt (row, column + OFFSET_SEPARATOR, ORDINAL_SEPARATOR);

	// Adjust for menu selections being 1-based and the array 0-based
	--item;

	// Display the menu item with the adjusted item value
	displayAt (row, column + OFFSET_ITEM,      MENU_ITEMS[item]);
	// Display the Menu price, based on the adjusted item.
	displayAt (row, column + OFFSET_PRICE,     MENU_PRICES[item], WIDTH_PRICE);
}

/***************
* Method:		displayMenuChoice
* Description:	Displays a menu item, with its orderCount number and price with
*				dollar sign.
*				The various columns are based on the original column argument
*				so as to allow this function to be used across  "menu columns."
*
*				This function expects the "choice" to already be saved.
*
* Input(s):		short  row		(The screen row)
*				short  column	(The starting screen column)
*				int    item		(The menu item represented as an array element)
*
* Output(s):	(void)
****************/
void RestaurantCheck::displayMenuChoice(short row, short column, int item)
{
	// Expected to be called after saving the choice!
	int choice = orderCount;

	// Adjust for menu selections being 1-based and the array 0-based
	--item;

	// Display the order number.
	displayAt (row, column,                    choice, WIDTH_ORDINAL);
	displayAt (row, column + OFFSET_SEPARATOR, ORDINAL_SEPARATOR);
	displayAt (row, column + OFFSET_ITEM,      MENU_ITEMS[item]);
	displayAt (row, column + OFFSET_SIGN,      DOLLAR_SIGN);
	displayAt (row, column + OFFSET_PRICE,     MENU_PRICES[item], WIDTH_PRICE);
}

/***************
* Method:		displayCheckItem
* Description:	Displays an ordered menu selection, with its price
*				The various columns are based on the original column argument
*				so as to allow this function to be used across  "menu columns."
*
* Input(s):		short row		(The screen row)
*				short column	(The starting screen column)
*				int   item		(The menu item represented as an array element)
*
* Output(s):	(void)
****************/
void RestaurantCheck::displayCheckItem(short row, short column, int item)
{
	// Move cursor
	setCursor(row, column + OFFSET_ITEM);

	// Display the menu item (Can't use displayAt() due to the right modifier
	cout << right << setw(WIDTH_ITEM) << MENU_ITEMS[item] << endl;
	displayAt(row, column + OFFSET_SIGN, DOLLAR_SIGN);
	displayAt(row, column + OFFSET_PRICE,  MENU_PRICES[item], WIDTH_PRICE);
}

/***************
* Method:		processCheckTotals
* Description:	Calculate the tax, tip and total based on the passed-in
*				subtotal, display all the calculations
*				The various columns are based on the original column argument
*				so as to allow this function to be used across  "menu columns."
*
* Input(s):		short  row		(The screen row)
*				short  column	(The starting screen column)
*				double subTotal	(The accumulated total from the order)
*
* Output(s):	(void)
****************/
void RestaurantCheck::processCheckTotals(short row, short column,
										 double subTotal)
{
	// Calculate the tax, tip & total due
	double tax   = calculateTax(subTotal);
	double tip   = calculateTip(subTotal);
	double total = subTotal + tax + tip;

	// Display the calculations.
	displayAt(  row, column + OFFSET_PRICE, TOTAL_BAR);
	displayAt(++row, column + OFFSET_TOTAL, "Sub Total");
	displayAt(  row, column + OFFSET_SIGN, DOLLAR_SIGN);
	displayAt(  row, column + OFFSET_PRICE, subTotal, WIDTH_PRICE);
	setCursor(++row, column + OFFSET_TAX);
	cout << "Tax (" << setw(WIDTH_TAX) << taxRate << "%) "
		 << DOLLAR_SIGN << endl;
	displayAt(  row, column + OFFSET_PRICE, tax, WIDTH_PRICE);
	setCursor(++row, column + OFFSET_TAX);
	cout << "Tip (" << setw(WIDTH_TAX) << tipRate << "%) "
		 << DOLLAR_SIGN << endl;
	displayAt(  row, column + OFFSET_PRICE, tip, WIDTH_PRICE);
	displayAt(++row, column + OFFSET_PRICE, TOTAL_BAR);
	displayAt(++row, column + OFFSET_TOTAL, "Total Due");
	displayAt(  row, column + OFFSET_SIGN, DOLLAR_SIGN);
	displayAt(  row, column + OFFSET_PRICE, total, WIDTH_PRICE);
}

/***************
* Method:		displayAt
* Description:	Moves the cursor and prints a string at the location.
*
* Input(s):		short  row		(The screen row)
*				short  column	(The starting screen column)
*				string text		(The string to display on screen)
*
* Output(s):	(void)
****************/
void RestaurantCheck::displayAt(short row, short column, string text)
{
	setCursor(row, column);
	cout << text << endl;
}

/***************
* Method:		displayAt
* Description:	Moves the cursor and prints a double at the location with a
*				precision for doubles and a column width.
*
* Input(s):		short  row		(The screen row)
*				short  column	(The starting screen column)
*				double number	(The double to display on screen)
*				int    width	(The width of the numeric column)
*
* Output(s):	(void)
****************/
void RestaurantCheck::displayAt(short row, short column, double number,
								int width)
{
	setCursor( row, column);
	cout << setprecision(PRECISION_DOUBLE) << setw(width) <<  number << endl;
}

/***************
* Method:		displayAt
* Description:	Moves the cursor and prints an integer at the location with a
*				precision for integers (i.e., nothing past the decimal point,
*				even the decimal point) and a column width.
*
* Input(s):		short  row		(The screen row)
*				short  column	(The starting screen column)
*				int    number	(The int to display on screen)
*				int    width	(The width of the numeric column)
*
* Output(s):	(void)
****************/
void RestaurantCheck::displayAt(short row, short column, int number, int width)
{
	setCursor(row, column);
	cout << setprecision(PRECISION_INT) << setw(width) <<  number << endl;
}

/***************
* Method:		setCursor
* Description:	Moves the screen cursor to the passed-in coordinates.
*				Mostly just a shorter name for SetConsoleCursorPosition
*				and using separate values instead of the wanted COORD struct.
*
* Input(s):		short row		(The screen row)
*				short column	(The starting screen column)
*
* Output(s):	(void)
****************/
void RestaurantCheck::setCursor(short row, short column)
{
	COORD coord;

	// Need to place the row and column arguments into a COORD struct
	coord.Y = row;
	coord.X = column;

	// And set the new cursor position
	SetConsoleCursorPosition(screen, coord);
}

/***************
* Method:		clearEOL
* Description:	Clear the screen line from the cursor to end of the same line.
*				It leaves the cursor at the passed in screen coordinates.
*
* Input(s):		short row	(The row to clear)
*				short col	(The column to start clearing at)
*
* Output(s):	(void)
****************/
void RestaurantCheck::clearEOL(short row, short column)
{
	// For debugging, I may switch to visible character.
	const char CLEAR = ' ';
	const int COUNT_ZERO = 1;				// Include zeroth row

	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	// Screen coordinates are zero-based, need to account for it in width.
	int toClear = COUNT_ZERO;

	GetConsoleScreenBufferInfo(screen, &screenInfo);
	toClear += screenInfo.srWindow.Right - column;
	// Why loop, when a string constructor can do it for us.
	string toEOL(toClear, CLEAR);

	// Move cursor and clear to the end of line
	displayAt(row, column, toEOL);

	// Move back to start of "clearing"
	setCursor(row, column);
}

/***************
* Method:		clearStreamForInput
* Description:	Restores the input stream to a good state and empties the input
*				buffer.
*
* Input(s):		None
*
* Output(s):	(void)
****************/
void RestaurantCheck::clearStreamForInput()
{
	// Make sure stream is in good state so we can read from it.
	cin.clear();

	// Read and discard all the remaining characters in the input buffer.
	cin.ignore(cin.rdbuf()->in_avail());
}

/***************
* Method:		checkStream
* Description:	Validates the stream is in good state and that only the Enter
*				is present in the input buffer
*
* Input(s):		short row	(The screen row)
*
* Output(s):	int choice	(The User's input)
****************/
bool RestaurantCheck::checkStream()
{
	const int MIN_BUFFER = 1;	// Account for the Enter key

	bool isGood = true;
	
	return cin && cin.rdbuf()->in_avail() == MIN_BUFFER;
}