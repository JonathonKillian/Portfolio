/*******************************************************************************
*      Struct: StudentScore
* Base Struct: No base
*
* Programmer: Jon Killian
*
* Revision     Date                          Release Comment
* --------  ----------  --------------------------------------------------------
*   1.0     12/01/2016  Initial Release
*
* File Description
* ----------------
* This file contains the external struct method definitions and the
* initialization of any constant, "const" values declared at struct scope.
*
* ------------------------- Public Methods Interface ---------------------------
*      Method                            Description
* ------------------	--------------------------------------------------------
* swap					Swaps the data between this object and (an)other.
*
* ----------------------------- Private Methods --------------------------------
*      Method                            Description
* ----------------  ------------------------------------------------------------
*                          *** No private methods ***
*
* ----------------------- Data Member Initializations --------------------------
*                          *** No Initializations ***
*
*******************************************************************************/

// External Definition files
#include "studentScore.h"

/*******************************************************************************
*
* Class constructors
*
*******************************************************************************/

// No constructors

/*******************************************************************************
*
* Methods: Helper functions
*
*******************************************************************************/

/***************
* Method:		swap
* Description:	Swaps the name and score with the passed in StudentScore
*
* Input(s):		Student * other
*
* Output(s):	void
****************/
void StudentScore::swap(StudentScore * other)
{
	// Save the other's data to temp variables
	string tempName = other->name;
	int tempScore = other->score;

	// Give the other this object's name and score
	other->name = name;
	other->score = score;

	// Replace this object's name and score with the other's.
	name = tempName;
	score = tempScore;
}