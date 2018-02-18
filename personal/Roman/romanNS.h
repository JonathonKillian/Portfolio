#include <string>			// Dealing with strings.
//#include <iostream>			// for diagnostic purposes
//#include <stdexcept>		// for out_of_range exception
#include <cctype>			// for toupper()

#ifndef HEADER_ROMAN_NS
#define HEADER_ROMAN_NS

namespace roman
{

enum class RCase {UPPER, LOWER};
const std::string ROMANUPPER = "MDCLXVI";
const std::string ROMANLOWER = "mdclxvi";

/* Convert from integer to Roman using the "MDCLXVI" string (s).
 *	0. Assumptions:
 *		1. 4s & 9s using subtractive method (CM, IV, etc).
 *		2. For C, X & I; there can be, at most, 3 of the same digit together (XXX, not XXXX).
 *		3. The integer number > 0.
 *	1. Validate the passed in number (n)
 *		1. Can't be > 3999 (Really, this is only to enforce the maximum of 3 Roman digits in a row for M.)
 *			1. Considering that roman to integer conversion won't force this limit, it doesn't make sense to use it here.
 *	2. Roman numbers never seem to be negative
 *		1. Optionally, add "-" to r, and n = abs(n)
 *	3. Most of the time, Roman numbers also aren't plain 0.
 * 		1. However, optionally, if 0, add "N" to result; conversion completed.
 * 			1. Read about "N" on wikipedia, so the usual take with a grain of salt.
 *	2. Set place offset (p) to 0, for s[0].
 *	3. Set "place" (d) to 1000.
 *	4. Integer divide n by d. Add that many s[p] characters, "M", to result (r)
 *	5. Save remainder of the division (modulus) into n; that sheds the 1000s.
 *	6. While d > 1
 *		1. Divide d by 10.
 *		2. Add 2 to p.
 *		3. Integer divide n by p into temp (t).
 *		4. If t == 9, add s[p]+s[p-2] to r.
 *			1. Could use a select case for the 9/4/5/rest. 5 would not have a break and fall through to default which adds the remainder of n.
 *		5. Else if t == 4, add s[p]+s[p-1] to r.
 *		6. Else,
 *			1. If t > 5,
 *				1. Add s[p-1] to r 
 *				2. Subtract 5 from t into t.
 *			2. Add t number of s[p] to r.
 *		7. Save remainder of the n / p, using modulus, into n.
 * 7. Result (r) will now hold the Roman number,
 */
std::string && ToRoman(int value, RCase rCase = RCase::UPPER) {
	//std::cerr << "DIAGNOSTIC: ToRoman( " << value << ", " << (rCase == RCase::UPPER ? "UPPER" : "LOWER") << ")\n";

	std::string letters; //(ROMANUPPER);
	if (rCase == RCase::LOWER) {
		letters = ROMANLOWER;
	}  else {
		letters = ROMANUPPER;
	} 
	
	std::string roman = "";

	if (value <= 0) {
		//throw std::out_of_range( "number must be an integer 1 or higher");
		return std::move(roman);
	}

	int lo = 0;
	int rv = 1000;
	int n = value / rv;
	roman.append( n, letters[lo]);

	value %= rv;
	while (rv > 1) {
		rv /= 10;
		lo += 2;
		n = value / rv;
		//std::cerr << "DIAGNOSTIC: rv=" << rv << ", lo=" << lo << ", n=" << n << ", value=" << value << ", roman=" << roman << "\n";
		if (n == 9) {
			roman += letters[lo] + letters[lo-2];
		} else if (n == 4) {
			roman += letters[lo] + letters[lo-1];
		} else {
			if (n >= 5) {
				roman += letters[lo-1];
				n -= 5;
			}
			roman.append( n,letters[lo]);
		}
		value %= rv;
	}

	return std::move(roman);
}

/* Convert from Roman to integer using the "MDCLXCI" string (s)
 *	0. Assumptions.
 *		1. For C, X or I; no more than 3 digits in a row.
 *		2. For the subtractive method, only 1 C, X or I.
 *			1. For example; IV is acceptable, XXL is not.
 *	1. Set the place offset (p) to 0.
 *	2. Set the input offset (i) to 0.
 *	3. Set the multiplier (m) to 1000.
 *	4. Count the number of s[p] at n[i] into c
 *	5. if c > 0,
 *		1. Add c + 1 to i.
 *		2. Add c*m to result (r)
 *	6. While m > 1
 *		1. Divide m by 10.
 *		2. Add 2 to p.
 *		3. if n[i] == s[p-1]
 *			1. Add 1 to i
 *			2. Add 5*m to r
 *		3. Count the number of s[p] at n[i] into c.
 *		4. if c > 0,
 *			0. c == 0 is not an error, just nothing to do.
 *			1. Add c + 1 to i.
 *			2. if c == 1
 *				1. if n[i] == s[p-2], add 9*m to r
 *				2. if n[i] == s[p-1], add 4*m to r
 *			3. Else, if c <= 3, add c*m to r
 *			4. Else, give error & abort
 *			5. For the if..elses above, we can use a switch on c instead.
 *				1. Default case is the error condition (c > 3)
 *				2. case 2 falls through to case 3.
 *	7. Result (r) now holds the integer equivalent of the roman number.
 */

// ToInt will return -1 on error; alternatively, the throws can be uncommented
int ToInt(const std::string & roman) {
	//std::cerr << "DIAGNOSTIC: ToInt( " << roman << ")\n";

	int lo = 0;
	int ro = 0;
	int rv = 1000;
	int answer = 0;

	std::string value = roman;
	for ( char & c : value)
		c = std::toupper(c);
	std::string letters = ROMANUPPER;

	if (value.find_first_not_of( letters) != std::string::npos) {
		//throw std::out_of_range("Invalid roman digit found in " + roman);
		return -1;
	}

	// Convert 1000s
	while (value[ro] == letters[lo]) {
		//answer += rv;
		++ro;
	}
	answer = ro * rv;

	while (rv > 1) {
		rv /= 10;
		lo += 2;
		//std::cerr << "DIAGNOSTIC: rv=" << rv << ", lo=" << lo << ", ro=" << ro << ", answer=" << answer << "\n";
		if (value[ro] == letters[lo-1]) {
		// Convert the "5" digit
			answer += 5*rv;
			++ro;
		}
		int count = ro;
		while (ro < value.length() && value[ro] == letters[lo]) {
			++ro;
			//++count;
		}
		count = ro - count;
		if (count == 1 && ro < value.length()) {
			if (value[ro] == letters[lo-2]) {
				// Convert the "9" double-digit
				answer += 9*rv;
				++ro;
			} else if (value[ro] == letters[lo-1]) {
				// Convert the "4" double-digit
				answer += 4*rv;
				++ro;
			} else {
				answer += rv;
			}
		} else if (count >= 0 && count <= 3) {
			// count==1 & ro==value.length is covered here.
			answer += count*rv;
		} else {	// Error! Too many digits.
			//throw std::out_of_range("Too many duplicate roman digits. Max is 3 (EG XXX)");
			return -1;
		}
	}

	return answer;
}

} // end of namespace

#endif