/*******************************************************************************
* Bellevue Class: PROG-113
*           Term: Spring 2017
*     Instructor: Robert Main
*
* Solution/Project Name: KillianProject7
*             File Name: KillianProject7.cpp
*
* This file defines the entry point method, main(), for a C++ Console
* application. When the executable file is selected for execution, the OS
* will transfer execution to the first line of code in method main(). Other
* methods called from main() may be defined here as well.
*
*
* Programmer: Jon Killian
*
* Assigned Project Number: 7
*
*
* Revision	   Date							Release Comment
* --------	----------	--------------------------------------------------------
*	1.0		05/23/2017	Initial Release
*
* Program Inputs
* --------------
*  Device								Description
* --------	--------------------------------------------------------------------
* Keyboard	User presses Enter to close program window
*
* Program Outputs
* ---------------
*  Device								Description
* --------	--------------------------------------------------------------------
* Monitor	Results of 2 sorting algorithms
*
* UDT Classes Utilized
* --------------------
*     Name                             Description
* ------------  --------------------------------------------------------------
* AbstractSort	Base class: Defining sort functions, including counting compares
* SelectionSort	Sub class:  Implementing Selection sort
* QuickSort		Sub class:  Implementing QuickSort
*
* File Methods
* ------------
*     Name								Description
* -----------------------	----------------------------------------------------
* main          			Program entry point method
* testSort					Tests the derived classes
* isSorted					Returns whether the array is sorted.
* showArray(int[],int)		"Converts" an array to string for displaying.
*******************************************************************************/
// External Definition files
#include <iostream>			// Defines objects and classes used for stream I/O
#include <cstdlib>			// For srand() and rnad()
#include <ctime>			// for time()
#include <sstream>			// for ostringstream()
#include <string>			// for string class

// Namespaces utilized in this program
using namespace std;		// Announces to the compiler that members of the
							// namespace "std" are utilized in this program

/*******************************************************************************
*      Class: AbstractSort
* Base Class: None
*
* Programmer: Jon Killian
*
* Revision	   Date							Release Comment
* --------	----------	--------------------------------------------------------
*	1.0		05/24/2017	Initial Release
*
* Class Description
* -----------------
* This abstract base class defines the public and protected interfaces for
* sorting sub-classes and allows tracking of the number of compares performed by
* the sub-classes sorting method.
*
* This class cannot be instantiated by itself, it has a purely virtual method
*
* --------------------------- Public Methods Interface -------------------------
*       Method                              Description
* ------------------	--------------------------------------------------------
* sort(int[],int)		Purely virtual method, is the primary method for sorting
* getCount()			Returns the count of compares performed during sorting
*
* ------------------------------ Protected Methods -----------------------------
*		Method								Description
* ------------------	--------------------------------------------------------
* clearCount()			Clears the compare count
* compare(int,int)		Returns -1/0/1 for </=/>, incrementing the compare count
* copyArray(int[],int)	Saves an array to class member array
* swapElements(int,int)	Swaps the values of 2 class memeber array elements
*
* --------------------- Private Data Members (static Const) --------------------
*  Type			Name						Description
* ------	------------	----------------------------------------------------
* None
*
* ---------------------- Private Data Members (Non-static) ---------------------
*  Type			Name						Description
* ------	------------	----------------------------------------------------
* int		compareCount	Count of compares
*******************************************************************************/
class AbstractSort
{
public:

	// Public mutators
	virtual int * sort(int [], int) = 0;	// Sub-class required to define

	// Public observers
	int getCount() const;					// Return the number of comparisons

protected:
	int * sortArray;						// Array to sort (filled in sort())

	// Protected mutators
	void clearCount();						// Resets the comparsion count
	int compare(int, int);					// Returns -1/0/1 for </=/>
	// Helper function for derived classes to save their array arguments
	void copyArray(const int [], int);		// Copies passed-in array to member
	void swapElements(int , int);			// Swap elements in array

private:
	int compareCount;
};

/*******************************************************************************
*
* Methods: Public Mutators
*
*******************************************************************************/

/***************
* Method:		clearCount()
* Description:	Clears the count of comparisons to zero for new sorts
*
* Input(s):		None
*
* Output(s):	(void)
****************/
void AbstractSort::clearCount()
{
	compareCount = 0;
}

/*******************************************************************************
*
* Methods: Public Observers
*
*******************************************************************************/

/***************
* Method:		getCount() const
* Description:	Returns the comparison counts
*
* Input(s):		None
*
* Output(s):	(int) compareCount
****************/
int AbstractSort::getCount() const
{
	return compareCount;
}

/*******************************************************************************
*
* Methods: Protected Mutators/Helper functions
*
*******************************************************************************/

/***************
* Method:		compare()
* Description:	Returns an integer representation of less than (-1), equals (0)
*				or greater than (+1). It also keeps track of how many times it
*				was called.
*
* Input(s):		int left	(lefthand-side of the compare)
*				int right	(righthand-side of the compare)
*
* Output(s):	(int)		(-1/0/1 representing </=/> comparison results)
****************/
int AbstractSort::compare(int left, int right)
{
	const int LESS    = -1;
	const int EQUAL   =  0;
	const int GREATER =  1;

	int result = EQUAL;						// Prime for equal

	++compareCount;							// Track the compares
	if (left < right)						// Adjust the return result based
	{										// on the resulting comparison
		result = LESS;
	}
	else if (left > right)
	{
		result = GREATER;
	}

	return result;
}

/***************
* Method:		copyArray()
* Description:	Copies, element by element, the array passed in (which is passed
*				in to swap() which calls this method) to the class member array
*
* Input(s):		int arr[]	(Source/original array)
*				int size	(how large is the original array)
*
* Output(s):	(void)
****************/
void AbstractSort::copyArray(const int arr[], int size)
{
	for (int index = 0; index < size; ++index)
	{
		sortArray[index] = arr[index];
	}
}

/***************
* Method:		swapElements()
* Description:	Swaps the contents of 2 class member array elements.
*
*				As the array is a class member, this method only needs to know
*				the element indexes to perform the swap
*
* Input(s):		int left		(lefthand side of the swap)
*				int right		(righthand side of the swap)
*
* Output(s):	(void)
****************/
void AbstractSort::swapElements(int left, int right)
{
	int temp = sortArray[left];

	sortArray[left]  = sortArray[right];
	sortArray[right] = temp;
}

/*******************************************************************************
*      Class: SelectionSort
* Base Class: AbstractSort
*
* Programmer: Jon Killian
*
* Revision	   Date							Release Comment
* --------	----------	--------------------------------------------------------
*	1.0		05/24/2017	Initial Release
*
* Class Description
* -----------------
* This class is used to track how many comparisons are performed utilizing a
* selection sort algorithm.
*
* --------------------------- Public Methods Interface -------------------------
*       Method                              Description
* ------------------	--------------------------------------------------------
* ~SelectionSort()		Class destructor; frees dynamically allocated memory
* sort(int[],int)		Sorts array using a selection sort algorithm
*
* --------------------------------- Private Methods ----------------------------
*       Method                              Description
* ------------------	--------------------------------------------------------
* None
*
* --------------------- Private Data Members (static Const) --------------------
*  Type			Name						Description
* ------	------------	----------------------------------------------------
* None
*
* ---------------------- Private Data Members (Non-static) ---------------------
*  Type			Name						Description
* ------	------------	----------------------------------------------------
* None
*******************************************************************************/
class SelectionSort : public AbstractSort
{
public:
	// Constructors: not used

	// Desctructor: Frees the memory requested in sort()
	~SelectionSort();

	// Public mutators

	// Base class defines this as pure virtual, it must be created in this class
	virtual int * sort(int [], int);
};

/*******************************************************************************
*
* Constuctors & Destructor
*
*******************************************************************************/

/***************
* Method:		Destructor
* Description:	Frees any dynamically acquired resources
*
* Input(s):		None
*
* Output(s):	None
****************/
SelectionSort::~SelectionSort()
{
	if (sortArray != nullptr)
	{
		// Release the memory requested in sort()
		delete [] sortArray;
	}
}

/*******************************************************************************
*
* Methods: Public Mutators
*
*******************************************************************************/

/***************
* Method:		sort()
* Description:	Sorts the array using a selection sort algorithm and using the
*				base class compare method (to count the number of compares)
*
*				Note, the base class holds the class member sortArray
*
* Input(s):		int arr[]	Array to be sorted
*				int size	Size of the array to be sorted
*
* Output(s):	(int *)		Pointer to the sorted array
****************/
int * SelectionSort::sort(int arr[], int size)
{
	// As the current element is compared to its next; don't allow end to become
	// the current
	int end = size - 1;
	int lowest = 0;									// Track the lowest element

	// Make a local copy of the array to sort on
	sortArray = new int[size];						// Defined in base class
	copyArray(arr, size);

	clearCount();									// Reset count for new run
	for (int start = 0; start < end; ++start)
	{
		lowest = start;								// Reset lowest value

		// Iterate through the remaining array looking for a lower value
		for (int element = start + 1; element < size; ++element)
		{
			// Track the lowest value
			if (compare(sortArray[element], sortArray[lowest]) < 0)
			{
				lowest = element;
			}
		}

		// Swap lowest value down to its "proper" place
		swapElements(start, lowest);
	}

	return sortArray;								// Return the sorted array
}

/*******************************************************************************
*      Class: QuickSort
* Base Class: AbstractSort
*
* Programmer: Jon Killian
*
* Revision	   Date							Release Comment
* --------	----------	--------------------------------------------------------
*	1.0		05/24/2017	Initial Release
*
* Class Description
* -----------------
* This class is used to track how many comparisons are performed utilizing a
* quicksort algorithm.
*
* --------------------------- Public Methods Interface -------------------------
*       Method                              Description
* ------------------	--------------------------------------------------------
* ~QuickSort()			Class destructor; frees dynamically allocated memory
* sort(int[],int)		Sorts array using a quicksort algorithm
*
* --------------------------------- Private Methods ----------------------------
*       Method                              Description
* ------------------	--------------------------------------------------------
* qSort					Recursive helper function that "splits" array in 2
* parition				Use a value to sort values to its lesser or greater side
*
* --------------------- Private Data Members (static Const) --------------------
*  Type			Name						Description
* ------	------------	----------------------------------------------------
* None
*
* ---------------------- Private Data Members (Non-static) ---------------------
*  Type			Name						Description
* ------	------------	----------------------------------------------------        
* None
*******************************************************************************/
class QuickSort : public AbstractSort
{
public:
	// Constructors: not used

	// Desctructor: Frees the memory requested in sort()
	~QuickSort();

	// Public mutators

	// Base class defines this as pure virtual, it must be created in this class
	virtual int * sort(int [], int);

private:
	void qSort(int, int);							// Recursive sort
	int partition(int, int);						// Sort helper function
};

/*******************************************************************************
*
* Constuctors & Destructor
*
*******************************************************************************/

/***************
* Method:		Destructor
* Description:	Frees any dynamically acquired resources
*
* Input(s):		None
*
* Output(s):	None
****************/
QuickSort::~QuickSort()
{
	if (sortArray != nullptr)
	{
		// Release the memory requested in sort()
		delete [] sortArray;
	}
}

/*******************************************************************************
*
* Methods: Public Mutators
*
*******************************************************************************/

/***************
* Method:		sort()
* Description:	Sorts the array using a recursive quicksort algorithm
*
* Input(s):		int arr[]	Array to be sorted
*				int size	Size of the array to be sorted
*
* Output(s):	(int *)	Pointer to the sorted array
****************/
int * QuickSort::sort(int arr[], int size)
{
	// Make a local copy of the array to sort on
	sortArray = new int[size];
	copyArray(arr, size);

	clearCount();									// Reset count for new run
	// Pass full array to recursive helper
	qSort(0, size - 1);

	return sortArray;								// Return the sorted array
}

/***************
* Method:		qSort()
* Description:	Recursive helper function for the QuickSort algorithm.
*
*				It sorts via a "divide and conquer" strategy, sorting 2 "halves"
*				of array (that are more likely uneven)
*
*				Recursion base case is when array offsets from either end cross
*				each other.
*
* Input(s):		int left	First element of the current array slice
*				int right	Last element of the current array slice
*
* Output(s):	(void)
****************/
void QuickSort::qSort(int left, int right)
{
	if (compare(left, right) < 0)
	{
		int pivot = partition(left, right);

		qSort(left, pivot);
		qSort(pivot + 1, right);
	}
}

/***************
* Method:		partition()
* Description:	Secondary helper function for QuickSort. This function picks a
*				value (in this case, the first element of the current array
*				"slice" defined by left and right) "pivot" and moves smaller
*			 	values to its left and larger values to its right (the value
*				gets moved towards middle early in the iterations
*
*				Note, the base class holds the class member sortArray
*
* Input(s):		int left	First element of the current array slice
*				int right	Last element of the current array slice
*
* Output(s):	(int)	The offset pointing to the "pivot"
****************/
int QuickSort::partition(int left, int right) {
	int pivot = sortArray[left];
	// Need to bump out the indices for the while loop
	--left;
	++right;

	// Swap the values larger than the pivot on left with values smaller than
	// the pivot on the right until left and right indices meet or cross.
	while (true) {										// Not infinite loop
		do
		{
			++left;
		} while (compare(sortArray[left], pivot) < 0);
		do
		{
			--right;
		} while (compare(sortArray[right], pivot) > 0);
		if (compare(left, right) >= 0)
		{
			return right;								// Leave loop here
		}
		swapElements(left, right);
	}
}

// Method Prototypes
// -----------------
void testSort(const char *, AbstractSort *, int[], int, int);
bool isSorted(const int [], int);
string showArray(const int [], int);

/*******************************************************************************
* Method: main()
*
* Method Description
* ------------------
* This program shows the number of comparisons used for 2 sorting algorithms,
* Selection & QuickSort. It will show the start of the sorted arrays (they are
* too big to display in entirety)
*
* Preconditions
* -------------
* User to press just Enter to close the window
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
*
* Invoked File Methods
* --------------------
*     Name								Description
* ------------	----------------------------------------------------------------
* showArray		"Describes" an array for displaying.
* testSort		Handles the actual sorting and reporting of compares
*******************************************************************************/
int main()
{
	const int NO_ERRORS = 0;			// Program Execution Status: No errors
	const int SIZE = 500;				// How big of array to sort
	const int DISPLAY_SIZE = 20;		// How many values to display
	const int MIN_RANGE = 1;			// For generating the random numbers
	const int MAX_RANGE = 1000;

	int programStatus = NO_ERRORS;  	// Assume no program execution errors
	int value = 0;						// For random number generation
	// Instructions call for 2 arrays to be filled identically, but also have
	// the sort class method make a local copy.
	int values[SIZE];
	int duplicates[SIZE];

	srand(time(0));						// Seed the random number generator

	// Program intro
	cout << "This program sees how many comparisons are used in both a Selection sort\n"
		 << "and QuickSort algorithm sorting the same " << SIZE << " integers.\n\n"
		 << "Only the first " << DISPLAY_SIZE
		 << " integers of the sorted array will be displayed\n"
		 << "but the whole array will be checked for correct ascending order.\n\n";

	// Fill the arrays with the same values and display the start of the first
	// to show its unsorted-ness (for comparison to the sorted arrays)
	for (int index = 0; index < SIZE; ++index)
	{
		value = (rand() % MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE;
		values[index] = duplicates[index] = value;
	}
	cout << "The first " << DISPLAY_SIZE << " values in the original array:\n"
		 << showArray(values, DISPLAY_SIZE)
		 << endl;

	// Instantiate both sort sub classes
	SelectionSort selectionSort;
	QuickSort quickSort;

	// Pass both objects to the test method along with the same array of random
	// numbers.
	testSort("Selection", &selectionSort, values,     SIZE, DISPLAY_SIZE);
	testSort("QuickSort", &quickSort,     duplicates, SIZE, DISPLAY_SIZE);

	// The sub-classes themselves free their dynamically allocated memory in
	// their destructors. No need free here

	// This prevents the Console Window from closing during debug mode using
	// the Visual Studio IDE.
	// Note: Generally, you should not remove this code
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "\n\n\n\nPress only the 'Enter' key to exit program: ";
	cin.get();

	return programStatus;

}	// End Method: main()

/*******************************************************************************
* Method: testSort(const char*, AbstractSort*, int[], int, int)
*
* Method Description
* ------------------
* This method calls the passed-in subclass's sort(), retrieves the sorted array
* and number of comparisons and displays the results. As it expects arrays too
* large for full display, it displays only a small portion, relying on a
* secondary function to verify the sorted array is truly sorted.
*
* The subclasses handle releasing their dynamically allocated memory in their
* destructor
*
* Preconditions
* -------------
* sortType to be non-empty
* sorter, the sub-class, to be instantiated
* arr, the array to be sorted, is populated with values to sort
* size is larger than zero and smaller or equal to the instantiated array size
*
* Method Arguments
* ----------------
*	Type		Name							Description
* --------	-------------	----------------------------------------------------
* char *	sortType		Type of sort; used to show which one is being tested
* Abstract*	sorter			The sub-class
* int []	values			The sorted array to confirm its actual sortedness
* int		size			The size of the sorted array
*
* Return Value
* ------------
*	Type								Description
* --------	--------------------------------------------------------------------
* void		This function does not return a value
*
* Invoked File Methods
* --------------------
*     Name								Description
* ------------	----------------------------------------------------------------
* showArray		"Converts" an array to string for displaying.
*******************************************************************************/
void testSort(const char * sortType, AbstractSort * sorter,
	int arr[], int size, int displaySize)
{
	cout << "\n\n*** Testing " << sortType << " sort ***\n\n"
		 << "Sorting array..\n\n";

	int * sorted = sorter->sort(arr, size);
	int compares = sorter->getCount();

	cout << "The array is ";
	if (isSorted(sorted, size))
	{
		cout << "successfully";
	}
	else
	{
		cout << "not";
	}

	cout << " sorted.\n\n"
		 << compares << " comparisons were performed.\n";

	if (displaySize > size)
	{
		// Don't try to display past the "reported" size of the passed-in array
		displaySize = size;
	}
	if (displaySize > 0)
	{
		cout << "The first " << displaySize << " values in the sorted array are:\n"
			 << showArray(sorted, displaySize) << endl;
	}

	// The subclasses' destructors handle releasing the dynamically allocated
	// memory, which sorted pointed to; setting to null here to visible release
	// any potential hold
	sorted = nullptr;
}

/*******************************************************************************
* Method: isSorted(const int[], int)
*
* Method Description
* ------------------
* This method confirms the array is sorted. Useful for when the sorted array is
* not fully displayed or the number of elements displayed makes it harder to
* discern the values are truly sorted
*
* Preconditions
* -------------
* size is larger than zero and smaller or equal to the instantiated array size
*
* Method Arguments
* ----------------
*	Type		Name							Description
* --------	-------------	----------------------------------------------------
* int[]		values			The sorted array to confirm its actual sortedness
* int		size			The size of the sorted array
*
* Return Value
* ------------
*	Type								Description
* --------	--------------------------------------------------------------------
* bool		Whether the array is sorted in ascending order or not.
*
* Invoked File Methods
* --------------------
*     Name								Description
* ------------	----------------------------------------------------------------
* None
*******************************************************************************/
bool isSorted(const int values[], int size)
{
	for (int index = 0; index < size - 1; ++index)
	{
		if (values[index] > values[index+1]) {
			return false;
		}
	}

	return true;
}

/*******************************************************************************
* Method: showArray(int[],int)
*
* Method Description
* ------------------
* Converts an array, or array slice, to a string for displaying.
*
* Preconditions
* -------------
* size is larger than zero and smaller or equal to the instantiated array size
*
*
* Method Arguments
* ----------------
*	Type		Name							Description
* --------	-------------	----------------------------------------------------
* int[]		values			The sorted array to confirm its actual sortedness
* int		size			The size of the sorted array
*
* Return Value
* ------------
*	Type								Description
* --------	--------------------------------------------------------------------
* string	A "description" of the array suitable for displaying
*
* Invoked File Methods
* --------------------
*     Name								Description
* ------------	----------------------------------------------------------------
* showArray(int[],int,int)	Converts array to string for displaying
*******************************************************************************/
string showArray(const int values[], int size)
{
	ostringstream out;

	if (size > 0)
	{
		int value = 0;

		// So the separator doesn't display before the first or after the last
		// element, print the first element outside the loop and the rest in a
		// loop
		out << values[value];
		for (++value; value < size; ++value)
		{
			out << ", " << values[value];
		}
	} else {
		// Show that an empty array was passed in
		out << "{}";
	}

	// Return just the inner string object of the stringstream
	return out.str();
}
