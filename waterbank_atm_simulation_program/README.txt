WATER BANK - ATM Simulation Program in C
===========================

This C program simulates the basic functionalities of an ATM system using a console-based menu. It includes balance inquiry, deposit and withdrawal options, PIN management, and secure access before every transaction. The user interacts with the system using menu choices, and all operations are protected by a 4-digit PIN.

---

🧾 Features
-----------

1. Check Balance  
- Displays the current account balance after successful PIN entry.

2. Deposit  
- Prompts the user to enter the deposit amount.
- Adds the amount to the current balance and confirms the transaction.

3. Withdraw  
- Displays the current balance.
- Prompts the user to enter the withdrawal amount.
- Deducts the amount only if it does not exceed the current balance.
- Displays a warning if the withdrawal exceeds available funds.

4. Change PIN  
- Requests the user’s current PIN.
- If correct, allows the user to enter a new 4-digit PIN.
- Rejects PINs that are not exactly 4 digits.

5. End Transaction  
- Exits the program gracefully.

---

🔐 Security
-----------
- The user must **enter the correct PIN before every transaction**.
- The default PIN is **1234**.
- PIN changes are validated to be exactly **4 digits** long.
- Invalid PIN entries do not allow access to any transaction.

---

💻 Program Behavior
-------------------

- The program starts with a main menu and loops until **End Transaction** is selected.
- User is prompted for the PIN before each menu option is executed.
- All numeric inputs are validated (e.g., non-negative deposit, valid withdrawal amount).
- Uses variables to track `balance` and `pin` throughout the session.
- Error messages and prompts are provided for invalid input cases.

---

📌 Example Interaction
----------------------

Welcome to the ATM System

Enter your 4-digit PIN: 1234

[1] Check Balance
[2] Deposit
[3] Withdraw
[4] Change PIN
[5] End Transaction

2

Your current balance is: P5000.00
Enter deposit amount: 1500

Deposit successful. New balance: P6500.00


---

📎 Summary
----------

This program provides a simple yet secure simulation of an ATM interface in C. It introduces key concepts such as:
- User authentication
- Input/output handling
- Conditional logic and loops
- Basic data validation

The design ensures a user-friendly and secure interaction, emulating the core operations of a real-world ATM.