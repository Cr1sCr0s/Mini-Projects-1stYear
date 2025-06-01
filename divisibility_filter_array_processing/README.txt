Divisibility Filter — JavaScript Array Processing
==================================================

This JavaScript program demonstrates the use of loops, conditionals, and the built-in `Math` library to work with a randomly generated array of integers. It filters values based on divisibility conditions and prints the results to the browser console.

---

🧮 Features
-----------

- Generates a **random array of 10 unique integers** between 1 and 100 using `Math.random()` and `Math.floor()`.
- Filters the array into three new arrays containing:
  1. Integers divisible by **both 2 and 5**
  2. Integers divisible by **2 only**
  3. Integers divisible by **5 only**
- **Prints all arrays** to the browser console on page load.

---

⚙️ How It Works
---------------

### Main Functions:
- `generateRandomArray()`: Creates an array of 10 non-repeating random integers from 1–100.
- `filterDivisibleBy2And5(arr)`: Returns values divisible by both 2 and 5.
- `filterDivisibleBy2(arr)`: Returns values divisible by 2.
- `filterDivisibleBy5(arr)`: Returns values divisible by 5.

### Page Behavior:
- The main logic runs automatically when the page loads.
- The final output is logged in the **browser console**.

---

🖥 How to Check the Console Output
----------------------------------

1. **Open the HTML file** in a modern web browser (e.g., Chrome, Firefox, Edge).
2. **Right-click** anywhere on the page and select **"Inspect"** or press `Ctrl + Shift + I` (Windows) or `Cmd + Option + I` (Mac).
3. Click the **"Console"** tab in the developer tools.
4. You will see the original random array and the filtered results printed clearly.

---

📁 File Structure
------------------

index.html        → HTML file linking to the script and showing instructions  
script.js         → JavaScript file containing all logic  
README.txt        → This documentation file

---

📌 Requirements Fulfilled
-------------------------

✔ Generates 10 **unique random integers** between 1 and 100  
✔ Uses `Math.random()` and `Math.floor()` for randomness  
✔ Uses **loops** and **conditional statements**  
✔ Uses **no external libraries** (only built-in Math)  
✔ Automatically runs on page load  
✔ Prints to the browser console  
✔ Provides clear instructions on how to open the console

---

This project demonstrates fundamental JavaScript concepts like control flow, array manipulation, and browser console interaction using only built-in functionality.
