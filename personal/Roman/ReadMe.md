# Roman

## What does this program do?
- Provides a "roman" namespace holding two functions for converting between positive non-zero integers and roman numbers.
- intToRoman() converts an unsigned integer to std::string holding a roman number.
  - A second optional parameter allows the calling function to specify upper (default) or lower case.
- romanToInt() converts a case-insensitive std::string holding a roman number to an unsigned integer.

## Dependencies
- The source cpp and h files use standard libraries but do not include a main().
- The unit test file requires the [Catch 2 framework](https://github.com/catchorg/Catch2).
  - Catch 2 is a single header file; installation is just copying it to local machine.

## Notes
### Versions
#### roman.cpp & roman.h
- This is the revamped functions; split into separate source and header files.
- Have unit tests written for them, unitTest1.cpp
- Use exceptions instead of sentinels and slightly more validation
  - intToRoman will throw an exception if the input number is zero or an invalid output case is specified.
  - romanToInt will throw on empty-string, too many duplicate numerals, or an ill-formed number
- The output of intToRoman is controlled by a public enum found in the header.

#### romanNS.h
- Older version; circa July 2015 (last saved date)
- Uses namespace to hold the two converter functions.
- Has logic errors.
  - I apparently did not fully comprehend how std::move() and && references worked; the test code spewed non-printable
    characters.
  - I made a newbie mistake of thinking char + char would concatenate the two characters as they were being concatenated
    to a string.
- Used visual comparisons for "unit tests" (test file not included)

#### romanclass.h
- Older version; circa July 2015 (last saved date)
- Used class over a namespace.
- It needs to be instantiated to be used (did not use static functions)
- Added alternate convert methods, using operator()().
- Same visual comparison tests used
- Did not use std::move nor tried char + char for concatenation.

### General
- Revamping inspired by reviewing original code for inclusion here.
- I use command line compiler, MinGW/g++.exe initially and, more currently, cl.exe (Visual Studio 2015)
- The modified date of the original source files puts it back in July 2015, prior to when I started Bellevue college.
- The original files had both exceptions and sentinel values; the exceptions were commented out (I don't remember why)
- The functions cap duplicated numerals at three; IIII has been on clocks but is not considered valid by the functions.

## Screen captures
There is no sample output from an executable.

Here is a snippet from unitTest1.cpp showing sample roman numbers used in one of the test cases.
TestPair is a struct holding an unsigned and std::string. Every roman numeral, single- or multi-character, is represented.
<!-- Specifying "cpp" here specifies to color the syntax for C++ -->
```cpp
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
```