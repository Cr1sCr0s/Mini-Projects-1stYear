Population Growth Calculator in C (Recursive)
=============================================

This C program calculates the projected population after a given number of years using a recursive function. The program prompts the user for the **initial population**, **annual growth rate**, and **number of years**, and performs the calculation based on user input.

The program features a menu that loops continuously until the user chooses to exit.

---

📈 How It Works
---------------

The program uses the formula:

Population after x years =  
P(x) = P(x-1) + (P(x-1) * growth_rate)

Where:
- `P(x)` is the population after `x` years
- `growth_rate` is entered as a percentage and internally converted to decimal

**Recursive Definition:**

P(0) = initial population
P(x) = P(x-1) + (P(x-1) * growth_rate)


---

📋 Program Menu
---------------

The menu presents the following options:

1. **Calculate population growth**  
   - Prompts user to enter:
     - Initial population (n)
     - Annual growth rate in % (y)
     - Number of years (x)
   - Uses recursion to calculate population for each year
   - Displays the final population rounded to **2 decimal places**

2. **Exit program**  
   - Ends the session gracefully

If the user enters an invalid menu option, an **error message is shown** and the menu is redisplayed.

---

🧪 Sample Calculation
---------------------

Inputs:
- Initial population: 13245  
- Annual growth rate: 2  
- Years: 4

Computation:
- Year 1: 13245 + (13245 * 0.02) = 13509.90  
- Year 2: 13509.90 + (13509.90 * 0.02) = 13780.10  
- Year 3: 13780.10 + (13780.10 * 0.02) = 14055.70  
- Year 4: 14055.70 + (14055.70 * 0.02) = 14336.81

Final Output:
> Population after 4 years: 14336.81

---

🔄 Program Flow
---------------

- Menu is displayed in a loop  
- User chooses to calculate or exit  
- All input values are validated  
- Recursive calculation is used instead of loops  
- Output is formatted to 2 decimal places using `%.2f`

---

📌 Notes
--------

- Growth rate is entered as a percentage but calculated as a decimal (e.g., 2 → 0.02)
- Input must be valid positive numbers for accurate results
- Program emphasizes recursion, not iteration, as a learning goal
- Includes error handling for invalid menu choices

This exercise reinforces understanding of recursion, function design, input validation, and basic output formatting in C.