Silverlock's Coffee Shop — Cash Register Program
================================================

A simple cash register program for **Silverlock's Coffee Shop**.
The store offers a delivery-only service and sells a variety of coffee drinks.

1. Main Menu Function
---------------------
displays the main menu with the following options:

    [1] Choose coffee  
    [2] Enter discount coupon  
    [3] Compute total and pay  
    [0] Exit

The function should return the user's choice.

---

2. Choose Coffee Function
--------------------------
A function for option [1] Choose coffee.  
The function should print the available menu items:

    [1] Espresso     : P150.00  
    [2] Cappuccino   : P200.00  
    [3] Latte        : P180.00  
    [4] Americano    : P140.00  
    [5] Mocha        : P220.00  
    [0] Back to main menu

- The user must input their choice.
- The user can select multiple items.
- The function should keep track of the **total price** of selected coffee drinks.
- When option [0] is chosen, the function should return the **total price** and return to the main menu.

---

3. Discount Coupon Function
---------------------------
A function for option [2] Enter discount coupon.

- The function takes the total price as a parameter.
- Prompt the user to enter a discount coupon.
- Check the validity of the coupon and apply the appropriate discount:

    "COFFEELOVER" → 15% discount  
    "FREESHOT"    → 10% discount  

- If the coupon is invalid, return the total price (no discount).

---

4. Compute Total and Pay Function
---------------------------------
A function for option [3] Compute total and pay.

The function takes the total price (after selecting drinks and applying discount) and does the following:

A. Display the Total Price  
   - Show the current total price.

B. Add Delivery Charge  
   - Add and display a 7% delivery charge.  
   - Use a **function** to calculate the total with the delivery charge.

C. Apply Senior Citizen or PWD Discount (Bonus)  
   - Ask the user: “Do you have a PWD or Senior Citizen ID?” (Enter 1 for Yes, 0 for No)  
   - If yes, apply a 20% discount **after adding the delivery charge**.  
   - Use a **function** to calculate this discounted price.  
   - If no, simply show the total price with the delivery charge.

D. Payment  
   - Ask the user how much they are paying.  
   - Display the change.

---

💡 Notes:
- Ensure the user experience is smooth with clear prompts and outputs.
- Modularize your code using separate functions for each feature.
- Handle invalid inputs gracefully.

