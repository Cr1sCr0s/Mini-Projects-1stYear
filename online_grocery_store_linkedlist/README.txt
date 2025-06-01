Online Grocery Store (Linked List Implementation) — Exercise 10
===============================================================

This C program simulates a fully functional online grocery store using singly linked lists. 
It supports dynamic inventory and customer tracking with no pre-defined limits on the number 
of grocery items or buyers.

---------------------------------------------------------------
Data Structures
---------------------------------------------------------------

This project uses three custom struct types:

1. Grocery Item
typedef struct groceryItems_tag {
    char item_name[30];
    float price;
    int stock;
    struct groceryItems_tag *nextItem;
} groceryItems;

2. Cart (per buyer)
struct cart {
    struct groceryItems_tag *item_bought;
    struct cart *nextItem;
};

3. Buyer
typedef struct buyer_tag {
    char name[30];
    struct buyer_tag *nextBuyer;
    struct cart *groceryItemsBought;
    float total_cost;
} buyer;

---------------------------------------------------------------
Main Menu
---------------------------------------------------------------

[1] Add Grocery Item  
[2] Buy Grocery Item  
[3] Edit Grocery Item  
[4] Delete Grocery Item  
[5] View All Grocery Items  
[6] View All Buyers  
[7] Exit

Invalid selections are detected and responded to with error messages.

---------------------------------------------------------------
Functionalities
---------------------------------------------------------------

1. Add Grocery Item
   - Inputs: name, price, stock
   - Rejects duplicates
   - Inserts new item in alphabetical order in the linked list

2. Buy Grocery Item
   - Checks if buyer exists; adds them if not
   - Displays grocery list
   - Buyer can purchase available (stock > 0) items
   - Stock decreases; buyer's total cost increases
   - Items added to buyer’s cart using dynamic node allocation

3. Edit Grocery Item
   - Allows modification of price and stock if item exists
   - Disallowed if item list is empty

4. Delete Grocery Item
   - Deletes item only if:
     - It exists
     - It has not been purchased by any buyer
   - Frees memory after removal

5. View All Grocery Items
   - Displays all grocery items including those with stock 0
   - Warns if list is empty

6. View All Buyers
   - Displays buyer names, items purchased, and total cost
   - Warns if no buyers exist

7. Exit
   - Triggers automatic data saving
   - Closes the program

---------------------------------------------------------------
Save & Load Data
---------------------------------------------------------------

File: groceryItem.txt
Format:
<item_count>
<item_name>
<price>
<stock>
...

File: buyers.txt
Format:
<buyer_count>
<buyer_name>
<item_count>
<item_name>
...
<total_cost>

- Files are automatically loaded on startup and saved on exit
- If files are missing or empty, appropriate error messages are shown
- A count of 0 is saved if there is no data

---------------------------------------------------------------
Compilation Instructions
---------------------------------------------------------------

To compile the program:
gcc grocery_store_linkedlist.c -o grocery_store
./grocery_store

---------------------------------------------------------------
Example Use Case
---------------------------------------------------------------

Welcome to the Online Grocery Store!

[1] Add Grocery Item  
[2] Buy Grocery Item  
...

> 1  
Enter item name: Hersheys Chocolate Milk Bar  
Enter price: 59  
Enter stock: 3  
Item added successfully.

> 2  
Enter buyer name: Pedro Pedro  
Available items:  
[1] Hersheys Chocolate Milk Bar — P59 — Stock: 3  
Enter item number to buy: 1  
Purchase successful. Pedro’s total cost: P59

---------------------------------------------------------------
Summary
---------------------------------------------------------------

This project demonstrates dynamic data handling using singly linked lists, 
real-world inventory modeling, and persistent file-based storage — all in C.
