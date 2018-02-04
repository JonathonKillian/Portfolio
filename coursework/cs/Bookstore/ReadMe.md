# Bookstore

## What does this program do?
Simulates a point of sales application for a book store. Via menu selections, the user can purchase or reserve a book by entering in the book's information. The menu selections to add, edit and delete a book are not functional; they give a
screen that shows you selected them.

## Course
[Introduction to Programming](https://www.bellevuecollege.edu/classes/All/PROG/110)

## Assignment
Presented here is the final assignment. It is built atop four other assignments

## Dependencies
There are no external dependencies; it is compilable and executable as-is using Visual Studio.

## Notes <!-- The extra back slashes are to escape the back slash: \\// -->
- One of my personal touches was to center a number of status lines and to use "\\\\//" as a textual logo.
- There is no storing of book information.
- Only one title can be purchased or reserved at a time
- The command window was assumed to be 80 characters in length.
- Text validation was to ensure a minimal length of 1; no maximum length except for the ISBN.
- The two previous points could potentially lead to the right columns becoming mis-aligned as all information was shown
  in full.
- Entering an invalid entry does not re-prompt nor stop the prompts. It does trigger a message after all the prompts.
  This was per instructions.

## Screen captures
As the application runs within a command window and does not adjust screen colors, these are copy and pastes of the
running application, instead of screen images.

### Program started
```
Welcome to our neck of the galaxy!

                       \\// Vulcan Values Bookstore \\//
                       \\// The Logical Choice LLAP \\//

                              \\// Main Menu \\//

1. Purchase a book
2. Reserve a book
3. Add a book
4. Edit a book
5. Delete a book
6. Exit

Enter your choice:
```
### Purchase a book
To purchase a book, the user is prompted for the necessary information. What is shown is the screen right before
return to menu.

#### Valid entries
```

                       \\// Vulcan Values Bookstore \\//
                       \\// The Logical Choice LLAP \\//

                         \\// Purchase Information \\//

Date (mm/dd/yyyy): 01/01/2018
Quantity (#).....: 1
ISBN.............: 978-0812585988
Title............: Ghostbusters
Price (#.##).....: 2.95


                       \\// Vulcan Values Bookstore \\//
                       \\// The Logical Choice LLAP \\//
                                                                     01/01/2018

 Qty  ISBN               Title                              Price         Total
 ------------------------------------------------------------------------------
 1    978-0812585988     Ghostbusters                       $2.95         $2.95
                                                                    ===========
                                                    SubTotal....:          2.95
                                                    Tax (9.1%)..:          0.27
                                                    Total.......:         $3.22

          \\// Thank you for shopping at Vulcan Values Bookstore! \\//


               \\// Press a key to return to the main menu. \\//
```
When the user presses a key to return to menu, they are given a secondary message and asked to press another key
```


                       \\// Vulcan Values Bookstore \\//
                       \\// The Logical Choice LLAP \\//

                              \\// Main Menu \\//

1. Purchase a book
2. Reserve a book
3. Add a book
4. Edit a book
5. Delete a book
6. Exit

Enter your choice: 1


              \\// Thank you again for your purchase of $3.22 \\//





               \\// Press a key to return to the main menu. \\//
```
#### Invalid entry
The same book is purchased; however, the user inputs an invalid (negative) price. The validations are for minimal
lengths, positive numeric values for quantity and price and a max length for the ISBN. Hence, the date does not need to
conform to an actual date.

Note, there is no re-prompt, and if the one of the other fields is given bad data (e.g., a blank purchase date ), the
user would still be prompted to enter the rest of the information. As the book information is not kept between menu
selections, the user would have to again re-input all fields should they try again. This was per instructions.
```


                       \\// Vulcan Values Bookstore \\//
                       \\// The Logical Choice LLAP \\//

                         \\// Purchase Information \\//

Date (mm/dd/yyyy): 2018/01/01
Quantity (#).....: 1
ISBN.............: 0-812-58598-4
Title............: Ghostbusters
Price (#.##).....: -2.95
                \\// Please provide a positive price over 0. \\//



        \\// Unable to display sales slip with invalid information. \\//


               \\// Press a key to return to the main menu. \\//
```
The secondary message under the main menu is still displayed, altered for the inability to complete the purchase.
As the price was not entered properly, it was left with a value of zero.
```


                       \\// Vulcan Values Bookstore \\//
                       \\// The Logical Choice LLAP \\//

                              \\// Main Menu \\//

1. Purchase a book
2. Reserve a book
3. Add a book
4. Edit a book
5. Delete a book
6. Exit

Enter your choice: 1


         \\// We are sorry we were unable to process you order    \\//
         \\// of $0.00. Were you able to enter everything proper? \\//




               \\// Press a key to return to the main menu. \\//
```
### Reserve a book
Like purchasing a book, the user is prompted to enter information one line at a time.

Unlike when purchasing, there is no secondary message displayed under the main menu.

#### Valid entries
```


                       \\// Vulcan Values Bookstore \\//
                       \\// The Logical Choice LLAP \\//

                           \\// Book Reservation \\//

ISBN.................: 978-0-441-00718-9
Title................: Galaxy Quest
Author...............: Terry Bison
Publisher............: Ace
Wholesale Cost (#.##): 5.99

                   \\// Set phasers to stun and fire at: \\//
Galaxy Quest by Terry Bison
Published by Ace
with an ISBN of 978-0-441-00718-9 for the low, low price of $5.99






               \\// Press a key to return to the main menu. \\//
```
#### Invalid entries
For this example, nothing was entered for all prompts.
```


                       \\// Vulcan Values Bookstore \\//
                       \\// The Logical Choice LLAP \\//

                           \\// Book Reservation \\//

ISBN.................:
                     \\// Please provide a valid ISBN. \\//

Title................:
                     \\// Please provide a valid title. \\//

Author...............:
                     \\// Please provide a valid author. \\//

Publisher............:
                     \\// Please provide a valid publisher. \\//

Wholesale Cost (#.##):
                \\// Please provide a positive cost over 0. \\//



           \\// Unable to display reservation with invalid data. \\//


               \\// Press a key to return to the main menu. \\//
```
### Inventory
Menu selections '3' through '5' deal with book inventory. Our instructions were to display a screen showing the user
what selection was made.

This example is for adding a book, selection '3'. A selection of '4' or '5' would only differ in the middle line
starting with "You selected."
```


                       \\// Vulcan Values Bookstore \\//
                       \\// The Logical Choice LLAP \\//

                              \\// Inventory \\//





                      \\// You selected "Add a book" \\//











               \\// Press a key to return to the main menu. \\//
```
### Exitting the program
```


                       \\// Vulcan Values Bookstore \\//
                       \\// The Logical Choice LLAP \\//

                        \\// Exit, stage left even \\//





      \\// Thank you for doing business with Vulcan Values Bookstore! \\//
      \\// We are here to help you with your book purchases.          \\//
      \\// It is the logical choice. LLAP                             \\//



                       \\// Please come back again! \\//




The program is reporting, "all stop." Press a key to close this window.
Thanks, -- Jon Killian

```
