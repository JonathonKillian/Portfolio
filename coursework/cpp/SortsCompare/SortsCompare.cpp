/*******************************************************************************
* Bellevue Class: PROG-111
*           Term: Fall 2016
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
* Revision     Date                        Release Comment
* --------  ----------  --------------------------------------------------------
*   1.0     11/15/2016  Initial Release
*
* Program Inputs
* --------------
*  Device                              Description
* --------  --------------------------------------------------------------------
* Keyboard	User to press 'Enter' at program's end
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  --------------------------------------------------------------------
* Monitor   Before, after & during displays of an array of integers being
*			sorted by bubble and selection sorts
*
* File Methods
* ------------
*         Name                                Description
* --------------------	--------------------------------------------------------
* main					Program entry point method
* swap					Swap two integers
* performBubbleSort		Controls the bubble sort portion of the program
* bubbleSort			Bubble sorts an array of ints
* performSelectionSort	Controls the selection sort portion of the program
* selectionSort			Selection sorts an array of ints
* displayBanner			Displays a one-line "banner" describing the sort
* displayWithArray		Displays a small-length right-justified text & an array
*******************************************************************************/
// External Definition files
#include <iostream>		// Defines objects and classes used for stream I/O
#include <iomanip>		// For setw()
#include <cstdlib>		// For srand() and rand()
#include <ctime>		// For time()
#include <string>		// For string object & to_string()

// Namespaces utilized in this program
using namespace std;	// Announces to the compiler that members of the
						// namespace "std" are utilized in this program

// Method Prototypes
// -----------------
void swap(int &, int &);
void performBubbleSort(int[], int);
void bubbleSort(int[], int);
void performSelectionSort(int[], int);
void selectionSort(int[], int);
void displayBanner(const string &);
void displayWithArray(const string &, const int[], int);

/*******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program displays the same randomly-generated array of ints being sorted
* with a bubble sort and then with a selection sort. During the sorting, the
* partially-sorted array is displayed after each pass.
*
* Preconditions
* -------------
* User is expected to press 'Enter' to end the program (and close the window)
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  -----------------------------------------------------
*                        *** No Arguments supplied ***
*
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* int       Program execution status: 0 - No errors
*
*
* Invoked File Methods
* --------------------
*         Name                                Description
* --------------------	--------------------------------------------------------
* performBubbleSort		Controls the bubble sort portion of the program
* performSelectionSort	Controls the selection sort portion of the program
*******************************************************************************/
int main() {
	// Constant "const" Value Declarations
	const int NO_ERRORS = 0;			// Program Execution Status: No errors
	const int SIZE = 8;
	const int MIN_RAND =  1;
	const int MAX_RAND = 30;

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;		// Assume no program execution errors
	int number = 0;						// holds a random number
	int bubbles[SIZE] = {};				// The arrays for both sorts,
	int selects[SIZE] = {};				// initialized to all zeros.

	// Seed the random number generator
	srand(time(0));

	// Fill the arrays with the same random numbers.
	for (int element = 0; element < SIZE; ++element) {
		number = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
		bubbles[element] = number;
		selects[element] = number;
	}

	// Pass control to functions that handle each sorting method.
	performBubbleSort(bubbles, SIZE);
	performSelectionSort(selects, SIZE);

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\n\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()

/*******************************************************************************
* Method: swap(int &, int &)
* 
* Method Description
* ------------------
* This function swaps the values of the 2 reference arguments.
*
* Preconditions
* -------------
* None
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------   ----------------------------------------------------
* int &		first			The first number to be swapped
* int &		second			The second number to be swapped
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return anything via the return statement
*
* Invoked File Methods
* --------------------
*         Name                                Description
* --------------------	--------------------------------------------------------
* None
*******************************************************************************/
void swap(int & first, int & second) {
	int temp = first;			// A temporary int to hold one of the arguments

	// Swap the two numbers utilizing the temporary.
	first  = second;
	second = temp;
}

/*******************************************************************************
* Method: performBubbleSort(int[], int)
* 
* Method Description
* ------------------
* This function handles the bubble sorting phased of the program. It shows the
* before (unsorted) snap, runs the sort, and shows the after (sorted) snap.
*
* Preconditions
* -------------
* The size argument is assumed to not be higher than the array's length
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------   ----------------------------------------------------
* int[]		ints			The array of integers to be sorted
* int		size			The size of the ints array
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return anything
*
* Invoked File Methods
* --------------------
*         Name                                Description
* --------------------	--------------------------------------------------------
* bubbleSort			Bubble sorts an array of ints
* displayBanner			Displays a one-line "banner" describing the sort
* displayWithArray		Displays a small-length right-justified text & an array
*******************************************************************************/
void performBubbleSort(int ints[], int size) {
	// Display banner for which sort being shown.
	displayBanner("Bubble sort");

	// Display the initial unsort array
	displayWithArray("The unsorted array", ints, size);
	cout << endl;

	// Sort the array
	bubbleSort(ints, size);

	// Display the sorted array
	cout << endl;
	displayWithArray("The sorted array:", ints, size); 
}

/*******************************************************************************
* Method: bubbleSort(int[], int)
* 
* Method Description
* ------------------
* This function sorts an array of ints using the bubble sort algorithm. It also
* displays the partially-sorted array after each pass of the sort.
*
* Preconditions
* -------------
* The size argument is assumed to not be higher than the array's length
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------   ----------------------------------------------------
* int[]		ints			The array of integers to be sorted
* int		size			The size of the ints array
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return anything
*
* Invoked File Methods
* --------------------
*         Name                                Description
* --------------------	--------------------------------------------------------
* swap					Swap two integers
* displayWithArray		Displays a small-length right-justified text & an array
*******************************************************************************/
void bubbleSort(int ints[], int size) {
	// Can't iterate over the last array element since we compare current
	// element to the next one.
	int end = size - 1;
	int pass = 0;						// Used for printing at bottom of loop
	bool swapped = false;				// Used to stop iterating.

	do {
		// Start out that there are no swaps
		swapped = false;

		// iterate through the array, moving larger elements along
		for (int element = 0; element < end; ++element) {
			if (ints[element] > ints[element + 1]) {
				swap(ints[element], ints[element + 1]);
				swapped = true;
				//cout << "Moved " << ints[element] << endl;	// Diagnostic
			}
		}

		// Show the progress
		displayWithArray("After pass #" + to_string(++pass), ints, size);
	} while (swapped);
}

/*******************************************************************************
* Method: performSelectionSort(int[], int)
* 
* Method Description
* ------------------
* This function handles the selection sorting phased of the program. It shows
* the before (unsorted) snap, runs the sort, and shows the after (sorted) snap.
*
* Preconditions
* -------------
* The size argument is assumed to not be higher than the array's length
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------   ----------------------------------------------------
* int[]		ints			The array of integers to be sorted
* int		size			The size of the ints array
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return anything
*
* Invoked File Methods
* --------------------
*         Name                                Description
* --------------------	--------------------------------------------------------
* selectionSort			Selection sorts an array of ints
* displayBanner			Displays a one-line "banner" describing the sort
* displayWithArray		Displays a small-length right-justified text & an array
*******************************************************************************/
void performSelectionSort(int ints[], int size) {
	// Display banner for which sort being shown.
	displayBanner("Selection sort");

	// Display the initial unsort array
	displayWithArray("The unsorted array", ints, size);
	cout << endl;

	// Sort the array
	selectionSort(ints, size);

	// Display the sorted array
	cout << endl;
	displayWithArray("The sorted array:", ints, size);
	cout << endl;
}

/*******************************************************************************
* Method: selectionSort(int[], int)
* 
* Method Description
* ------------------
* This function sorts an array of ints using the selection sort algorithm.
* It also displays the partially-sorted array after each pass of the sort.
*
* Preconditions
* -------------
* The size argument is assumed to not be higher than the array's length
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------   ----------------------------------------------------
* int[]		ints			The array of integers to be sorted
* int		size			The size of the ints array
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return anything
*
* Invoked File Methods
* --------------------
*         Name                                Description
* --------------------	--------------------------------------------------------
* swap					Swap two integers
* displayWithArray		Displays a small-length right-justified text & an array
*******************************************************************************/
void selectionSort(int ints[], int size) {
	int pass = 0;						// Used for printing at bottom of loop
	int lowest = 0;
	int end = size - 1;

	// Iterate through the array to establish a starting lowest
	for (int start = 0; start < end; ++start) {
		// Remember the current lowest
		lowest = start;
		//cout << "Starting pass with " << ints[lowest] << " as lowest\n";

		// Iterate through the remaining array looking for a lower value
		for (int element = start + 1; element < size; ++element) {
			// Do we have a new lowest?
			if (ints[element] < ints[lowest]) {
				// Remember the new lowest
				lowest = element;
				//cout << ints[lowest] << " is now lowest\n";
			}
		}

		// Swap the lowest to the current start of the pass
		swap(ints[start], ints[lowest]);
		//cout << "Moved " << ints[start] << endl;

		// Show the progress
		displayWithArray("After pass #" + to_string(++pass), ints, size);
	}
}

/*******************************************************************************
* Method: displayBanner(const string &)
* 
* Method Description
* ------------------
* Displays a simplistic one-line "banner."
*
* Preconditions
* -------------
* The size of banner is small enough to prevent wrap-around on the screen.
*
* Method Arguments
* ----------------
*      Type			 Name						Description
* --------------	------	----------------------------------------------------
* const string &	banner	The string holding the main part of the banner
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return anything
*
* Invoked File Methods
* --------------------
*         Name                                Description
* --------------------	--------------------------------------------------------
* None
*******************************************************************************/
void displayBanner(const string & banner) {
	const int COUNT = 7;
	const char DASH = '-';
	
	string dashes(COUNT, DASH);

	cout << "\n\n " << dashes << " " << banner << " " << dashes << "\n\n\n";
}

/*******************************************************************************
* Method: displayWithArray(const string &, const int[], int)
* 
* Method Description
* ------------------
* Displays a reason why to show the array, right-justified, and an array.
*
* Due to the multiple places this function is called, and that it is specialized
* to this program, there are constants defined here in place of passing them
* through other functions or leaving them in global space.
*
* Preconditions
* -------------
* The size argument is assumed to not be higher than the array's length
*
* Method Arguments
* ----------------
*      Type			 Name						Description
* --------------	------	----------------------------------------------------
* const string &	preface	The string holding the first part of the line
* const int[]		ints	The array to be displayed
* int				size	The size of the ints array.		
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return anything
*
* Invoked File Methods
* --------------------
*         Name                                Description
* --------------------	--------------------------------------------------------
* None
*******************************************************************************/
void displayWithArray(const string & preface, const int ints[], int size) {
	const int PREFACE_WIDTH = 20;
	const int ELEMENT_WIDTH =  2;

	int element = 0;	// Arrays start at 0

	cout << right << setw(PREFACE_WIDTH) << preface << ": {";

	if (size > 0) {
		// Display first element
		cout << setw(ELEMENT_WIDTH) << ints[element];
		
		// Display the rest of the element with separators
		for (element = 1; element < size; ++element)
			cout << ", " << setw(ELEMENT_WIDTH) << ints[element];
	}

	cout << "}\n";
}
