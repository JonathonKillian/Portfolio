# Punchline

## What does this program do?
The application displays a joke and punchline, by reading two user-supplied files.

The supplied joke file is read-in and displayed in entirety. Only the last line of the punchline is displayed.

## Course
[Intermediate C++ Programming](https://www.bellevuecollege.edu/classes/All/PROG/113)

## Assignment
This assignment was assigned during the unit on file I/O.

## Dependencies
- There are no external dependencies; only the standard libraries.
- The program does expect two text files (not that it would care if the same file if given for both).

## Notes
- The instructions allowed for, assumed, the punchline file would not end in a newline/"Enter" character. This tied in
  with one of the requirements that we search for the beginning of the punchline, by searching for a new line character,
  from the end of the file.
- I chose to check for newline characters being at file's end, moving the file pointer back until the first non-newline
  character, then searching for a newline signifying the beginning of the punchline.
- I also coded for reaching the beginning of the file without a newline. Another variation to the instructions.
- Since I took the alternate path, the instructor graded me on it; offering suggestions and allowing me to re-submit (I
  had turned-in early and still had time before the deadline that locked the assignment).
- There is minor validation of the filenames supplied by the user; if the file can't be opened for reading, the user is
  re-prompted.
- There is validation code for failing to read the files (albeit the file is successfully opened). Due to the latter
  addition of checking for file existence by opening it (it is kept open afterwards) the validation at reading may be
  extraneous.
- The test joke and punchline files are not included. However, they are only text files.
- The class used Visual Studio 2015 and the instructor only asked for source, .exe and a word doc. I used the command
  line to compile and execute the program. This means there is no solution or project files included in the portfolio.

## Screen captures
As the application runs within a command window and does not adjust screen colors, these are copy and pastes of the
running application, instead of screen images.

This sample run uses one set of the joke and punchline files supplied by the instructor. Main() prints one blank line
before displaying the contents of the joke file, and both methods that display from file print a final new line.

Be aware, the "Q:" and "A:" are read-in from the files.
```

This program will display a joke read from two files, where the first holds all
but the punchline and the second holds the punchline as the last of multiple
lines.

Please enter the name of the joke file
 (e.g., joke.txt): joke.txt

Please enter the name of the punchline file
 (e.g., punchline.txt): punchline.txt

Telling the joke (don't shoot the messenger!)


Q: What did the tongue say to the teeth?

A: If you bite me again, I will give you a licking.


Th-th-th-that's all, folks! -- Porky Pig
Press Enter to exit program:

```
An example of providing a file that only has a "Enter" in it (noliner.txt). This causes the punchline to be an empty line.
```

This program will display a joke read from two files, where the first holds all
but the punchline and the second holds the punchline as the last of multiple
lines.

Please enter the name of the joke file
 (e.g., joke.txt): joke.txt

Please enter the name of the punchline file
 (e.g., punchline.txt): noliner.txt

Telling the joke (don't shoot the messenger!)


Q: What did the tongue say to the teeth?




Th-th-th-that's all, folks! -- Porky Pig
Press Enter to exit program:

```