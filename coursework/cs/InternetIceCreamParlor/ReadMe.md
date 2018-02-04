# Internet Ice Cream Parlor

## What does this program do?
It simulates an online store where an employee can add product and a customer can purchase a product one item at a time.

## Course
[Web Development II](https://www.bellevuecollege.edu/classes/All/PROG/117)

## Assignment
This is the final project. The course assignments all built upon this program.

## Dependencies
- ADO.Net 4.5
- SQL Server (Class used 2012+)

## Notes
- At the beginning of the course, we were asked what we wanted to "sell." I humorously chose ice cream.
- All SQL commands were sent in plain text; as commented upon in the code, the instructor kept reinforcing that this is
  not safe but that this facilitated the learning. Another [course](https://www.bellevuecollege.edu/classes/All/PROG/210)
  did show safer methods.
- Part of the assignment included emailing the customer when they purchased an item; however, this has been disabled due to
  the lack of password security for my gmail account being built in. The section of code is still present in the Page_Load
  method in the [oneclickBuy.aspx.cs](InternetIceCreamParlor/shopping/oneclickBuy.aspx.cs) file for review.
- The sign up pages were from an earlier assignment; their look was not updated to match the main page and product pages.
- When ordering a product, the user is presented with a humorous take on "one-click buy" in the form of "one lick buy".

## Screen shots
Note: These are not full screen images. Most have a sliver of the
[banner graphic](InternetIceCreamParlor/InternetIceCreamParlor/img/neonicecream.png)
![Initial screen with no logged in user](screenshots/firstRun.JPG)
![A user logged in and is greeted. Login box is switched to logout link](screenshots/login.JPG)
![The user logged out, and given a farewell message](screenshots/logout.JPG)
!["New products" and "Products" links return non-logged-in users back to main with status message](screenshots/bounce.JPG)
![Sign up page with a user's information typed in.](screenshots/Signup1.JPG)
![Confirmation page showing new user information and 2 links](screenshots/Signup2.JPG)
![Update page with user's information pre-filled. The user modified their password](screenshots/Signup3.JPG)
![Update confirmation page](screenshots/Signup4.JPG)
!["New product" page; with a sample product already entered](screenshots/adding.JPG)
![Products page showing single _lick_ buy](screenshots/products.JPG)
![Purchase confirmation screen showing a receipt in letter form. An email of same wording would have been emailed](screenshots/Purchased.JPG)
