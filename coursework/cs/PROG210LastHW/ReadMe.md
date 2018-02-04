# PROG210LastHW

## What does this program do?
It simulates a product order window. The user selects a customer and selects what product, cereal in this case, the
selected customer would like to purchase. Clicking the buy button performs the purchase and updates the status bar in the
lower window.

## Course
[Enterprise Software Development II](https://www.bellevuecollege.edu/classes/All/PROG/210)

## Assignment
This is the last assignment for the course. We did not have a "course" project.

The instructor didn't go by modules, chapters, units or such. He named the assignments based mostly on what he taught that
week. In this particular case, instead of calling it something along the lines of "distributed transaction" he simply called it "Last Homework" or rather, "PROG210LastHW."

The assignment gave the class a chance to try out distributed transactions and communicating with a database
in the cloud (Azure).

## Dependencies
- Azure account (freebie okay) and a pre-created database.
- SQL Server (Class uses 2012+).

## Notes
- At the time of the assignment, Azure did not permit distributed transactions; only the local database was placed inside a
  transaction.
- The success of writing to the Azure database did calculate in commiting the transaction.
- There are two methods of validation; the buy button only enables when both a custonmer and a product is selected, and the
  update queries to both tables include a minimum check (to counter negatives) in their where clauses.
- For testing purposes, I programmed a double-click of either grid (dataGridView) forces a refresh for both. This allowed
  me to modify the values outside the program and continue testing without restarting.

### Screen shots
![The program was just started; customers and products are loaded from the two databases](screenshots\no buy.JPG)
![A customer and product are selected, enabling the "Buy" button](screenshots\buy enabled.JPG)
![Purchase completed successfully per the status message](screenshots\buy succeeded.JPG)
![Customer's attempt to buy a product without enough funds is confirmed by the status message](screenshots\not enough funds.JPG)
![A customer snagged the last box of Frosted Flakes in inventory](bought last frosted flakes.JPG)
![A status message informing that a product out of stock cannot be sold](screenshots\out of stock.JPG)
![A customer without funds unsuccessfully attempts to buy a product](screenshots\out of funds.JPG)
![In the rare chance a customer without funds tries to buy a product without stock generates two staus messages](screenshots\two error messages.JPG)
