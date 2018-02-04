/*******************************************************************************
* Bellevue Class: PROG-113
*           Term: Spring 2017
*     Instructor: Robert Main
*
* Solution/Project Name: KillianProject9/KillianProject9
*             File Name: KillianProject9.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Programmer: Jon Killian
*
* Assigned Project Number: 9
*
* Revision	   Date							Release Comment
* --------	----------	--------------------------------------------------------
*	1.0		06/01/2017	Initial Release
*
* Program Inputs
* --------------
*  Device								Description
* --------	--------------------------------------------------------------------
* Keyboard	User to just press Enter to close console window
*
* Program Outputs
* ---------------
*  Device								Description
* --------	--------------------------------------------------------------------
* Monitor	Intro, status messages and multiple stringified linked lists.
*
* UDTs (User Defined Types) Utilized
* -----------------------------------
*     Name								Description
* ------------	----------------------------------------------------------------
* LinkedList	The UDT defines methods for linked-list creation & manipulation
*
* File Methods
* ------------
*     Name								Description
* ------------	----------------------------------------------------------------
* main          Program entry point method
* floatRandom	Generates a random double within passed-in range
*******************************************************************************/
// External Definition files
#include <iostream>				// Defines console stream I/O objects
#include <iomanip>				// Defines I/O Stream manipulators
#include <cstdlib>				// Defines random functions
#include <chrono>				// Defines system_clock::now()
#include <string>				// Defines string objects
#include "LinkedList.h"			// Defines linkedList<T> ADT

// Namespaces utilized in this program
using namespace std;			// Using functions in the std namespace
using namespace std::chrono;	// Using functions in the std::chrono namespace

// Method Prototypes
// -----------------
double floatRandom(double, double);

/*******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program is loosely a test program for the LinkedList class found in
* LinkedList.h, following five of the text book's chapter 17 challenges: #1 - #3
* and #5-#6 (Linked List class with copy constructor, toString observer method,
* destructor and remove method, and a linked-list reverse method)
*
* Preconditions
* -------------
* The User is only expected to press Enter to close the program's console
*
* Method Arguments
* ----------------
*	Type		Name							Description
* --------	-------------	----------------------------------------------------
* None
*
* Return Value
* ------------
*	Type								Description
* --------	--------------------------------------------------------------------
* int		Program execution status: 0 - No errors
*
* Invoked File Methods
* --------------------
*     Name								Description
* ------------	----------------------------------------------------------------
* floatRandom	Generates a random double within passed-in range
*******************************************************************************/
int main()
{
	// Constant "const" Value Declarations
	const int NO_ERRORS    =  0;		// Program Execution Status: No errors
	const int PRECISION    =  2;		// To display double fractions as .##
	const int MAX_VALUES   = 10;		// Only dealing with a small linked-list
	const double MIN_RANGE = 10.0;		// Assignment criteria for min and max
	const double MAX_RANGE = 20.0;		// values for doubles linked list values

	// Initialized Variable Declarations
	int programStatus      = NO_ERRORS;	// Assume no program execution errors
	double randomDouble    =  0.0;		// Used for generating double values
	double values[MAX_VALUES] {};		// The doubles to add to linked list
	LinkedList<double> linkedList1;		// A linked list of double type

	// Seed the random number generator; for a change of pace, using a different
	// time source for the seed
	srand(system_clock::now().time_since_epoch().count());

	// Displaying doubles, so matching the fixed precision used by LinkedList
	// toString() class method
	cout << fixed << setprecision(PRECISION);

	// Program Intro
	cout << "This program puts a linkedList UDT class through some paces\n\n"
		 << "Please note: the doubles are displayed to " << PRECISION
		 << " places, but\n"
		 << "they are randomly generated to more places.\n";

	// Challenge 3 mentions displaying a blank linked list
	cout << "\n\nCreate a linked list (of doubles).\n"
		 << "1st: " << linkedList1.toString() << endl;

	cout << "\n\nAdding " << MAX_VALUES << " random values\n";
	// Use the C++ random number generator to add 10 values to the list, in the
	// range 10.0 to 20.0. Define a method to perform this task
	for (int value = 0; value < MAX_VALUES; ++value)
	{
		randomDouble = floatRandom(MIN_RANGE, MAX_RANGE);
		// To "remember" the values added to the list
		values[value] = randomDouble;
		// Why repeat the loop just to add them to the linked list?
		linkedList1.add(randomDouble);
	}
	// Display the list using your defined class method, toString().
	cout << "1st: " << linkedList1.toString() << endl;

	// Next, create a second class object, as a copy of the first object; i.e.
	// use your defined class Copy Constructor.
	cout << "\n\nCreating a 2nd list via its Copy constructor\n";
	LinkedList<double> linkedList2(linkedList1);
	cout << "2nd: " << linkedList2.toString() << endl;

	// Pick one of the random numbers stored in the first list and remove it
	// from the second list. Display both lists.
	randomDouble = values[rand() % MAX_VALUES];
	linkedList2.remove(randomDouble);
	cout << "\n\nRemoving " << randomDouble
		 << " from the 2nd list\n"
		 << "1st: " << linkedList1.toString()
		 << "\n2nd: " << linkedList2.toString() << endl;

	// Finally, invoke your class method reverse on the first list.
	// Display both lists again.
	cout << "\n\nReversing the 1st list\n";
	linkedList1.reverse();
	cout << "1st: " << linkedList1.toString()
		 << "\n2nd: " << linkedList2.toString() << endl;

	// A bit of humor and slightly less readability to show off that the linked
	// list class is templated
	LinkedList<string> pressEnter;
	string words[]
		{"\n\n", "Press", "only", "the", "'Enter'", "key", "to", "exit", "program:"};
	for (string word : words)
	{
		pressEnter.add(word);
	}
	pressEnter.remove(words[0]);					// remove works on strings
	pressEnter.reverse();							// so does reverse
	// double-newlines work better outside the square brackets
	cout << words[0] << pressEnter.toString();

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	//cout << "\n\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()

/*******************************************************************************
* Method: floatRandom(double, double)
* 
* Method Description
* ------------------
* Generates and returns a double between the passed-in range inclusively
*
* Based on code at http://www.cplusplus.com/forum/beginner/14867/#msg72795
*
* Preconditions
* -------------
* min < max
*
* Method Arguments
* ----------------
*	Type		Name							Description
* --------	-------------	----------------------------------------------------
* double	min				Minimum value to generate a random number from
* double	max				Maximum value to generate a random number from
*
* Return Value
* ------------
*	Type								Description
* --------	--------------------------------------------------------------------
* double	The generated number between min and max
*
* Invoked File Methods
* --------------------
*     Name								Description
* ------------	----------------------------------------------------------------
* None
*******************************************************************************/
double floatRandom(double min, double max)
{
	return (rand() / (static_cast<double>(RAND_MAX) + 1.0)) * (max - min) + min;
}
