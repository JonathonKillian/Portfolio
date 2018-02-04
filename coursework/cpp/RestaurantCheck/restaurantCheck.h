#pragma once

// External Definition files
// -------------------------
#include <string>
#include <windows.h>

using std::string;		// Only need to reference string from std namespace

/*******************************************************************************
*      Class: RestaurantCheck
* Base Class: None
*
* Programmer: Jon Killian
*
*
* Revision     Date                          Release Comment
* --------  ----------  --------------------------------------------------------
*   1.0     11/10/2016  Initial Release
*
*
* Class Description
* -----------------
* This class simulates the creation and display of a restaurant check via a menu
* and on-screen "check."
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
*
* -------------------------- Private Data Members ------------------------------
*             	 Data
*    Type     	 Type   Name                     Description
* ------------	------  ------------------	------------------------------------
* static const	double	MIN_TAX_PERCENT		Minimum valid tax rate
* static const	double	DEFAULT_TAX_PERCENT	Default tax rate
* static const	double	MAX_TAX_PERCENT		Maximum valid tax rate
* static const	double	MIN_TIP_PERCENT		Minimum valid tip rate
* static const	double	DEFAULT_TIP_PERCENT	Default tip rate
* static const	double	MAX_TIP_PERCENT		Maximum valid tip rate
* static const	double	PERCENT_CONVERT		To convert % to decimal
* static const	int		NO_ORDER			Invalid order (for order[])
* static const	int		MAX_ORDER			Maximum order (for order[])
* static const	int		MIN_MENU			Minimum menu choice
* static const	int		MAX_MENU			Maximum menu choice
* static const	int		ORDER_COMPLETE		Menu choice to end orders early
* static const	int		PRECISION_DOUBLE	Precision value used for doubles
* static const	int		PRECISION_INT		Precision value used for ints
* static const	short	COL_CENTER_TITLE1	Column for screen title, line 1
* static const	short	COL_CENTER_TITLE2	Column for screen title, line 2
* static const	short	COL_LEFT			Base column for left screen side
* static const	short	COL_RIGHT			Base column for right screen side
* static const	short	OFFSET_SEPARATOR	Column offset for ordinal separator
* static const	short	OFFSET_ITEM			Column offset for menu item text
* static const	short	OFFSET_TAX			Column offset for Tax & Tip
* static const	short	OFFSET_TOTAL		Column offset for Totals
* static const	short	OFFSET_SIGN			Column offset for '$'
* static const	short	OFFSET_PRICE		Column offset for the menu prices
* static const	short	ROW_TITLE1			Row for Title line 1
* static const	short	ROW_TITLE2			Row for Title line 2
* static const	short	ROW_ITEMS			Top row for the screen body
* static const	short	ROW_CHOICES			Top row for User's selections
* static const	short	OFFSET_THANKS2		Row offset for Thank you line 2
* static const	short	OFFSET_THANKS3		Row offset for Thank you line 3
* static const	int		WIDTH_ORDINAL		Column width for ordinals
* static const	int		WIDTH_ITEM			Column width for menu items
* static const	int		WIDTH_PRICE			Column width for menu prices
* static const	int		WIDTH_TAX			Column width for Check Tax/Tip %
* static const	int		WIDTH_COLUMNS		Number of column groups
* static const	string	BUSINESS_NAME		The Restaurant's business name
* static const	string	ORDINAL_SEPARATOR	What's placed after the ordinals
* static const	string	DOLLAR_SIGN			The '$'
* static const	string	CANCEL_PROMPT		The cancel prompt for promptYN
* static const	string	CONFIRM_PROMPT		The control prompt for promptYN
* static const	string	TOTAL_BAR			Dashes to indicate a total
* static const	string	MENU_ITEMS[]		Parallel array holding menu items
* static const	double	MENU_PRICES[]		Parallel array holding menu prices
* non-static	double	taxRate				Holds the tax rate as a decimal
* non-static	double	tipRate				Holds the tip rate as a decimal
* non-static	int		order[MAX_ORDER]	Array to hold User's menu choices
* non-static	int		orderCount			Array offset into order[]
* non-static	HANDLE	screen				Handle to the standard console
*
*
* --------------------------- Public Data Members ------------------------------
*              Data
*    Type      Type   Name                    Description
* ----------  ------  ----  ----------------------------------------------------
*                         *** No public data members ***
*
*******************************************************************************/
class RestaurantCheck
{
public:
    // Constructor
    RestaurantCheck(double = DEFAULT_TAX_PERCENT, double = DEFAULT_TIP_PERCENT);

    // Public Mutator methods
    bool placeOrder();

    // Public Accessor methods
    void issueCheck();

    // Public static Validation methods
    static bool testTaxRate(double);
    static bool testTipRate(double);

private:
	// Percentage rates
	static const double MIN_TAX_PERCENT;
	static const double DEFAULT_TAX_PERCENT;
	static const double MAX_TAX_PERCENT;
	static const double MIN_TIP_PERCENT;
	static const double DEFAULT_TIP_PERCENT;
	static const double MAX_TIP_PERCENT;
	static const double PERCENT_CONVERT;
	// Array boundaries
	static const int    NO_ORDER;
	static const int    MAX_ORDER = 5;
	static const int    MIN_MENU;
	static const int    MAX_MENU;
	static const int    ORDER_COMPLETE;
	// How many places past the decimal point for doubles & ints
	static const int    PRECISION_DOUBLE;
	static const int    PRECISION_INT;
	// Screen coordinates grouped by col(umn) and row.
	static const short  COL_CENTER_TITLE1;
	static const short  COL_CENTER_TITLE2;
	static const short  COL_LEFT;
	static const short  COL_RIGHT;
	static const short  OFFSET_SEPARATOR;
	static const short  OFFSET_ITEM;
	static const short  OFFSET_TAX;
	static const short  OFFSET_TOTAL;
	static const short  OFFSET_SIGN;
	static const short  OFFSET_PRICE;
	static const short  ROW_TITLE1;
	static const short  ROW_TITLE2;
	static const short  ROW_ITEMS;
	static const short  ROW_CHOICES;
	static const short  OFFSET_THANKS2;
	static const short  OFFSET_THANKS3;
	// Column widths
	static const int    WIDTH_ORDINAL;
	static const int    WIDTH_ITEM;
	static const int    WIDTH_PRICE;
	static const int    WIDTH_TAX;
	static const int    WIDTH_COLUMNS;
	// Static texts
	static const string BUSINESS_NAME;
	static const string ORDINAL_SEPARATOR;
	static const string DOLLAR_SIGN;
	static const string CANCEL_PROMPT;
	static const string CONFIRM_PROMPT;
	static const string TOTAL_BAR;
	// Parallel arrays holding the menu items and prices.
	static const string MENU_ITEMS[];
	static const double MENU_PRICES[];

    double taxRate;
    double tipRate;
	// Hold on to the order between calls to class methods
    int order[MAX_ORDER];
	int orderCount;
	HANDLE screen;			// Class does screen buffer cursor manipulation.

	// Private mutator function(s)
	bool saveOrder(int);
	void clearOrder();
	
	// Private accessor functions
    double calculateTax(double) const;
    double calculateTip(double) const;

	// Private screen menu/form functions
    void presentMenu();
	int  promptChoice(short);
	bool promptYN(short, string);
	void displayMenuItem(short, short, int);
	void displayMenuChoice(short, short, int);
	void displayCheckItem(short, short, int);
	void processCheckTotals(short, short, double);
	void displayAt(short, short, string);	// Strings don't need to setw()
	// The two numeric displayAt alter the precision of the output stream
	void displayAt(short, short, double, int);
	void displayAt(short, short, int, int);
	void setCursor(short, short);
	void clearEOL(short, short);
	void clearStreamForInput();
	bool checkStream();
};
