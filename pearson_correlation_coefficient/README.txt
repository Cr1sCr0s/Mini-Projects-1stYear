Pearson Correlation Coefficient in C
=================================================

This program calculates the **Pearson Correlation Coefficient (r)** between the **weights (kg)** and **lengths (cm)** of 10 newborn babies using arrays and a 2D summary table.

It demonstrates array operations, mathematical formula implementation, and correlation analysis using the C programming language.

---

📊 Dataset
---------

The following values are used:

Weight (kg):  
3.63, 3.02, 3.82, 3.42, 3.59, 2.87, 3.03, 3.46, 3.36, 3.30

Length (cm):  
53.1, 49.7, 48.4, 54.2, 54.9, 43.7, 47.2, 45.2, 54.4, 50.4

---

📐 Formula Used
---------------

Pearson Correlation Coefficient (r):

r = [n(∑xy) - (∑x)(∑y)] / sqrt{ [n∑x² - (∑x)²][n∑y² - (∑y)²] }


Where:
- `x` = weight
- `y` = length
- `n` = 10 (number of babies)

---

🧠 Program Features
-------------------

- Uses **1D arrays** to store weight and length data
- Uses a **2D array** to compute and store:
  - x (weight)
  - y (length)
  - x²
  - y²
  - xy

- Uses `sqrt()` from `<math.h>` to compute square root
- Outputs a well-formatted **summary table**
- Computes and displays the Pearson coefficient `r`
- Interprets the correlation using the standard strength table below

---

📋 Interpretation Table
------------------------

| r Value Range         | Strength of Relationship |
|-----------------------|--------------------------|
| 0.90 to 1.00 or -0.90 to -1.00 | Very Strong       |
| 0.70 to 0.89 or -0.70 to -0.89 | Strong            |
| 0.40 to 0.69 or -0.40 to -0.69 | Moderate          |
| 0.10 to 0.39 or -0.10 to -0.39 | Weak              |
| 0.00 to 0.09 or -0.00 to -0.09 | Negligible        |

---

🖥 Sample Output Format
------------------------

| x    | y    | x^2 | y^2 | xy  |
| ---- | ---- | --- | --- | --- |
| 3.63 | 53.1 | ... | ... | ... |
| ...  |      |     |     |     |

Sum of x: ...
Sum of y: ...
Sum of x^2: ...
Sum of y^2: ...
Sum of xy: ...

Pearson r: 0.58
Interpretation: Moderate positive correlation


(`-lm` links the math library required for `sqrt()`)

---

📌 Notes
--------

- You are required to use a 2D array to store and print the summary table.
- `float` or `double` types should be used to maintain precision.
- The program helps reinforce understanding of:
  - Array indexing
  - Mathematical operations in C
  - Correlation and statistical analysis
