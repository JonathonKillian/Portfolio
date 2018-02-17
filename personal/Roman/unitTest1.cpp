#define CATCH_CONFIG_MAIN		// Tells catch framework to supply a main()
#include "catch.hpp"			// Obtained from https://github.com/catchorg/Catch2
#include "roman.h"				// Converts to and from roman numbers

// Could've used a std::pair, std::map or even a parallel array. Instead, I chose a struct for naming purposes.
struct TestPair {
	unsigned    integer;
	std::string roman;
};

// This matcher extracts the error string (both functions use specific strings but use the same exception) to compare
// against.
// Alternatively, I could have executed two separate REQUIRE/CHECK, one to test the correct exception, the other to
// test the actual string returned by the what() function. 
// Reference: https://github.com/catchorg/Catch2/issues/1088
class ExceptionWhatMatches : public Catch::MatcherBase<std::exception> {
public:
	ExceptionWhatMatches(const std::string & expected) : expected(expected) {}

	bool match(const std::exception & actual) const override {
		return actual.what() == expected;
	}

	std::string describe() const override {
		return "is \"" + expected + "\"";
	}

private:
	std::string expected;
};

TEST_CASE("Can convert to and from lower case roman numerals", "[intToRoman][romanToInt]") {
	// These values were initially in the converting test case below. 2001 shows a jump from 1000 to 1, or 2 zeroes
	// skipped, 1666 shows every numeral in order, and the others are random.
	const std::vector<TestPair> tests {
		{   5, "v"},
		{  42, "xlii"},
		{  60, "lx"},
		{  86, "lxxxvi"},
		{  99, "xcix"},
		{ 100, "c"},
		{1666, "mdclxvi"},
		{2001, "mmi"}
	};

	for (TestPair test : tests) {
		// romanToInt is case-insensitive (Converts input to upper case)
		CHECK(test.integer == roman::romanToInt(test.roman));
		// intToRoman needs to be told to output lower case (It has a string of upper case numerals and of lower case.
		CHECK(test.roman   == roman::intToRoman(test.integer, roman::ROMAN_NUMERAL_CASE::LOWER));
	}
}

TEST_CASE("Can convert from integer to roman numbers and vice-versa", "[intToRoman][romanToInt]") {
	// Most of the 3-digit numbers were formed so each of the decimal digits could be represented in each place.
	// The hundreds are in numerical order (by 1), starting at 4; the tens are by 7, starting at 1; and the ones are by
	// 3, starting at 3.
	const std::vector<TestPair> tests {
		{ 413, "CDXIII"},
		{ 586, "DLXXXVI"},
		{ 659, "DCLIX"},
		{ 722, "DCCXXII"},
		{ 895, "DCCCXCV"},
		{ 968, "CMLXVIII"},
		{1031, "MXXXI"},
		{2104, "MMCIV"},
		{3277, "MMMCCLXXVII"},
		{4340, "MMMMCCCXL"}
	};

	for (TestPair test : tests) {
		CHECK(test.integer == roman::romanToInt(test.roman));
		CHECK(test.roman   == roman::intToRoman(test.integer));
	}
}

// While another test case does include converting a number greater than 4000, this one runs the thousands through
// their "digits" akin to another test case that loops through the smaller "places."
TEST_CASE("Roman numeral 'M' is not restricted to a maximum of 3","[intToRoman]") {
	const std::string TEN_THOUSAND("MMMMMMMMMM");
	const unsigned THOUSAND = 1000U;
	
	for (unsigned thousands = 1, value = THOUSAND; thousands <= TEN_THOUSAND.size(); ++thousands, value += THOUSAND) {
		std::string romanNumber(TEN_THOUSAND.substr(0, thousands));
		CHECK(romanNumber == roman::intToRoman(value));
		CHECK(value       == roman::romanToInt(romanNumber));
	}
}

TEST_CASE("Zero is not convertible to roman numeral", "[error][intToRoman]") {
	REQUIRE_THROWS_MATCHES(roman::intToRoman(0), std::invalid_argument,
		ExceptionWhatMatches("Can only convert integers > 0"));
}

TEST_CASE("intToRoman outputs only in all upper or lower case", "[error][intToRoman]") {
	const unsigned TEST = 1666;			// The enum would convert numerically to 0 or 1 only.
	REQUIRE_THROWS_MATCHES(roman::intToRoman(TEST, static_cast<roman::ROMAN_NUMERAL_CASE>(TEST)),
		std::invalid_argument, ExceptionWhatMatches("Roman numerals will only output in UPPER or lower case"));
}

TEST_CASE("An empty string is unconvertible", "[error][romanToInt]") {
	REQUIRE_THROWS_MATCHES(roman::romanToInt(""), std::invalid_argument,
		ExceptionWhatMatches("No number to convert"));
}

TEST_CASE("Only roman numerals are convertible to integer", "[error][romanToInt]") {
	const std::vector<std::string> testValues {
		"42",					// string integer is not roman
		"M M",					// Spaces are not ignored
		" I",					// Leading space not trimmed
		"X ",					// Trailing space also not trimmed
		"Not a roman numeral",	// Non-roman characters
		"MMM,CMXCIX",			// Commas are not used to delimit digits
		"III.IIVIV",			// Function doesn't handle fractions, especially decimal
		"-V"					// Function doesn't handle negative roman numbers
	};

	std::string error("");

	for (std::string testValue : testValues) {
		CAPTURE(testValue);				// Display the test value on failed check.
		CHECK_THROWS_MATCHES(roman::romanToInt(testValue), std::invalid_argument,
			ExceptionWhatMatches("Invalid roman numeral"));
	}
}

// I have seen some clocks sporting "IIII" for 4; but I chose to not allow that in my function.
TEST_CASE("Roman numerals 'I', 'X', and 'C' can only repeat up to 3 times", "[error][romanToInt]") {
	const std::vector<std::string> testValues {"IIII", "XXXXXX", "CCCCCCCCCC"};

	for (std::string testValue : testValues) {
		CAPTURE(testValue);				// Display the test value on failed check.
		CHECK_THROWS_MATCHES(roman::romanToInt(testValue), std::invalid_argument,
			ExceptionWhatMatches("Too many duplicate roman numerals. Except for 'M', max is 3 (e.g., XXX)"));
	}
}

TEST_CASE("Out-of-order roman numbers will not convert", "[error][romanToInt]") {
	const std::vector<std::string> testValues {
		// Only 4s and 9s use subtractive method
		// Only the one of the current place can be followed by the five or ten (previous place's one)
		"IIX",				//   8 is VIII
		"IC",				//  99 is XCIX
		"XM",				// 990 is CMXCIX
		"LC",				// The C, as well as invalid here, is also extraneous (10 - 5 is already 5)
		// Only the "one" numerals (M, C, X, & I) can be duplicated
		"vv",				// 5 + 5 = 10 which already has its own numeral, x or X
		"DDD",				// 3 * 500 = 1500. 1500 is MD.
		// Roman numbers are expected to be in descending numeric value
		"IVXLCDM"			// Even if acceptable, this does not equal MDCLXVI, but MDCLXIV
	};

	for (std::string testValue : testValues) {
		CAPTURE(testValue);				// Display the test value on failed check.
		CHECK_THROWS_MATCHES(roman::romanToInt(testValue), std::invalid_argument,
			ExceptionWhatMatches("Roman number potentially ill-formed"));
	}
}
