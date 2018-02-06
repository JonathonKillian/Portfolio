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

The program was just started. Customers and products are loaded from the two databases. No selections are made resulting
in the "Buy" button being disabled.<br/>
![The buy button is disabled due to no selections](screenshots/disabled.JPG)

A customer and product are selected, enabling the "Buy" button.<br/>
![The buy button is enabled due to selections made](screenshots/enabled.JPG)

A purchase is successful.<br/>
![Status message showing completed purchase](screenshots/succeeded.JPG)

A customer attempted to buy cereal without enough funds.<br/>
![Status message showing non-sufficient funds](screenshots/insufficient.JPG)

A customer bought the last box of Frosted Flakes.<br/>
![Status message showing completed purchase and Frosted Flakes inventory shows zero](screenshots/last.JPG)

A customer attempts to purchase an out-of-stock cereal.<br/>
![Status message reporting the ordered product out of stock](screenshots/out.JPG)

Both error messages can be triggered together.<br/>
![Status message shows both insufficient funds and out-of-stock](screenshots/errors.JPG)
