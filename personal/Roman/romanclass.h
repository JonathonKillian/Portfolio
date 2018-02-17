#include <string>			// Dealing with strings.
//#include <iostream>			// for diagnostic purposes
//#include <stdexcept>		// for out_of_range exception
#include <cctype>			// for toupper()

#ifndef HEADER_ROMAN_NS
#define HEADER_ROMAN_NS

const std::string ROMANUPPER = "MDCLXVI";
const std::string ROMANLOWER = "mdclxvi";
/* Roman -  Convert to and from Roman numerals.
 *
 * Currently, handles just the modern form, with no restriction on the M's.
 *			
 */
class Roman
{
public:
	enum class RCase {UPPER, LOWER};

	//Roman() : mInt(0), mRoman(""), mCase(RCase::UPPER) {};
	//Roman() : mRoman("") {};
	const std::string & ToRoman(int value, RCase rCase = RCase::UPPER);
	int ToInt(const std::string & roman);
	const std::string & operator()(int value, RCase rCase = RCase::UPPER) {
		return ToRoman( value, rCase);
	};
	int operator()(const std::string & roman) {
		return ToInt( roman);
	};

private:
	//int mInt;
	std::string mRoman;			// Keep a copy of the string here for lifespan.
	//RCase mCase;
};

// I know, I know. I should split the functions from the class description
// into another file. For my testing/learning experience, I'm not bothering.

/* Convert from integer to Roman using the "MDCLXVI" string (letters).
 *	1. Assumptions:
 *		1. 4s & 9s use subtractive method (CM, IV, etc).
 *		2. For C, X & I; there can be, at most, 3 of the same digit together (XXX, not XXXX).
 *		3. The integer number > 0, otherwise it is considered an error.
 *      4. Default is to assume uppercase Roman "digits",
 *			1. Lowercase, or uppercase explicitly, can be asked for.
 *			2. This just alters where letters points to.
 *	2. Set letters offset (lo) to 0.
 *	3. Set "place" (rv) to 1000.
 *	4. Integer divide input number (value) by letters offset (rv) into a temp (n).
 *	5. Add that many letters[lo] characters, "M", to result (mRoman)
 *	6. While rv > 1
 *		1. Save the remainder of value divided by rv back into value.
 *			1. This removes the already processed digits.
 *		2. Divide rv by 10.
 *			1. This allows processing of 100s, 10s and 1s (in that order).
 *		2. Add 2 to lo.
 *			1. This allows using the correct roman letters; C, X & I
 *			2. And also their "5" and "10" digits
 *		3. Integer divide value by rv (n).
 *		4. If n = 9, add letters[p]+letters[p-2] to mRoman.
 *		5. Else if n == 4, add letters[p]+letters[p-1] to mRoman.
 *		6. Else,
 *			1. If n > 5,
 *				1. Add letters[p-1] to mRoman.
 *				2. Subtract 5 from n.
 *			2. Add n number of letters[p] to mRoman.
 * 7. Result (mRoman) will now hold the Roman number.
 *
 * The only error this function handles is the passed in value being <= 0.
 * When that occurs, it will use an empty string, "", to represent error.
 * Instead, a throw can be uncommented instead; a better one than out of bounds
 * might be better in that case.
 */
const std::string & Roman::ToRoman(int value, RCase rCase) {
	//std::cerr << "DIAGNOSTIC: ToRoman( " << value << ", " << (rCase == RCase::UPPER ? "UPPER" : "LOWER") << ")\n";

	std::string letters; //(ROMANUPPER);
	if (rCase == RCase::LOWER) {
		letters = ROMANLOWER;			// mdclxvi
	}  else {
		letters = ROMANUPPER;			// MDCLXVI
	} 

	mRoman = "";

	if (value <= 0) {
		//throw std::out_of_range( "number must be an integer 1 or higher");
		return mRoman;
	}

	int lo = 0;				// lo is the offset to the string of Roman letters.
	int rv = 1000;			// rv is the level of numbers, 1000, 100, 10, 1.
	// Process for thousands...
	int n = value / rv;		// n represents the extracted roman "digit"
	mRoman.append( n, letters[lo]);

	// Process for 100s, 10s & 1s
	//value %= rv;
	while (rv > 1) {
		value %= rv;
		rv /= 10;
		lo += 2;
		n = value / rv;
		//std::cerr << "DIAGNOSTIC: rv=" << rv << ", lo=" << lo << ", n=" << n << ", value=" << value << ", mRoman=" << mRoman << "\n";
		// In C++11, .append method allows arrays and allows init-lists.
		// So fake a list to append 2 characters (as string) instead of adding
		// the 2 chars into 1 int and adding it to the answer string.
		if (n == 9) {
			mRoman.append({letters[lo], letters[lo-2]});
		} else if (n == 4) {
			mRoman.append({letters[lo], letters[lo-1]});
		} else {
			if (n >= 5) {
				// Matching the above .append, add 1 char to the answer string.
				mRoman.push_back( letters[lo-1]);
				// Subtracting 5 from n so we can drop to adding any "1"s
				n -= 5;	
			}
			mRoman.append( n,letters[lo]);
		}
		//std::cerr << "DIAGNOSTIC: rv=" << rv << ", lo=" << lo << ", n=" << n << ", value=" << value << ", mRoman=" << mRoman << "\n";
		//value %= rv;
	}

	return mRoman;
}

/* Convert from Roman to integer using the "MDCLXCI" string (letters)
 *	0. Assumptions.
 *		1. For C, X or I; no more than 3 digits in a row.
 *		2. For the subtractive method, only 1 C, X or I.
 *			1. For example; IV is acceptable, XXL is not.
 *		3. Empty strings, "Roman numbers" are considered an error.
 *	1. Set the letters offset (lo) to 0.
 *	2. Set the input (Roman) offset (ro) to 0.
 *	3. Set the multiplier (rv) to 1000.
 *	4. Increment the input offset (ro) until it no longer points to an "M"
 *	5. Add ro * rv to the answer
 *	6. While rv > 1
 *		1. Divide rv by 10.
 *			1. This will test the 100s, 10s & 1s
 *		2. Add 2 to lo.
 *			1. This will point to C, X & I as the loop repeats
 *		3. if roman[ro] == s[lo-1]
 *			1. Increment ro by 1
 *			2. Add 5*m to r
 *		3. Count the number of letters[po].
 *			1. Remember current ro (count)
 *			2. While the roman[ro] = letters[po], increment ro
 *			3. Assign the difference of ro to count back into count.
 *		4. If c = 1 & ro is not pointing at the end:
 *			1. Check if the next digit, roman[ro], is greater.
 *			2. This is where letters[lo-1] and letters[lo-2] come into play.
 *			3. If neither are the next "digit"/letter, add (1*)rv to answer
 *			4. Otherwise, add 4*rv or 9*rv (respectively) to answer
 *		5. Else if 0 <= count <= 3:
 *			1. Add count * rv to answer (Yes, this can & will add 0)
 *		6. Else error out with "Too many digits" (Remember, count can't be < 0)
 *	7. Verify the whole roman number was processed (ro points to end/length)
 *		1. If it isn't, most likely it is due to a misplaced "digit", error out.
 *		2. Else, return the answer.
 *
 * While this algorithm checks for valid Roman digits and for full processing,
 * it doesn't check for integer overflow; however, that would be an extreme
 * corner case (lots and lots of M's).
 */

// ToInt will return -1 on error; alternatively, the throws can be uncommented
// Although I should make them more appropriate; currently they are all out of
// bounds error.
int Roman::ToInt(const std::string & roman) {
	//std::cerr << "DIAGNOSTIC: ToInt( " << roman << ")\n";

	int lo = 0;
	int ro = 0;
	int rv = 1000;
	int answer = 0;

	mRoman = roman;
	for ( char & c : mRoman)
		c = std::toupper(c);
	std::string letters = ROMANUPPER;

	// Don't process empty strings
	if (roman.empty()) {
		//throw std::out_of_range("No number to convert");
		return -1;
	}
	// Check for a non-roman numeral. Doesn't check order of them.
	if (mRoman.find_first_not_of( letters) != std::string::npos) {
		//throw std::out_of_range("Invalid roman digit found in " + mRoman);
		return -1;
	}

	// Convert 1000s
	while (mRoman[ro] == letters[lo]) {
		//answer += rv;
		++ro;
	}
	answer = ro * rv;

	while (rv > 1) {
		rv /= 10;
		lo += 2;
		//std::cerr << "DIAGNOSTIC: rv=" << rv << ", lo=" << lo << ", ro=" << ro << ", answer=" << answer << "\n";
		if (mRoman[ro] == letters[lo-1]) {
		// Convert the "5" digit
			answer += 5*rv;
			++ro;
		}
		int count = ro;
		while (ro < mRoman.length() && mRoman[ro] == letters[lo]) {
			++ro;
		}
		count = ro - count;
		// It is possible to have 1 "1"s digit at the end of the number, e.g. VI
		if (count == 1 && ro < mRoman.length()) {
			/*
			for (auto i = 1; i <= 2; ++i) {
				if (mRoman[ro] == letters[lo-i]) {
					int j = i+1;
					answer += j*j*rv;
					answer += (i+1)*(i+1)*rv;
					++ro;
					break;
				}
			} */
			if (mRoman[ro] == letters[lo-2]) {
				// Convert the "9" double-digit
				answer += 9*rv;
				++ro;
			} else if (mRoman[ro] == letters[lo-1]) {
				// Convert the "4" double-digit
				answer += 4*rv;
				++ro;
			} else {
				answer += rv;
			}
		} else if (count >= 0 && count <= 3) {
			// count==1 & ro==mRoman.length() is covered here.
			answer += count*rv;
		} else {	// Error! Too many digits.
			//throw std::out_of_range("Too many duplicate roman digits. Max is 3 (EG XXX)");
			return -1;
		}
	}

	// Check if we are at the end of the roman number.
	// If not, the most likely culprit is a roman numeral out of order.
	// Remember, the roman number was validated to hold only roman digits above.
	if (ro < mRoman.length()) {
		//throw std::out_of_range("Roman number potentially ill-formed.");
		return -1;
	}

	// At this point, the number is good; pass it out.
	return answer;
}

#endif