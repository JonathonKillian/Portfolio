# SortingAlgorithmAnalysis

## What does this program do?
This program counts how many comparisons are used to sort an array of 500 integers using both a selection sort algorithm
and a quick sort algorithm.

## Course
[Intermediate C++ Programming](https://www.bellevuecollege.edu/classes/All/PROG/113)

## Assignment
This assignment has us using polymorphism, virtual functions and abstract base classes.

## Dependencies
- There are no external dependencies; only the standard libraries are used.

## Notes
- For this assignment, the instructor had us keep all the class declarations and functions in the one source file.
- The sorting algorithms came from earlier assignments
- This also shows recursion; I do not otherwise have a separate program exemplifying recursion currently in my portfolio.
- I chose to make a test method that is passed in the derived class as the steps were the same for both. Compare that the
  other [program](..\SortsCompare\SortsCompare.cpp) in the portfolio from the preceding course where I duplicated the
  "test" method.
- There were conflicting requirements in the instructions that had both main() and the public sort() method in the derived
  classes to both make copies of the generated array. As no update came from the Instructor prior to turn-in, I left the
  conflict in; thus generating four copies of the same array.
- As we were to use an array of 500 numbers, and the sorting itself was not the purpose of this application,
  it would not be helpful to display 1500 numbers for eye-ball comparisons. Instead, only the first twenty numbers were
  displayed, unsorted, sorted by selection sort and sorted by quick sort (the latter two should be the same). A validation
  function was added and used to verify the array was properly sorted in ascending order.
- Except for the pressing "Enter" prompt at program's end, there is no User interaction.
- The numbers were randomly generated every run.
- The class used Visual Studio 2015 and the instructor only asked for source, .exe and a word doc. I used the command line
  to compile and execute the program. This means there is no solution or project files included in the portfolio.

## Screen captures
As the application runs within a command window and does not adjust screen colors, these are copy and pastes of the
running application, instead of screen images.
```
This program sees how many comparisons are used in both a Selection sort
and QuickSort algorithm sorting the same 500 integers.

Only the first 20 integers of the sorted array will be displayed
but the whole array will be checked for correct ascending order.

The first 20 values in the original array:
81, 958, 311, 744, 472, 614, 836, 894, 378, 234, 143, 475, 368, 833, 323, 110, 245, 78, 157, 958


*** Testing Selection sort ***

Sorting array..

The array is successfully sorted.

124750 comparisons were performed.
The first 20 values in the sorted array are:
4, 7, 8, 11, 12, 14, 18, 23, 24, 28, 30, 31, 34, 38, 40, 42, 44, 46, 47, 48


*** Testing QuickSort sort ***

Sorting array..

The array is successfully sorted.

9982 comparisons were performed.
The first 20 values in the sorted array are:
4, 7, 8, 11, 12, 14, 18, 23, 24, 28, 30, 31, 34, 38, 40, 42, 44, 46, 47, 48




Press only the 'Enter' key to exit program:
```