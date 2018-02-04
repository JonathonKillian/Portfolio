# SortsCompare

## What does this program do?
Shows a bubble sort and then selection sort on the same set of random numbers, showing the array after each pass.

## Course
[Introduction to C++ Programming](https://www.bellevuecollege.edu/classes/All/PROG/111)

## Assignment
This was assigned during the unit on arrays and on "searching, sorting and algorithm analysis."

## Dependencies
There are no external dependencies; only the standard libraries

## Notes
- Displaying the array at the bottom of the iteration was part of the instructions.
- I used formatting for easier scanning; the numbers would not go above two digits.
- For the most part, including this assignment, we worked with plain arrays, instead of std::vectors or std::arrays.
  The text book did introduce vectors; the instructor did not choose to allow them on this assignment. Thus, when passing
  arrays, the array size also had to be passed in.
- Except for the pressing "Enter" prompt at program's end, there is no User interaction.
- The array was filled with randomly-generated numbers.
- The class used Visual Studio 2015 and the instructor only asked for source, .exe and a word doc. I used the command line
  to compile and execute the program. This means there is no solution or project files included in the portfolio.

## Screen captures
As the application runs within a command window and does not adjust screen colors, these are copy and pastes of the
running application, instead of screen images.
```


 ------- Bubble sort -------


  The unsorted array: { 3, 27, 22, 11, 21,  4, 25, 27}

       After pass #1: { 3, 22, 11, 21,  4, 25, 27, 27}
       After pass #2: { 3, 11, 21,  4, 22, 25, 27, 27}
       After pass #3: { 3, 11,  4, 21, 22, 25, 27, 27}
       After pass #4: { 3,  4, 11, 21, 22, 25, 27, 27}
       After pass #5: { 3,  4, 11, 21, 22, 25, 27, 27}

   The sorted array:: { 3,  4, 11, 21, 22, 25, 27, 27}


 ------- Selection sort -------


  The unsorted array: { 3, 27, 22, 11, 21,  4, 25, 27}

       After pass #1: { 3, 27, 22, 11, 21,  4, 25, 27}
       After pass #2: { 3,  4, 22, 11, 21, 27, 25, 27}
       After pass #3: { 3,  4, 11, 22, 21, 27, 25, 27}
       After pass #4: { 3,  4, 11, 21, 22, 27, 25, 27}
       After pass #5: { 3,  4, 11, 21, 22, 27, 25, 27}
       After pass #6: { 3,  4, 11, 21, 22, 25, 27, 27}
       After pass #7: { 3,  4, 11, 21, 22, 25, 27, 27}

   The sorted array:: { 3,  4, 11, 21, 22, 25, 27, 27}



Press only the 'Enter' key to exit program:
```
