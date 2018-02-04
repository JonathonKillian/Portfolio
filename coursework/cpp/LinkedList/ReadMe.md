# LinkedList

## What does this program do?
Runs the templated linked-list class through some visual tests.

## Course
[Intermediate C++ Programming](https://www.bellevuecollege.edu/classes/All/PROG/113)

## Assignment
This is the last assignment. It is a combination of five text book problems and shows off each of the methods added by each
problem.

The five problems:
1. Create a simple linked list class (adding to the list only from the front).
1. Add a copy constructor.
1. Stringify the list of values.
1. Add a destructor and "remove by value" function.
1. Add a reverse list function via pointer manipulation only.

## Dependencies
There are no external dependencies; only the standard libraries and the class created for the assignment (functions are
in the header due to be templated)

## Notes
- I coded the copy constructor without using the reverse function as its problem came before. The instructions did not
  stipulate this.
- The instructions only had us testing with double values. As the class was written in template style, I added a string
  linked list in the form of the message and prompt that displays at program's end.
  I added code to remove a node and to reverse the list of strings before displaying it.
- For reasons I no longer remember (or included within comment) I added an extra class method that was never called by the
  main program. The instructor did not ding me on it either.
- Except the need to press "Enter" at program's end, there is no user interaction.
- The numbers are randomly generated; the list length is hard-coded.
- The class used Visual Studio 2015 and the instructor only asked for source, .exe and a word doc. I used the command line
  to compile and execute the program. This means there is no solution or project files included in the portfolio.

## Screen captures
As the application runs within a command window and does not adjust screen colors, these are copy and pastes of the
running application, instead of screen images.

```
This program puts a linkedList UDT class through some paces

Please note: the doubles are displayed to 2 places, but
they are randomly generated to more places.


Create a linked list (of doubles).
1st: []


Adding 10 random values
1st: [16.84, 15.81, 15.59, 16.03, 17.00, 16.45, 15.73, 14.19, 16.18, 16.03]


Creating a 2nd list via its Copy constructor
2nd: [16.84, 15.81, 15.59, 16.03, 17.00, 16.45, 15.73, 14.19, 16.18, 16.03]


Removing 16.45 from the 2nd list
1st: [16.84, 15.81, 15.59, 16.03, 17.00, 16.45, 15.73, 14.19, 16.18, 16.03]
2nd: [16.84, 15.81, 15.59, 16.03, 17.00, 15.73, 14.19, 16.18, 16.03]


Reversing the 1st list
1st: [16.03, 16.18, 14.19, 15.73, 16.45, 17.00, 16.03, 15.59, 15.81, 16.84]
2nd: [16.84, 15.81, 15.59, 16.03, 17.00, 15.73, 14.19, 16.18, 16.03]


[Press, only, the, 'Enter', key, to, exit, program:]
```