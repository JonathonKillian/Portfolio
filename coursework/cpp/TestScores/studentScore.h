#pragma once

// External Definition files
// -------------------------
#include <string>                   // For string class
using std::string;                  // Only need string out of std namespace

/*******************************************************************************
*      Struct: StudentScore
* Base Struct: No base
*
* Programmer: Jon Killian
*
*
* Revision     Date                          Release Comment
* --------  ----------  --------------------------------------------------------
*   1.0     12/01/2016  Initial Release
*
*
* Struct Description
* ------------------
* Struct holds a name and test score. Since it will be part of an array that
* will be sorted, a helper function to swap the values with another is added.
*
* --------------------------- Public Methods Interface -------------------------
*       Method                                Description
* ------------------	--------------------------------------------------------
* swap					Swaps the data between this object and (an)other.
*
* --------------------------------- Private Methods ----------------------------
*       Method                                Description
* ------------------	--------------------------------------------------------
*                           *** No private methods ***
*
*
* -------------------------- Private Data Members ------------------------------
*				 Data
*    Type		 Type	Name					  Description
* ----------	------	----	------------------------------------------------
*                         *** No private data members ***
*
* --------------------------- Public Data Members ------------------------------
*				 Data
*    Type		 Type	Name					  Description
* ----------	------	----	------------------------------------------------
* non-static	string	name	The student's name
* non-static	int		score	The student's test score

*******************************************************************************/
struct StudentScore
{
    string name;
    int    score;

	// Helper functions
	void swap(StudentScore *);						// Swaps this and other.
};
