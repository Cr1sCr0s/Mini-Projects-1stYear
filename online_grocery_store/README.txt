Online Grocery Store — C Structures Program
===========================================

This C program simulates an online grocery store using **structures**. It supports basic CRUD (Create, Read, Update, Delete) operations for grocery inventory, buyer transactions, and data persistence via file I/O. The application runs continuously until the user selects Exit.

---

🗂 Data Structures
------------------

1. **GroceryItem**  
   - `char name[50]`  
   - `float price`  
   - `int stock`

2. **Buyer**  
   - `char name[50]`  
   - `GroceryItem orders[5]`  
   - `float totalCost`

- Maximum of **10 grocery items** and **10 buyers** can be stored at a time.

---

📋 Main Menu
------------

[1] Add Grocery Item
[2] Buy Grocery Item
[3] Edit Grocery Item
[4] Delete Grocery Item
[5] View All Grocery Items
[6] View All Buyers
[7] Exit


Invalid inputs are detected and reported.

---

🛒 Functionalities
------------------

1. **Add Grocery Item**  
   - User inputs item name, price, and stock.  
   - Duplicate item names are not allowed.

2. **Buy Grocery Item**  
   - User enters buyer's name. If not found, a new buyer is added.  
   - Lists available grocery items.  
   - User selects an item to buy (stock must be > 0).  
   - Updates:
     - Buyer's orders (up to 5 items)
     - Item stock
     - Buyer's total cost

3. **Edit Grocery Item**  
   - User enters item name. If found, can modify price and stock.  
   - No edits if there are no items.

4. **Delete Grocery Item**  
   - User enters item name to delete.  
   - Item is removed if found.  
   - Deletion not allowed if item list is empty.

5. **View All Grocery Items**  
   - Displays all items regardless of stock level.  
   - Prints message if no items exist.

6. **View All Buyers**  
   - Displays name, item list, and total cost for each buyer.  
   - Prints message if there are no buyers.

7. **Exit**  
   - Saves all data before exiting.
   - Prints exit message.

---

💾 Data Persistence
-------------------

**Files Used:**
- `groceryItem.txt`  
- `buyers.txt`

**Save Behavior:**
- Data is saved to files **automatically on Exit**
- Separate files are used for grocery items and buyers
- If there is no data to save, a message is printed

**Sample Save Format:**

*`groceryItem.txt`*
2
Hersheys Chocolate Milk Bar
59
1
Coca-Cola Cherry Coke 12oz
69
3

*`buyers.txt`*
2
Pedro Pedro
3
Coca-Cola Cherry Coke 12oz
Hersheys Chocolate Milk Bar
Hersheys Chocolate Milk Bar
187
Hayley Williams
1
Coca-Cola Cherry Coke 12oz
69


**Load Behavior:**
- Program attempts to **automatically load data** from files on startup.
- Displays an error message if files are missing.

---

📌 Notes
--------

- All user actions include **success** or **error** messages.
- File loading and saving are seamlessly integrated.
- Robust validation ensures reliable operations.
- Dynamic user interaction and structured data management are demonstrated clearly in this project.

---

Make sure `groceryItem.txt` and `buyers.txt` exist in the same directory to load data on program start.

---

This project reinforces concepts of:
- Structures and nested structures
- Arrays and string handling
- Menu-driven programming
- File I/O in C
- Input validation and user interaction
