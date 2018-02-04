# TestScores

## What does this program do?
This program prompts for a number of students, their names and test scores. It outputs a list, sorted by score then
student and display's the calculated average.  While numeric input is limited to integers within range of 0 to 100, the
average is displayed with a decimal fraction when present (it is displayed without formatting).

## Course
[Introduction to C++ Programming](https://www.bellevuecollege.edu/classes/All/PROG/111)

## Assignment
This assignment has us working on raw pointers. We were only instructed on the built-in "raw" pointers and assigning
dynamic memory using new and delete.

This was actually the last assignment for the class; there was no course project.

## Dependencies
There are no external dependencies; only the standard libraries and the class created for the assignment.

## Notes
- The choice of selection sort was dictated by instructions. There is validation for the numeric input.
- Only the test scores were validated; the student's name only required characters (by the nature of using the input
  stream).
- We were instructed to use regular arrays, so their size needed to be passed into the functions along side the array
  pointer.
- The class used Visual Studio 2015 and the instructor only asked for source, .exe and a word doc. I used the command
  line to compile and execute the program. This means there is no solution or project files included in the portfolio.

## Screen captures
As the application runs within a command window and does not adjust screen colors, these are copy and pastes of the
running application, instead of screen images.

### Valid run
The average was manually verified correct using a calculator.
```

Test Score Average Calculator

This program will accept a variable list of student names and their test score
from a recent test. It will then display them in sorted order and displayed the
average for the test.

The numeric inputs are whole numbers; however, the average will display a
fraction when needed.

How many test scores to enter (5-20): 6

Enter student #1's name: May
Enter May's score (0-100): 80

Enter student #2's name: April
Enter April's score (0-100): 99

Enter student #3's name: June
Enter June's score (0-100): 100

Enter student #4's name: August
Enter August's score (0-100): 100

Enter student #5's name: Autumn
Enter Autumn's score (0-100): 92

Enter student #6's name: Winter
Enter Winter's score (0-100): 60


  Score  Student
  -----  -------
     60  Winter
     80  May
     92  Autumn
     99  April
    100  August
    100  June


The average test score is 88.5


Press only the 'Enter' key to exit program:
```
### Invalid entries
Various non-numeric entries were tried. As the program was using I/O streams, pressing Enter by itself was ignored, I
just had to type in a valid entry on a blank line.
```

Test Score Average Calculator

This program will accept a variable list of student names and their test score
from a recent test. It will then display them in sorted order and displayed the
average for the test.

The numeric inputs are whole numbers; however, the average will display a
fraction when needed.

How many test scores to enter (5-20): 4
Please enter a whole number within range.
How many test scores to enter (5-20): 21
Please enter a whole number within range.
How many test scores to enter (5-20): 10.5
Please enter a whole number within range.
How many test scores to enter (5-20): Ten
Please enter a whole number within range.
How many test scores to enter (5-20):
5

Enter student #1's name:
Please supply an entry.
Enter student #1's name: 1
Enter 1's score (0-100): -10
Please enter a whole number within range.
Enter 1's score (0-100): 106
Please enter a whole number within range.
Enter 1's score (0-100):

0

Enter student #2's name: Bobbie Jo
Enter Bobbie Jo's score (0-100):   100

Enter student #3's name: ^A
Enter ☺'s score (0-100): 000000000000000000000000000000000000000001

Enter student #4's name: @
Enter @'s score (0-100): 100 100
Please enter a whole number within range.
Enter @'s score (0-100): 100

Enter student #5's name: Zed
Enter Zed's score (0-100): 0


  Score  Student
  -----  -------
      0  1
      0  Zed
      1  ☺
    100  @
    100  Bobbie Jo


The average test score is 40.2


Press only the 'Enter' key to exit program: :)
```