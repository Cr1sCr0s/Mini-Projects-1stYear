# BMI Calculator in C

This C program calculates the **Body Mass Index (BMI)** of a user and classifies it based on standard health categories. The program uses a **menu-driven interface** and supports both **Metric** and **Standard** measurement systems. The application runs in a loop until the user chooses to exit.

---

## 📋 Menu Options

### 1. Metric  
- Prompts for weight in **kilograms**  
- Prompts for height in **centimeters**  
- Calculates BMI using:  
  `BMI = weight_kg / (height_meters)^2`

### 2. Standard  
- Prompts for weight in **pounds**  
- Prompts for height in **feet and inches**  
- Calculates BMI using:  
  `BMI = (weight_lbs / (height_inches)^2) * 703`

### 3. Exit  
- Exits the program gracefully

---

## 🧠 BMI Classification

| Category       | BMI Range           |
|----------------|---------------------|
| Underweight    | Less than 18.5      |
| Normal weight  | 18.5 to less than 25|
| Overweight     | 25 to less than 30  |
| Obese          | 30 and above        |

---

## ✅ Program Behavior

- The menu **repeats in a loop** until "Exit" is selected
- BMI is calculated and printed after each input
- Classification is displayed immediately
- Input validation ensures **positive height and weight**
- BMI is not rounded for simplicity

---

## 💻 Example Output

Select a measurement system:
[1] Metric
[2] Standard
[3] Exit

Enter weight in kilograms: 70
Enter height in centimeters: 175

Your BMI is: 22.857142
You are classified as: Normal weight


---

## ⚙️ Build & Run

To compile and run the program:

gcc bmi_calculator.c -o bmi
./bmi


---

## 📎 Additional Notes

- Metric height is converted from **centimeters to meters**
- Standard height is converted to **inches**
- Program uses `switch-case`, loops, and conditionals
- A practical introduction to numeric operations and basic control structures in C