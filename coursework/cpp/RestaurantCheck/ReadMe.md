# RestaurantCheck


## What does this program do?
Simulates a restaurant order being entered, by number, and a check/receipt generated.

## Course
[Introduction to C++ Programming](https://www.bellevuecollege.edu/classes/All/PROG/111)

## Assignment
This assignment was given for the chapter on arrays. It gives us the opportunity to showcase parallel arrays.

## Dependencies
- There are no external library dependencies; only the standard libraries are used.
- A source file with a main() is needed; the assignment did not require us students to create.

## Notes
- For this assignment, the instructor provided the CPP file holding main() and we were to create a class with two static
  methods that the instructor's code utilizes.
- The menu was left up to each student. I used food found in various Dr. Seuss books. Web pages used are linked in the
  source code.
- This assignment is Windows-specific; it uses windows.h API to move the cursor around the command window.
- Like my other C++ assignments, no Visual Studio solution or project files are included, I used cl.exe instead.
- The instructor provided the source code holding the main(). It is not included as it is not my own code.
- Instructions gave a max order of five menu items; only

## Screen captures
As the application runs within a command window and does not adjust screen colors, these are copy and pastes of the
running application, instead of screen images.

### Valid run
What is shown is my doing within the class; so the prompts for tax and tip are not shown. The menu screen is actually
from the method for placing an order. There is a hard-coded limit of five, after item 5, the y/n prompt is automatically
displayed. The prompt to press enter for the check is from the instructor's code; the order-taking and check generation
are different methods.

What is not displayed here is the prompt to enter the menu item; it is overwritten with the valid choice.
```
                                Who-ville Grille
                                      Menu


   1. Green Eggs & Ham           9.99      2. Roast Beast               15.98
   3. Wham Chops                13.29      4. Glunker Stew               7.35
   5. Who Hash                   4.75      6. Truffula Fruit             4.48
   7. Choc'late Mush-Mush        6.49      8. Blueberry Bumplings        5.55
   9. Goose Juice                1.99     10. Butterfly Milk             2.49


   1. Roast Beast             $ 15.98
   2. Who Hash                $  4.75
   3. Truffula Fruit          $  4.48
   4. Blueberry Bumplings     $  5.55
   5. Butterfly Milk          $  2.49
      Is your order correct (Y/N)? y

Press "Enter" when ready for the customer's check:
```
This is the generated check from the order placed above. The right-side is displayed independent of the left-side.
The prompt to exit the program is also from the instructor's code.
```
                                Who-ville Grille
                                      Check


                  Roast Beast $ 15.98         Thank you for visiting us here
                     Who Hash $  4.75         at Who-ville Grille
               Truffula Fruit $  4.48
          Blueberry Bumplings $  5.55         Please come again soon!
               Butterfly Milk $  2.49
                               ------
                    Sub Total $ 33.25
                 Tax (10.00%) $  3.33
                 Tip (20.00%) $  6.65
                               ------
                    Total Due $ 43.23

Press "Enter" to Exit the program:
```
### Cancelled order

This run had the order cancelled from the get-go; as when a valid entry is made, the prompt is replaced, this time with a
new prompt confirming the cancellation. The method to generate the check is not called, instead the instructor's code
displays "You have elected NOT to enter an Order!" and the exit prompt without clearing the screen.
```
                                Who-ville Grille
                                      Menu


   1. Green Eggs & Ham           9.99      2. Roast Beast               15.98
   3. Wham Chops                13.29      4. Glunker Stew               7.35
   5. Who Hash                   4.75      6. Truffula Fruit             4.48
   7. Choc'late Mush-Mush        6.49      8. Blueberry Bumplings        5.55
   9. Goose Juice                1.99     10. Butterfly Milk             2.49


      Cancel your order (Y/N)? y

You have elected NOT to enter an Order!

Press "Enter" to Exit the program:
```

### Menu prompts; valid entries
This shows the actual prompt to enter the menu choice. The value to stop is actually calculated based on the size of the
menu; if I had twenty items on the menu it would show 21 instead.
```
                                Who-ville Grille
                                      Menu


   1. Green Eggs & Ham           9.99      2. Roast Beast               15.98
   3. Wham Chops                13.29      4. Glunker Stew               7.35
   5. Who Hash                   4.75      6. Truffula Fruit             4.48
   7. Choc'late Mush-Mush        6.49      8. Blueberry Bumplings        5.55
   9. Goose Juice                1.99     10. Butterfly Milk             2.49


      Enter Menu item #1 (11 to stop):
```

The user has made their first choice. The prompt is overwritten with their choice and the cursor is moved down a row.
Notice the prompt is now asking for item **#2**. The menu portion of the screen remains static and not being shown here.
```
   1. Green Eggs & Ham        $  9.99
      Enter Menu item #2 (11 to stop):
```
Only one item was ordered, "11" was entered to stop the order, causing the menu item prompt to be replaced with a 
confirmation prompt (again, the static menu is not included; otherwise it is the same screen)
```
   1. Green Eggs & Ham        $  9.99
      Is your order correct (Y/N)?
```

What happens when "n" is the answer; the cursor is after the : waiting for user to enter a menu choice.
Unlike other places, the confirmation prompt was not cleared (I would say this was an oversight and missed in testing)
```
   1. Enter Menu item #1 (11 to stop):
      Is your order correct (Y/N)? n
```

The order was re-entered and confirmed with a 'y' this time; passing control back out to the instructor's main().
```
   1. Green Eggs & Ham        $  9.99
      Is your order correct (Y/N)? Y

Press "Enter" when ready for the customer's check:
```
This is the check for the single item. This shows a minimal check; the right-side will never be taller than the left.
```
                                Who-ville Grille
                                      Check


             Green Eggs & Ham $  9.99         Thank you for visiting us here
                               ------         at Who-ville Grille
                    Sub Total $  9.99
                 Tax ( 1.00%) $  0.10         Please come again soon!
                 Tip ( 5.00%) $  0.50
                               ------
                    Total Due $ 10.59

Press "Enter" to Exit the program:
```
### Invalid entries

An out-of-range invalid menu choice was entered, failing validation. As a result, the error message to the right is
displayed, the invalid entry cleared and the cursor place back after the colon.

The 10 visible on the line is a correct entry before pressing enter again.
```
                                Who-ville Grille
                                      Menu


   1. Green Eggs & Ham           9.99      2. Roast Beast               15.98
   3. Wham Chops                13.29      4. Glunker Stew               7.35
   5. Who Hash                   4.75      6. Truffula Fruit             4.48
   7. Choc'late Mush-Mush        6.49      8. Blueberry Bumplings        5.55
   9. Goose Juice                1.99     10. Butterfly Milk             2.49


      Enter Menu item #1 (11 to stop): 10     Please use a whole number, 1-11
```

The error message is cleared from the right side once an entry if validated. For item #2's prompt, the user entered in
the actual item instead of its number (i.e., non-numeric entry).
```
   1. Butterfly Milk          $  2.49
      Enter Menu item #2 (11 to stop): Who Hash
```
As the entry is still invalid, the error message remains on screen. This time, a non-integer value is being entered.
```
   1. Butterfly Milk          $  2.49
      Enter Menu item #2 (11 to stop): 3.14   Please use a whole number, 1-11
```
While the cursor is moved/jumped around the command window, input and output still uses the standard I/O streams.
Pressing enter without typing anything else just drops the cursor to the next line. End result has an invalid entry
entered on a different line and not where it is expected to be.
```
   1. Butterfly Milk          $  2.49
      Enter Menu item #2 (11 to stop):        Please use a whole number, 1-11
-2
```
On to invalid entries for the order confirmation prompt. Invalid entries work the same way, with the appropriate error
message still showing on the right. The below capture shows the user entering a proper 'y' after the invalid entry was
cleared and the prompt to clear and show the check is now displayed.

The out-of-place invalid entry is still present on screen as it is outside where the cursor is being moved around.
```
   1. Butterfly Milk          $  2.49
   2. Roast Beast             $ 15.98
-2 3. Choc'late Mush-Mush     $  6.49
      Is your order correct (Y/N)? y          Was that a Y or N?

Press "Enter" when ready for the customer's check:
```
The screen is cleared before outputting the check; the out-of-place entry is now gone. This run was given a tax of 11.999
(12 is the max) and a tip of 18.50 (both valid). The tax and tip are only provided room for the two places past the
decimal point, resulting in the tax being rounded in format; the 2.99 reflects the 11.999; a 12% tax would show as 3.00. 
```
                                Who-ville Grille
                                      Check


               Butterfly Milk $  2.49         Thank you for visiting us here
                  Roast Beast $ 15.98         at Who-ville Grille
          Choc'late Mush-Mush $  6.49
                               ------         Please come again soon!
                    Sub Total $ 24.96
                 Tax (12.00%) $  2.99
                 Tip (18.50%) $  4.62
                               ------
                    Total Due $ 32.57

Press "Enter" to Exit the program:
```
