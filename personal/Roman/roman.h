#ifndef HEADER_ROMAN_CONVERTERS_NS
#define HEADER_ROMAN_CONVERTERS_NS

#include <string>

namespace roman {
	enum class ROMAN_NUMERAL_CASE {
		UPPER,						// roman numerals are M, D, C, L, X, V & I
		LOWER						// roman numerals are m, d, c, l, x, v & i
	};

std::string intToRoman(unsigned, ROMAN_NUMERAL_CASE = ROMAN_NUMERAL_CASE::UPPER);
unsigned    romanToInt(std::string);
}

#endif	// HEADER_ROMAN_CONVERTERS_NS