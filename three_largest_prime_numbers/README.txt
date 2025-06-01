Three Largest Prime Numbers in a Range — C Program
==================================================

This C program allows the user to enter two numbers, x and y, and then finds and displays up to the **three largest prime numbers** between them (inclusive). It validates input, handles range correction, and gives user-friendly output depending on the number of primes found.

---

📌 Program Objectives
---------------------

- Accept two integer inputs from the user (x and y)
- Ensure x ≤ y (swap if necessary)
- Check if the range is valid (i.e. contains numbers ≥ 2)
- Identify and display up to **three largest prime numbers** in the range
- Show appropriate messages if:
  - The range is invalid
  - No prime numbers are found
  - Only one or two prime numbers exist

---

📤 Expected Outputs
--------------------

- **Invalid Range**:  
  Prints `Invalid range!` if the range is below 2

- **No Primes Found**:  
  Prints `No prime numbers found.`

- **One Prime Found**:  
  Prints `There is one prime number: <number>`

- **Two Primes Found**:  
  Prints `The two prime numbers are: <number> <number>`

- **Three Primes Found**:  
  Prints `The three largest prime numbers are: <number> <number> <number>`

---

🔧 Required Functions
----------------------

You must implement the following five functions with correct types and parameters:

1. `void getInput(int *x, int *y);`  
   - Gets x and y from user input

2. `void swapValues(int *x, int *y);`  
   - Swaps x and y if x > y

3. `int primeChecker(int num);`  
   - Returns 1 if `num` is prime, else 0

4. `void getLargest(int x, int y, int *largest1, int *largest2, int *largest3);`  
   - Iterates through the range and stores up to 3 largest prime numbers in descending order

5. `void printLargest(int largest1, int largest2, int largest3);`  
   - Displays the output based on how many primes were found

---

🔄 Sample Flow
--------------

Enter value for x: 10
Enter value for y: 30

The three largest prime numbers are: 29 23 19


If x = 35 and y = 20, they will be swapped automatically.  
If the range is less than 2, prints:  
`Invalid range!`

---

🧠 Logic Overview
------------------

- A loop in `getLargest()` scans from y to x (descending)
- Each number is checked using `primeChecker()`
- The first three primes found are stored as `largest1`, `largest2`, and `largest3`
- These values are then passed to `printLargest()` to determine the appropriate message

---

📂 Main Function Format
------------------------

int main() {
int x, y, largest1 = 0, largest2 = 0, largest3 = 0;
getInput(&x, &y);
swapValues(&x, &y);

getLargest(x, y, &largest1, &largest2, &largest3);
printLargest(largest1, largest2, largest3);

return 0;


---

🧪 Sample Test Cases
---------------------

Case 1: x = 1, y = 10  
> Output: The three largest prime numbers are: 7 5 3

Case 2: x = 4, y = 4  
> Output: No prime numbers found.

Case 3: x = 0, y = 1  
> Output: Invalid range!

Case 4: x = 2, y = 2  
> Output: There is one prime number: 2

---

📎 Additional Notes
--------------------

- Prime check optimized up to √n
- All inputs assumed to be valid integers
- Additional helper functions may be added to improve modularity
- Easy to expand to return top N primes if needed

This exercise demonstrates loop design, recursion (optional), modular function usage, and number theory basics in C.