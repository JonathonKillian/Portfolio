/*******************************************************************************
* Bellevue Class: PROG-113
*           Term: Spring 2017
*     Instructor: Robert Main
*
* Solution/Project Name: KillianProject5/KillianProject5
*             File Name: punchline.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
*
* Programmer: Jon Killian
*
* Assigned Project Number: 5
*
*
* Revision	   Date							Release Comment
* --------	----------	--------------------------------------------------------
*	1.0		05/03/2017	Initial Release
*
* Program Inputs
* --------------
*  Device								Description
* --------	--------------------------------------------------------------------
* Keyboard	User supplies 2 filenames & an Enter at program's end
* ifstream	2 files to be read in
*
* Program Outputs
* ---------------
*  Device								Description
* --------	--------------------------------------------------------------------
* Monitor	The full contents of th 1st file & last line of the 2nd file.
*
* File Methods
* ------------
*     Name								Description
* ------------	----------------------------------------------------------------
* main          Program entry point method
* printAllLines	Prints all the lines read from the passed-in ifstream
* printLastLine	Prints the last line of the file 
* getFile		Prompts User for a filename and returns the opened file stream
*******************************************************************************/
// External Definition files
#include <iostream>			// Defines objects and classes used for stream I/O
#include <fstream>			// For ifstream class object for file reading
#include <string>			// For string class object

// Namespaces utilized in this program
using namespace std;		// Announces to the compiler that members of the
							// namespace "std" are utilized in this program

// Method Prototypes
// -----------------
void printAllLines(ifstream &);
void printLastLine(ifstream &);
ifstream getFile(const string & filetype);

/*******************************************************************************
* Method: main()
* 
* Method Description
* ------------------
* This program will print a joke, minus its punchline, from one file and then
* print the punchline from a second file, where it is stored as the last line
* after "garbage" lines.
*
* Preconditions
* -------------
* None
*
* Method Arguments
* ----------------
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
* -------------	----------------------------------------------------------------
* printAllLines	Prints all the lines read from the passed-in ifstream
* printLastLine	Prints the last line of the file 
* getFile		Prompts User for a filename and returns the opened file stream
*******************************************************************************/
int main()          
{
	// Constant "const" Value Declarations
	const int NO_ERRORS   = 0;			// Program Execution Status: No errors

	int programStatus = NO_ERRORS;		// Assume no program execution errors

	// Intro
	cout << "\nThis program will display a joke read from two files, where the "
		 << "first holds all\n"
		 << "but the punchline and the second holds the punchline as the last "
		 << "of multiple\n"
		 << "lines.\n";

	// Get and open files (Combined only for validation)
	ifstream jokeStream = getFile("joke");
	ifstream punchlineStream = getFile("punchline");

	// Both files are open, proceed to read them
	cout << "\nTelling the joke (don't shoot the messenger!)\n\n";
	printAllLines(jokeStream);
	printLastLine(punchlineStream);

	// Play nice and close the filestreams
	jokeStream.close();
	punchlineStream.close();

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\n\nTh-th-th-that's all, folks! -- Porky Pig\n"
		 << "Press Enter to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()

/*******************************************************************************
* Method: printAllLines(ifstream &)
* 
* Method Description
* ------------------
* Reads a file via input stream and outputs it to screen
*
* Preconditions
* -------------
* The input filestream is expected to already be opened.
* The calling function will account for any stream conditions and close it
*
* Method Arguments
* ----------------
*	Type		Name							Description
* --------	-------------	----------------------------------------------------
* ifstream&	file			The file input stream, already opened
*
* Return Value
* ------------
*	Type								Description
* --------	--------------------------------------------------------------------
* void		This function does not return a value
*
* Invoked File Methods
* --------------------
* None
*******************************************************************************/
void printAllLines(ifstream & file)
{
	string line("");

	// Make sure the stream is in a good state and at start of file
	file.clear();
	file.seekg(0); //, ios::beg);

	// Chances should be slim that the seekg failed, but just to cover the bases
	if (file)
	{
		// Just loop through every line in the file, outputting them to console
		while (getline(file, line))
		{
			cout << line << endl;
		}
	}
	else
	{
		file.clear();
		cout << "Unable to read from the joke file.\n"
			 << "(Only wish that WAS the joke; it's an error)\n";
	}
}

/*******************************************************************************
* Method: printLastLine(ifstream &)
* 
* Method Description
* ------------------
* Jumps to end of file and searches backwards for the beginning of the last
* line, which it then outputs.
*
* Preconditions
* -------------
* The input filestream is expected to already be opened.
* The last line is not terminated with a newline.
* There is more than 1 line in the file
* The calling function will close the stream.
*
* Method Arguments
* ----------------
*	Type		Name							Description
* --------	-------------	----------------------------------------------------
* ifstream&	file			The file input stream, already opened
*
* Return Value
* ------------
*	Type								Description
* --------	--------------------------------------------------------------------
* void		This function does not return a value
*
* Invoked File Methods
* --------------------
* None
*******************************************************************************/
void printLastLine(ifstream & file)
{
	const int NEWLINE_LENGTH = 2;		// Written to file as "\r\n"
	const int PREVIOUS_CHAR = -1;

	char checkChar = '\0';

	// Make sure the stream is in a good state
	file.clear();

	// Seek to file's last character
	file.seekg(PREVIOUS_CHAR, ios::end);

	// Starting with the last character, move back one character until a newline
	// is reached.
	checkChar = file.peek();

	// First, make sure the last character(s) is not a new line
	if (checkChar == '\n')
	{
		// It is, back up one more (it'll already be on the 1st character of the
		// newline)
		file.seekg(PREVIOUS_CHAR, ios::cur);
		// And load the new "current" character into the check var
		checkChar = file.peek();
	}

	// Now proceed through the characters backwards until a newline, or begin
	// of file is found, whichever is found first.
	// Note, if the only thing in the punchline was a newline, the filestream is
	// not in good condition and should skip the while loop
	while (file.tellg() > 0 && checkChar != '\n')
	{
		if (!file.seekg(PREVIOUS_CHAR, ios::cur))
		{
			// Shouldn't get an error here; break out of the loop
			break;
		}
		checkChar = file.peek();
	}

	// At this point, the filestream should be sitting at the beginning of the
	// last line; however, it also could be in a failed state
	if (file)
	{
		string line("");

		// File stream could be at beginning of file where they may not be a
		// newline; so check once to see if we need to jump past it.
		if (checkChar == '\n')
		{
			file.seekg(NEWLINE_LENGTH, ios::cur);
		}

		getline(file, line);
		cout << line << std::endl;
	}
	else
	{
		file.clear();
		cout << "Unable to read from the punchline file.\n"
			 << "(This is an error and not the punchline)\n";
	}
}

/*******************************************************************************
* Method: getFile(const string & filetype)
* 
* Method Description
* ------------------
* Prompts the user for a file name, based on the short type descriptor passed in
* and validates it by opening the file.
*
* Preconditions
* -------------
* User is assumed to enter a valid filename located in current directory
* The calling function will close the stream.
*
* Method Arguments
* ----------------
*	Type		Name							Description
* --------	-------------	----------------------------------------------------
* string &	filetype		(const) What type of file to open (e.g. joke)
*
* Return Value
* ------------
*	Type								Description
* --------	--------------------------------------------------------------------
* ifstream	The open input file stream
*
* Invoked File Methods
* --------------------
* None
*******************************************************************************/
ifstream getFile(const string & filetype)
{
	// Reason "short" is mentioned, the passed-in string is inserted twice into
	// the prompt
	string prompt("\nPlease enter the name of the " + filetype + " file\n" +
		" (e.g., " + filetype + ".txt): ");
	string filename("");
	ifstream file("");
	bool askAgain = true;

	do
	{
		// Prompt the User
		cout << prompt;
		getline(cin, filename);

		// Validate User's filename
		file.open(filename);
		if (file)
		{
			askAgain = false;		// A valid filename; end the loop
		} else {
			cout << "Unable to open " << filename
				 << ". Please verify the name and try again.\n";
		}
	} while (askAgain);

	return file;
}
