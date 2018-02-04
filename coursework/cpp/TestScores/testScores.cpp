/*******************************************************************************
* Bellevue Class: PROG-111
*           Term: Fall 2016
*     Instructor: Robert Main
*
* Solution/Project Name: KillianProject10/KillianProject10
*             File Name: KillianProject10.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
* Programmer: Jon Killian
*
* Assigned Project Number: 10
*
*
* Revision     Date                        Release Comment
* --------  ----------  --------------------------------------------------------
*   1.0     12/01/2016  Initial Release
*
* Program Inputs
* --------------
*  Device                              Description
* --------  --------------------------------------------------------------------
* Keyboard  User to enter a count of scores to input, the scores and the student
*           names associated with the scores. User to also press 'Enter' to
*           exit the program
*
* Program Outputs
* ---------------
*  Device                            Description
* --------  --------------------------------------------------------------------
* Monitor   Introduction, multiple prompts, a sorted list of students and test
*           scores, plus their average.
*
* ADTs (Abstract Data Types) Utilized
* -----------------------------------
*       Name                               Description
* ----------------  ------------------------------------------------------------
* StudentScore      Struct that holds a student's name and test score.
*
* File Methods
* ------------
*     Name                             Description
* ------------  ----------------------------------------------------------------
* main			Program entry point method
* displayIntro	Displays the program's introduction
* getScores		Handles the collecting of student names and scores.
* promptUser	Displays a prompt and waits for User's input in form of an int
* promptUser	Displays a prompt and waits for User's input in form of a string
* selectSort	Sorts an array using selection sort.
* calcAverage	Calculates the average of an array of scores.
* sumScores		Sums the scores collected in the StudentScore array
* displayArray	Displays an array of structs holding names and scores
* streamEmpty	Does the input stream buffer have extra characters in it?
* resetStream	Place input stream in good state and empty the input buffer.
*******************************************************************************/
// External Definition files
#include <iostream>         // Defines objects and classes used for stream I/O
#include <iomanip>			// For stream manipulators (setw)
#include <string>			// For string object and getline()
#include "studentScore.h"	// Include your UDT class header file(s) here

// Namespaces utilized in this program
using namespace std;        // Announces to the compiler that members of the
                            // namespace "std" are utilized in this program

// Method Prototypes
// -----------------
void displayIntro();
void getScores(StudentScore *, int, int, int);
int promptUser(const string &, int, int);
string promptUser(const string &);
void selectSort(StudentScore *, int);
double calcAverage(const StudentScore * const, int);
int sumScores(const StudentScore * const, int);
void displayArray(const StudentScore * const, int);
bool streamEmpty();
void resetStream();

/*******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program allows dynamic entry of student names and test scores, plus
* sorting averaging and then displaying said names, scores and average.
*
* Preconditions
* -------------
* User expected to press 'Enter' to exit the program
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
*     Name                             Description
* ------------  ----------------------------------------------------------------
* displayIntro	Displays the program's introduction
* getScores		Handles the collecting of student names and scores.
* promptUser	Displays a prompt and waits for User's input in form of an int
* selectSort	Sorts an array using selection sort.
* calcAverage	Calculates the average of an array of scores.
* displayArray	Displays an array of structs holding names and scores
* resetStream	Place input stream in good state and empty the input buffer.
*******************************************************************************/
int main()
{
	// Constant "const" Value Declarations
	const int NO_ERRORS   =   0;		// Program Execution Status: No errors
	const int MIN_ENTRIES =   5;		// Minimum number of test scores
	const int MAX_ENTRIES =  20;		// Maximum number of test scores
	const int MIN_SCORE   =   0;		// Minimum test score
	const int MAX_SCORE   = 100;		// Maximum test score

	// Initialized Variable Declarations
	int programStatus = NO_ERRORS;		// Assume no program execution errors

	// Introduce the program to the User
	displayIntro();

	// Get number of students with test scores to be inputted (5-20)
	int scoreCount = promptUser("How many test scores to enter",
		MIN_ENTRIES, MAX_ENTRIES);

    // Dynamically allocate an array of structs to hold the requisite entries.
	StudentScore * scores = new StudentScore[scoreCount];

    // Get the names and scores of the students
	getScores(scores, scoreCount, MIN_SCORE, MAX_SCORE);

    // Calculate the average of the test scores
	double average = calcAverage(scores, scoreCount);

    // Sort the entries by score, then name where needed, in ascending order
	selectSort(scores, scoreCount);

    // Display the sorted names and test scores, plus the average
	displayArray(scores, scoreCount);
	cout << "\n\nThe average test score is " << average << endl;

	// Release the allocated memory
	delete[] scores;
	scores = 0;

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	resetStream();
	cout << "\n\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()

/******************************************************************************
* Method: displayIntro()
* 
* Method Description
* ------------------
* Displays an introduction about the program and what the user can expect to
* input.
*
* Preconditions
* -------------
* None
* 
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------   ---------------------------------------------------
*                        *** No Arguments supplied ***
*
* Return Value
* ------------
*   Type                              Description
* --------  -------------------------------------------------------------------
* void		The function does not return a value.
*
* Invoked File Methods
* --------------------
*     Name                             Description
* -------------------	-------------------------------------------------------
* None
*******************************************************************************/
void displayIntro()
{
	cout << "\nTest Score Average Calculator\n\n"
		 << "This program will accept a variable "
		 << "list of student names and their test score\n"
		 << "from a recent test. It will then display them "
		 << "in sorted order and displayed the\n"
		 << "average for the test.\n\n"
		 << "The numeric inputs are whole numbers; "
		 << "however, the average will display a\n"
		 << "fraction when needed.\n\n";
}

/*******************************************************************************
* Method: getScores(StudentScore *, int, int, int)
*
* Method Description
* ------------------
* Provided an empty array and the count of scores to collect, prompts for and
* obtains the names and scores from the User.
*
* Preconditions
* -------------
* min is assumed less than max
*
* Method Arguments
* ----------------
*   Type			 Name						Description
* --------------	------	----------------------------------------------------
* StudentScore *	scores	Const pointer to const array holding test scores
* int				size	The number of entries in the passed in array
* int				min		The minimally inclusive valid input
* int				max		The maximally inclusive valid input
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return a value
*
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ----------	----------------------------------------------------------------
* promptUser	Displays a prompt and waits for User's input in form of an int
* promptUser	Displays a prompt and waits for User's input in form of a string
*******************************************************************************/
void getScores(StudentScore * scores, int size, int min, int max)
{
	string name("");

	for (int offset = 0; offset < size; ++offset)
	{
		cout << endl;		// Add blank line for readibility

		// Saving to temp string as name is used in second prompt
		name = promptUser(
			"Enter student #" + to_string(offset + 1) + "'s name");

		// Save it to the array
		(scores + offset)->name = name;

		// Prompt for and save to array the score.
		(scores + offset)->score = 
			promptUser("Enter " + name + "'s score", min, max);
	}
}

/*******************************************************************************
* Method: promptUser(string, int, int)
*
* Method Description
* ------------------
* Prompt the User for an int value and validates it is an int within the
* passed-in range
*
* Preconditions
* -------------
* min is assumed less than max
* User is expected to enter an int (int input)
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------	-------------	----------------------------------------------------
* string    prompt          The prompt to display to User
* int		min				The minimally inclusive valid input
* int		max				The maximally inclusive valid input
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* int       The validated User input
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ------------	----------------------------------------------------------------
* streamEmpty   Does the input stream buffer have extra characters in it
* resetStream   Place input stream in good state and empty the input buffer.
*******************************************************************************/
int promptUser(const string & prompt, int min, int max)
{
	int input = 0;
	bool askAgain = true;

	do
	{
		// Display prompt with the valid input range & get the User's input
		cout << prompt << " (" << min << '-' << max << "): ";
		cin  >> input;

		// Validate the input
		if (!cin ||									// Non-numeric
			!streamEmpty() ||						// Non-integer
			input < min || input > max)				// Out of range
		{
			// Clear the error and buffer for the input stream
			resetStream();

			// Inform the User of the invalid input
			cout << "Please enter a whole number within range.\n";
		}
		else
		{
			askAgain = false;						// break out of the loop
		}
	} while (askAgain);

	// Return the User's now validated input
	return input;
}

/*******************************************************************************
* Method: promptUser(string)
*
* Method Description
* ------------------
* This program allows dynamic entry of student names and test scores, sorting
* averaging and then displaying said names, scores and average.
*
* Preconditions
* -------------
* User is expected to input something (string input),
* albeit they can give just whitespace.
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------	-------------	----------------------------------------------------
* string    prompt          The prompt to display to User
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* string	The User input
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ------------	----------------------------------------------------------------
* resetStream   Place input stream in good state and empty the input buffer.
*******************************************************************************/
string promptUser(const string & prompt)
{
	string input("");

	// Make sure the input stream is good and empty; getline() gets tripped up
	// on left-in Enters
	resetStream();

	do
	{
		// Display the passed in prompt and collect User's input.
		// No valid range to include in the prompt.
		cout << prompt << ": ";
		getline(cin, input);

		// Validate the User typed in something
		if (input.empty())
		{
			cout << "Please supply an entry.\n";
		}
	} while (input.empty());

	// Return the User's now validated input
	return input;
}

/*******************************************************************************
* Method: selectSort(StudentScore *, int)
*
* Method Description
* ------------------
* Sort by score, via selection sort, the passed in array of StudentScore's
* For multiples of the same score, sort by name.
*
* Preconditions
* -------------
* None
*
* Method Arguments
* ----------------
*   Type			 Name						Description
* --------------	------	----------------------------------------------------
* StudentScore *	scores	Const pointer to const array holding test scores
* int				size	The number of entries in the passed in array
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return a value
*
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ------------  ----------------------------------------------------------------
* None
*******************************************************************************/
void selectSort(StudentScore * scores, int size)
{
	int lowest = 0;
    int end    = size - 1;				// For outer loop

	// Iterate up to, but not including, the last element of the passed in array
	for (int start = 0; start < end; ++start)
	{
		// Remember the current lowest
		lowest = start;

		// Iterate through the remaining array looking for a lower value
		for (int offset = start + 1; offset < size; ++offset)
		{
			// Do we have a new lower score? or if the score matches the current
			// lowest, do we have a "smaller" name (A before b, etc.)
			if (((scores + offset)->score <  (scores + lowest)->score) ||
				((scores + offset)->score == (scores + lowest)->score &&
				 (scores + offset)->name  <  (scores + lowest)->name))
			{
				// Remember the new lowest
				lowest = offset;
			}
		}

		// Swap the lowest to the current start of the pass
		(scores + start)->swap((scores + lowest));
	}
}

/*******************************************************************************
* Method: calcAverage(const StudentScore * const, int)
*
* Method Description
* ------------------
* Calculate the average of the array of scores.
*
* If a size of zero, passed-in array is empty, a zero is passed out.
*
* Preconditions
* -------------
* None
*
* Method Arguments
* ----------------
*   Type			 Name						Description
* --------------	------	----------------------------------------------------
* StudentScore *	scores	Const pointer to const array holding test scores
* int				size	The number of entries in the passed in array
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* double	The average of the scores in the passed in array
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ------------  ----------------------------------------------------------------
* sumScores		Sums the scores contained in the passed in array.
*******************************************************************************/
double calcAverage(const StudentScore * const scores, int size)
{
	double average = 0.0;

	// If we've an array, or in other words, no divide by 0
	if (size > 0)
	{
		// Accumulate the sum and calculate average
		average = sumScores(scores, size) / static_cast<double>(size);
	}

	return average;
}

/*******************************************************************************
* Method: sumScores(const StudentScore * const, int)
*
* Method Description
* ------------------
* Sum up all the scores in the passed-in array.
*
* If an empty array is passed in, a zero is passed out.
*
* Preconditions
* -------------
* None
*
* Method Arguments
* ----------------
*   Type			 Name						Description
* --------------	------	----------------------------------------------------
* StudentScore *	scores	Const pointer to const array holding test scores
* int				size	The number of entries in the passed in array
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* int		The accumulated total of all the scores in the passed-in array
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ------------  ----------------------------------------------------------------
* None
*******************************************************************************/
int sumScores(const StudentScore * const scores, int size)
{
	int sum = 0;

	// Sum up all the scores.
	for (int offset = 0; offset < size; ++offset)
	{
		sum += (scores + offset)->score;
	}

	return sum;
}
	
/*******************************************************************************
* Method: displayArray(const StudentScore * const, int)
*
* Method Description
* ------------------
* Print the array of student names and scores in column-fashion. Name is second
* column as it has greater variance in width.
*
* Note: an empty array will still print the column headers.
*
* Preconditions
* -------------
* None
*
*
* Method Arguments
* ----------------
*   Type			 Name						Description
* --------------	------	----------------------------------------------------
* StudentScore *	scores	Const pointer to const array holding test scores
* int				size	The number of entries in the passed in array
*
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return a value
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ------------  ----------------------------------------------------------------
* None
*******************************************************************************/
void displayArray(const StudentScore * const scores, int size)
{
	const int WIDTH_SCORE = 7;
	const int WIDTH_GAP   = 2;
	const char CHAR_GAP   = ' ';

	string columnGap(WIDTH_GAP, CHAR_GAP);

	// Display column header
	cout << "\n\n"
		 << setw(WIDTH_SCORE) << "Score" << columnGap << "Student\n"
		 << setw(WIDTH_SCORE) << "-----" << columnGap << "-------\n";

	// Display the array, one entry per line
	for (int offset = 0; offset < size; ++offset)
	{
		cout << setw(WIDTH_SCORE) << (scores + offset)->score
			 << columnGap         << (scores + offset)->name
			 << endl;
	}
}

/*******************************************************************************
* Method: streamEmpty()
*
* Method Description
* ------------------
* Reports back if the input buffer is "empty," making an allowance for the
* 'Enter' normally left.
*
* Preconditions
* -------------
* The input stream is assumed in good state
*
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  -----------------------------------------------------
*                        *** No Arguments supplied ***
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* bool		True if there is no other characters beside the 'Enter'
*
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ------------  ----------------------------------------------------------------
* None
*******************************************************************************/
bool streamEmpty()
{
	const int MIN_BUFFER = 1;	// Account for the Enter key

	return cin.rdbuf()->in_avail() <= MIN_BUFFER;
}

/*******************************************************************************
* Method: resetStream()
*
* Method Description
* ------------------
* Restores the input stream (cin) to a good state and empties the input buffer.
*
* Preconditions
* -------------
* None
*
* Method Arguments
* ----------------
*   Type        Name                        Description
* --------  -------------  -----------------------------------------------------
*                        *** No Arguments supplied ***
*
* Return Value
* ------------
*   Type                              Description
* --------  --------------------------------------------------------------------
* void		This function does not return a value
*
*
* Invoked File Methods
* --------------------
*     Name                             Description
* ------------  ----------------------------------------------------------------
* None
*******************************************************************************/
void resetStream()
{
	// Make sure stream is in good state so we can read from it.
	cin.clear();

	// Read and discard all the remaining characters in the input buffer.
	cin.ignore(cin.rdbuf()->in_avail());
}
