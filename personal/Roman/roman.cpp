#include <string>			// Roman numbers are held in strings
#include <cctype>			// for toupper()
#include <stdexcept>		// for invalid_argument exception
#include <algorithm>		// for transform()
#include "roman.h"			// For ROMAN_NUMERAL_CASE enum

/*******************************************************************************
* Roman namespace: Holds functions to convert decimal to/from roman numbers/numerals.
*
* Rules used by the functions
* - The functions only handle up to roman numeral for 1000; No bars, parentheses, or reversed Cs around the numerals.
* - 4s & 9s using subtractive method (CM, IV, etc).
*	- Only 1 smaller numeral (e.g., IX, not IIX)
*	- Only the next larger five (D, L or V) or "ten" numeral (M, C, or X) is allowed (IX, but not IC)
* - For hundreds, tens and ones (C, X & I) there will be, at most, 3 duplicates (e.g., III, not IIII).
* - Thousands, M, are not limited to a max of 3.
* - Only positive non-zero integer numbers are handled by the function.
* - The functions use 32-bit unsigned integers; passing negative integers will result in really large roman numbers.
* - Roman numbers are not positional
*	- They don't use the concept of 0 as a place holder (e.g., 1001 is MI, or 1000 "plus" 1).
* - intToRoman returns capital numerals; romanToInt accepts either.
*******************************************************************************/
namespace roman {
	namespace {
		// Only the functions within the outer namespace need to know about these constants.

		// The enum is in the header as that is part of the public API.
		// The arrays of roman numerals.
		const std::string MDCLXVI("MDCLXVI");
		const std::string mdclxvi("mdclxvi");		// Used only by intToRoman()

		// Magic numbers ;)
		// Raw digits, representing themselves, are left as numeric literals.
		const unsigned    BASE        =   10;		// Convert to & from decimal
		const unsigned    MIN_PLACE   =    1;		// Lowest roman numeral
		const unsigned    MAX_PLACE   = 1000;		// Highest roman numeral handled
	}

	/***************************************************************************
	* Convert from integer to roman number
	*	1. Convert thousands first; this will generate a string of 'M' numerals.
	*	2. Loop through the other places (100, 10, 1).
	*		1. Remove the processed digit(s) from the input value.
	*		2. Adjust place to the next lower value.
	*		3. Get the numerals representing ten, five and one for the particular place/level
	*		4. Extract the next digit from the input number.
	*		5. Process the digit
	*			1. digit = 9, attach the one's and ten's numeral; IX, XC, CM. Loop.
	*			2. digit = 4, attach the one's and five's numeral; IV, XL, CD. Loop.
	*			3. digit >= 5, attach five's place digit (D, L, or V), and subtract 5 from digit.
	*			4. Any other digit is used as a count to attach the one's digit.
	*	3. Return the roman number to the calling function.
	***************************************************************************/
	std::string intToRoman(unsigned value, ROMAN_NUMERAL_CASE numeralCase) {
		// Assert the passed in number is positive
		if (value == 0) {
			throw std::invalid_argument("Can only convert integers > 0");
		}

		std::string numerals(MDCLXVI);
		switch (numeralCase) {
			case ROMAN_NUMERAL_CASE::UPPER:
				break;									// numerals is initialized to upper case numerals
			case ROMAN_NUMERAL_CASE::LOWER:
				numerals = mdclxvi;
				break;
			default:
				throw std::invalid_argument("Roman numerals will only output in UPPER or lower case");
		};

		std::string romanNumber = "";					// Holds the converted roman number
		unsigned    numeral     = 0;					// Offset into the roman letters array
		unsigned    place       = MAX_PLACE;			// Only go up to thousands place
		unsigned    digit       = value / place;		// Pre-fill digit with the count of thousands
		// Variable names are the digit representation for the particular "place"
		// My personal choice is to not leave uninitiated variables, so the five and ten being assigned one's value is
		// strictly a place-holder
		char        one         = numerals[numeral];	// Start with the 1 in the thousand place
		char        five        = one;
		char        ten         = one;

		// Add the number of thousand numerals to the output
		romanNumber.append(digit, one);

		// Loop through the other places (100, 10, 1).
		// The place is adjusted after the check; MIN_PLACE is still processed in-loop
		while (place > MIN_PLACE) {
			value %= place;								// Remove the processed digit(s)
			place /= BASE;								// Adjust down to 100s, 10s and 1s

			// Using the digit variables reads slightly better and keeps the adjustment of the offset into the roman
			// numerals positive. Originally, I was adding 2 and subtracting 1 and 2 to refer to fives and tens.
			ten    = numerals[numeral];
			five   = numerals[++numeral];
			one    = numerals[++numeral];

			// Extract the next digit from the input number and process.
			digit  = value / place;

			// 9s and 4s require two roman numerals, to represent subtracting method
			if (digit == 9) {
				// 9 translates to CM, XC, or IX.
				romanNumber.append({one, ten});
			} else if (digit == 4) {
				// 4 translates to CD, XL, or IV.
				romanNumber.append({one, five});
			} else {									// Fives and ones are handled together.
				// 5 has its own numeral; D, L, or V.
				if (digit >= 5) {
					romanNumber += five;
					digit       -= 5;
				}

				// 0-3 are represented by a count of the one; C, X, or I.
				// 5-8 reach this point as 0-3.
				romanNumber.append(digit, one);
			}
		}

		// romanNumber now holds a proper roman number.
		return romanNumber;
	}

	/***************************************************************************
	* Convert from roman to integer using the "MDCLXCI" string (s)
	*	1. Count the number of thousand numerals, mulitply by 1000, and save to output.
	*	2. While ther are roman numerals and the "place" is still > 1:
	*		1. Adjust place to the next lower value.
	*		2. Extract the place's digits into temp variables.
	*			1. The assignments also move the offset along for the next iteration.
	*		3. Check if there is a five digit (D, L, or V) present.
	*			1. If so, add 5 to the output & advance digit offset.
	*		4. Count the number of one digits.
	*			1. A count of 0 here is not an error, just means there's no digit at this place level.
	*		6. If count is 1 and there is another numeral/digit:
	*			1. If the next digit is a ten (previous one) digit:
	*				1. Add 9 to the output and advance the digit offset.
	*			2. Else if the next digit is a five digit:
	*				1. Add 4 to the output and advance the digit offset.
	*			3. Else, add the current digit (place value) to output.
	*		7. Else if count is  <= 3, add the count * place value to output.
	*		8. Else, give error.
	*	3. If there are still "digits" unprocessed in the passed-in string, it was not formed correctly.
	*		1. Throw an error that the number is malformed
	*	4. Return to the caller the integer output.
	***************************************************************************/
	unsigned romanToInt(std::string romanNumber) {
		const unsigned MAX_DUPLICATE = 3;		// Maximum number of valid repeat consecutive digits

		// Empty strings have nothing to convert to integer & 0 is not a valid converted result.
		if (romanNumber.empty()) {
			throw std::invalid_argument("No number to convert");
		}

		// Make the conversion case-insensitive
		std::transform(romanNumber.cbegin(), romanNumber.cend(), romanNumber.begin(), std::toupper);

		// Can only convert the roman numerals; spaces, symbols and others are not valid.
		if (romanNumber.find_first_not_of(MDCLXVI) != std::string::npos) {
			throw std::invalid_argument("Invalid roman numeral");
		}

		unsigned length  = romanNumber.size();	// Length is checked in multiple places
		unsigned place   = MAX_PLACE;			// Start at the highest roman numeral value
		unsigned count   = 0U;					// For counting the one's numerals (C, X, & I)
		unsigned numeral = 0U;					// Offset into the roman numerals string
		unsigned digit   = 0U;					// Offset into the passed in romanNumber
		unsigned value   = 0U;					// Could well call this sum
		// Variable names are the digit representation for the particular "place"
		// five and ten are given just a place holder value here; one's value is just handy.
		char     one     = MDCLXVI[numeral];
		char     five    = one;
		char     ten     = one;

		// Convert the thousand's numeral
		while (romanNumber[digit] == one) {
			++digit;							// Count the 'M's 
		}
		value = digit * place;					// Convert the count to 1000s

		// Iterate through 100s, 10s and 1s.
		while (place > MIN_PLACE) {
			place /= BASE;						// Adjust down to 100s, 10s and 1s
			// Copy the proper numerals into their representative variables
			ten    = MDCLXVI[numeral];
			five   = MDCLXVI[++numeral];
			one    = MDCLXVI[++numeral];

			// Account for a five numeral; D, L, or V.
			if (romanNumber[digit] == five) {
				value += 5 * place;
				++digit;
			}

			// Account for the one numeral, which can be duplicated up to three times.
			count = digit;				// Current input string offset represents zero
			while (digit < length && romanNumber[digit] == one) {
				++digit;
			}
			count = digit - count;		// Calculate the count from the digit offset delta

			// Account for the count of one numerals.
			if (count == 1 && digit < length) {
				if (romanNumber[digit] == ten) {
					// 1 before 10 is 10-1 is 9.
					value += 9 * place;
					++digit;			// Bypass the 9's second digit.
				} else if (romanNumber[digit] == five) {
					// 1 before 5 is 5-1 is 4.
					value += 4 * place;
					++digit;			// Bypass the 4's second digit.
				} else {
					// The next numeral is not larger, so just convert the single digit
					value += place;
				}
			} else if (count <= MAX_DUPLICATE) {
				// A trailing single one will convert here.
				value += count * place;
			} else {
				// A count of 4 or more is not allowed
				throw std::invalid_argument("Too many duplicate roman numerals. Except for 'M', max is 3 (e.g., XXX)");
			}
		}

		// If there are still "digits" unprocessed in the passed-in roman number, it was not formed correctly.
		if (digit < length) {
			throw std::invalid_argument("Roman number potentially ill-formed");
		}

		// Reaching here means the roman number was valid and value holds its integer conversion.
		return value;
	}
} // end of namespace
