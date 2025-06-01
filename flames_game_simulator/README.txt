F-L-A-M-E-S Game Simulator in C
===============================

This C program simulates the classic F-L-A-M-E-S compatibility game. It takes the user's name and a list of their crushes, then computes a "relationship result" for each crush based on the FLAMES algorithm.

---

📌 Program Features
-------------------

- Accepts **user's name** and the number of crushes
- Stores crush names using a **dynamic 2D array** (using `malloc`)
- Handles **name normalization**:
  - Converts all characters to **lowercase**
  - **Removes whitespaces**, numbers, and special characters
- Computes and displays the **FLAMES result** for each crush name

---

🔢 FLAMES Computation Steps
----------------------------

1. **Normalize** both names (user and crush):
   - Convert to lowercase
   - Remove all non-alphabetic characters

2. **Remove common letters** from both names

3. **Count** the total number of characters remaining

4. Use the count to **eliminate letters** from "FLAMES" one by one:
   - Start from `F`, wrap around circularly
   - Remove the letter at the position of the count
   - Repeat until **one letter remains**

5. Map the final letter to the relationship meaning:

| Letter | Meaning       |
|--------|----------------|
| F      | Friends        |
| L      | Lovers         |
| A      | Affectionate   |
| M      | Married        |
| E      | Enemies        |
| S      | Soulmates      |


---

🛠 Technical Details
--------------------

- Uses `malloc` to create a **dynamic 2D array** for crush names
- Maximum name length: **50 characters**
- Each crush is processed independently
- FLAMES elimination is implemented with character rotation logic

---

🚨 Input Validation
--------------------

- Ensures number of crushes is valid (> 0)
- Handles names containing only valid characters
- Sanitization of names ensures consistent matching behavior

---

📎 Summary
----------

This project demonstrates the use of:
- Dynamic memory allocation
- 2D character arrays
- String processing and cleanup
- Classic logic-based games implemented through arrays and loops

It provides a fun way to apply foundational C concepts in a lighthearted, engaging context.
