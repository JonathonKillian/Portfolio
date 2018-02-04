# Guess that number

## What does this program do?
Simulates a TV game show where the contestant needs to guess a number within range. Incorrect guesses shorten the valid
range until the "contestant" guesses correctly.

## Course
[Introduction to Programming](https://www.bellevuecollege.edu/classes/All/PROG/110)

## Assignment
One of the few assignments not using the [Bookstore](..\Bookstore) program. It covers loop structures and
the Random class.

## Dependencies
There are no external dependencies; it is compilable and executable as is using Visual Studio.

## Notes
- Instructions said to "have fun, be creative." I chose to use a game show environment.
- Instructions also mention to say the let the user know if the guess was incorrect and re-prompt with the range of
  valid values. My take was to do exactly that; there is no "too high" or "too low", just that the guess is incorrect.
- Due to the nature of shortening the valid range, eventually, the correct number will show.
- I use sound descriptions, "Wah wah wah", "Ding ding ding ding", and "BUZZZ" to aid in establishing a game show
  environment.
- For the instructor's benefit, I left a comment in the source with a youtube [link](https://youtu.be/iMpXAknykeg)
  for the "Wah wah wah."
- Once the user makes the correct guess and they are told the number of guesses they took, "another round" of the game
  can be played. Playing again does not repeat the introduction and how to play.
- The program executes in a command window assuming a width of 80 characters.

## Screen captures
As the application runs within a command window and does not adjust screen colors, these are copy and pastes of the
running application, instead of screen images.

### First round with valid guesses
This shows the introduction and an example "round." All inputted guesses are in expected form of positive integers
within the specified range and the full "yes" required to play another round.
```
Welcome back to another round of "Guess that number!"

For those tuning in for the first time, let me go over the rules.
A random number between 1 and 50 will be generated.
The contestant will continue making guesses within the valid range until they
find the number. It's that simple folks!
Do I hear you cry that how could the contestant guess the number with no clues
but incorrect guesses? We won't leave them in the lurch, folks! Every incorrect
guess will shorten their valid range of choices!

Ladies and gentlemen, are you all ready for today's contestant? Then let's all
give a warm welcome as the contestant comes on stage! Clap, clap, clap

We've generated some numbers through our patent pending process, we have our
Contestant, the audience is all jived up. We are ready to begin!

The winning number is now locked. Contestant, get ready to play...

                             ######################
                             # Guess that number! #
                             ######################

Contestant, please enter your guess from the range of 1 to 50: 25
Wah wah wah. I'm sorry, your guess is incorrect, please try again.

Contestant, please enter your guess from the range of 1 to 24: 12
Wah wah wah. I'm sorry, your guess is incorrect, please try again.

Contestant, please enter your guess from the range of 13 to 24: 18
Wah wah wah. I'm sorry, your guess is incorrect, please try again.

Contestant, please enter your guess from the range of 13 to 17: 15
Ding ding ding ding! Ladies and gentlemen, we have a winner!
Our contestant was able to find the number in 4 guesses.


Contestant, shall we play again (yes,no): yes
```
### Second round with invalid guesses
This is a continuation from the above run; the screen was cleared and the introduction was not repeated. Some guesses
were intentionally inputted in incorrect form to show the error message (The message does not say that the number of
guesses is still incremented).

Even the prompt to play again is shown with incorrect guesses; the correct guess finally given shows that the validation
is actually case-insensitive.

As the contestant/user chose not to play another round, they were presented with a closing message, still adhering to the
game show environment.
```
The winning number is now locked. Contestant, get ready to play...

                             ######################
                             # Guess that number! #
                             ######################

Contestant, please enter your guess from the range of 1 to 50:
BUZZZ! Your guess is outside the valid range of 1 to 50 and needs to be a whole
number. Please keep track of the valid range and try again.

Contestant, please enter your guess from the range of 1 to 50: twenty-five
BUZZZ! Your guess is outside the valid range of 1 to 50 and needs to be a whole
number. Please keep track of the valid range and try again.

Contestant, please enter your guess from the range of 1 to 50: -25
BUZZZ! Your guess is outside the valid range of 1 to 50 and needs to be a whole
number. Please keep track of the valid range and try again.

Contestant, please enter your guess from the range of 1 to 50: 25
Wah wah wah. I'm sorry, your guess is incorrect, please try again.

Contestant, please enter your guess from the range of 1 to 24: 12.0
BUZZZ! Your guess is outside the valid range of 1 to 24 and needs to be a whole
number. Please keep track of the valid range and try again.

Contestant, please enter your guess from the range of 1 to 24: +12
Wah wah wah. I'm sorry, your guess is incorrect, please try again.

Contestant, please enter your guess from the range of 1 to 11: 6
Wah wah wah. I'm sorry, your guess is incorrect, please try again.

Contestant, please enter your guess from the range of 1 to 5: 3
Wah wah wah. I'm sorry, your guess is incorrect, please try again.

Contestant, please enter your guess from the range of 1 to 2: 1
Wah wah wah. I'm sorry, your guess is incorrect, please try again.

Contestant, please enter your guess from the range of 2 to 2: 2
Ding ding ding ding! Ladies and gentlemen, we have a winner!
Our contestant was able to find the number in 10 guesses.


Contestant, shall we play again (yes,no): y
I'm sorry, but your response was lost in the cheering.


Contestant, shall we play again (yes,no):
I'm sorry, but your response was lost in the cheering.


Contestant, shall we play again (yes,no): N
I'm sorry, but your response was lost in the cheering.


Contestant, shall we play again (yes,no): NO


Contestant, thank you for playing!
Ladies and gentlemen, let's give another round of applause to our fine
Contestant as they leave the stage. Clap, clap, clap.

Thank you for watching "Guess that number!"
Please tune in again to watch our next contestant and don't forgot about our
home game!




The program has now gone off the air. Press a key to close the window.
```
