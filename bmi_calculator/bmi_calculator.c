/*
02/04/25
*/

#include <stdio.h>
int main() {
	//variables needed
	int menu;
	
	float weight;
	float height;
	
	float pounds;
	float feet;
	float inches;
	
	float bmi;
	
	//do while menu
	do {
		//menu
		printf("\nMENU\n");
		printf("[1] Metric\n");
		printf("[2] Standard\n");
		printf("[3] Exit\n");
		
		printf("Please enter your choice: ");
		scanf("%d", &menu);
		
		//metric
		if (menu == 1) {
			printf("Enter weight in kilograms: ");
			scanf("%f", &weight);
			
			printf("Enter height in centimeters: ");
			scanf("%f", &height);
			
			//calculations
				//printf("%f",height);
			height = height/100;
			height = height*height;
			bmi = weight/height;
			printf("Your BMI is: %f\n", bmi);
			
			//bmi category
			if (bmi < 18.5) {
				char class[] = "underweight";
				printf("BMI Category: %s\n", class);
			} else if (bmi >= 18.5 && bmi < 25) {
				char class[] = "normal";
				printf("BMI Category: %s\n", class);
			} else if (bmi >= 25 && bmi < 30) {
				char class[] = "overweight";
				printf("BMI Category: %s\n", class);
			} else {
				char class[] = "obese";
				printf("BMI Category: %s\n", class);
			}
		}
		
		//standard
		else if (menu == 2) {
			printf("Enter weight in pounds: ");
			scanf("%f", &pounds);
			
			printf("Enter height in feet: ");
			scanf("%f", &feet);
			
			printf("Enter height in inches: ");
			scanf("%f", &inches);
			
			//calculations
			
			height = feet*12;
				//printf("1st: %f\n",height);
			height = height + inches;
				//printf("2nd: %f\n",height);
			height = height * height;
				//printf("3rd: %f\n",height);
			bmi = (pounds/height) *703;
			
			printf("Your BMI is: %f\n", bmi);
			
			//bmi category
			if (bmi < 18.5) {
				char class[] = "underweight";
				printf("BMI Category: %s\n", class);
			} else if (bmi >= 18.5 && bmi < 25) {
				char class[] = "normal";
				printf("BMI Category: %s\n", class);
			} else if (bmi >= 25 && bmi < 30) {
				char class[] = "overweight";
				printf("BMI Category: %s\n", class);
			} else {
				char class[] = "obese";
				printf("BMI Category: %s\n", class);
			}
		}
	//exit
	} while (menu != 3);
	
	
	return 0;
}
