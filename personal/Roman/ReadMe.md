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
- The modified date of the original source file puts it back in 2015, prior to when I started Bellevue college.
- There were two versions, a class and a header holding the two separate functions in a namespace
  - The latter was not 100% working and not included here.
  - The class version is included, renamed as romanclass.h.
    - It holds both class declaration and methods.
	- It will not work with the unitTest, even if an instantion line is included.
	- While including the exceptions, the class did not use them.
- The output of intToRoman is controlled by a public enum found in the header.
- Both functions will throw invalid_argument exceptions.
  - intToRoman will throw an exception if the input number is zero or an invalid output case is specified.
  - romanToInt will throw on empty-string, too many duplicate numerals, or an ill-formed number
- The version included here does work; as evidenced by all included unit tests passing.
- For single source files, I tend to not use Visual Studio IDE, just cl.exe. There is no solution or project file.
  - The class version was written when I was still using MinGW G++.exe as my compiler

## Screen captures
There is no sample output from an executable.

Here is a snippet from [unitTest1.cpp](./unitTest1.cpp) showing sample roman numbers used in one of the test cases.
TestPair is a struct holding an unsigned and std::string. Every roman numeral, single- or multi-character, is represented.
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