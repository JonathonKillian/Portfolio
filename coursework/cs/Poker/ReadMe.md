# Poker

## What does this program do?
Play "poker" against a computer dealer. The user is given $10 in credit and play continues until they lose it all.

## Course
[Object Oriented Programming Concepts](https://www.bellevuecollege.edu/classes/All/PROG/120)

## Assignment
This is the course project. We worked on it during the second half of the quarter.

## Dependencies
There are no external dependencies; it is compilable and executable as is using Visual Studio.

## Notes
- While called poker, it is not. Players can only draw one card and win by either a flush or ace-high. The instructor
  called it "poker."
- I added a method to sort the deck of cards based on
  [Fisher-Yates shuffle](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle)
  before the instructor informed the class how he wanted them to sort, by adding a boolean flag to the card class and
  randomly choosing a card until one was found with the boolean set to false. I was permitted to keep my version in.
- I also added a confirmation when the user chooses to replace a card. There is no confirmation for standing pat.
- Instructions had the dealer draw a new card if they hold a card under seven.
- The dealer always plays second and their draw, if any, is not shown.
- The hands are re-displayed when the winner is announced and money changes hands.
- Aces are considered strictly high as there is no hands that would need them low (i.e., straights).
- Each card has its own point value. From deuces at 2 to face cards (11-13) and aces (14).
- Game play is in a console window with colored text and backgrounds.
- There is no way to exit before user exhausts their $10.
  Pressing Control-C or simply closing the command window does work.

### Screen shots
While running in a console window, coloring is used; pictures are provided instead of copy and pasting.
![Introduction screen](screenshots\Introduction.JPG)
![A hand being played](screenshots\first hand.JPG)
![Player lost a hand](screenshots\Hand lost.JPG)
![Player won a hand](screenshots\Hand won.JPG)
![Player is out of funds; game over](screenshots\Hand lost.JPG)
