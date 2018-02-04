# DTS

## What does this program do?
DTS is a logger; it writes what is typed on the command line after it (its parameters) to a file.

Its name is derived from prepending the written line with a _D_ate/_T_ime _S_tamp.

Without a line, it displays the entire log file to screen

## Dependencies
There are no external dependencies; just the standard libraries.

## Notes
- At the time I wrote this program, I thought it easiest enough to use an environment variable.
- The program will complain if the environment variable is not set or the log file cannot be opened
- The program will not complain if told to read from a zero-byte file. The empty output would show me enough.
- Another use for the environment variable was to open the log file in notepad; there were times I did this to log
  something I couldn't as easy dump to command line.
- Reviewing the source for addition to my portfolio shows some examples of what one should not do, like combine two
  separate functions into one, displayFileorHelp (at least I named it so).
- It was originally compiled using g++; I didn't use an IDE and used printed diagnostic lines.
- This is an example of my coding a tool that I used for work. For what I used it for, it worked.

## Screen captures
As the application runs within a command window and does not adjust screen colors, these are copy and pastes of the
running application, instead of screen images.

For this run, the dts environment variable was not set
```
Please set the DTS enviroment variable.
For example, set DTS=%temp%\TestComments.txt.
```
The DTS environment variable was set; the log file does not exist yet.
```
Showing .\log.txt.
Unable to open .\log.txt.

To use this program, just type its name followed by what you want to log.
The line will be written to the log file above with a date/time stamp.
You can use this program to read the log file, just execute it without any
parameters.

```
The log file was created as a zero-byte file.
```
Showing .\log.txt.

```
A test line was logged, ```dts Trying out DTS```.
```
2018/02/04 09:31:18 Trying out DTS

```
A second line was logged and then dts executed without parameters to display the log.
```
Showing .\log.txt.
2018/02/04 09:31:18 Trying out DTS
2018/02/04 09:35:35 A second log line
```
