#include<stdio.h>
// 02/18/25

//MENU
int menu() {

	printf("\nPOPULATION GROWTH CALCULATOR\n");
	printf("[1] Compute\n");
	printf("[2] Exit\n");
	
	int menu;
	
	printf("Enter your choice: ");
	scanf("%d", &menu);
	
	return menu;
}


//COMPUTATION
float growthCalculator(double n, float y, int x) {
	
	//printf("%f\n",n);
	//printf("%f\n",y);
	//printf("%d\n\n",x);
	
	if (x == 0) { //Base Case, return population if year is 0
		return n;
	}
	else { //Recursive Case
		return growthCalculator(n+(n*y), y, x-1);
		//n+(n*y) - current population + (2% of current population), changes every year
		//y - growth in decimal, constant
		//x-1 - reduces by a year after every iteration
	}
}


//INPUT & OUTPUT
int growth() {
	
	//varibles
	int x; //years 
	double n; //population, 
	float y; //growth rate
	
	//input
	printf("Enter population (n): ");
	scanf("%lf", &n);
	printf("Enter growth rate (y%%): ");
	scanf("%f", &y);
	y /= 100; //convert percent to decimal
	printf("Enter years (x): ");
	scanf("%d", &x);
	
	//computation call function
	n = growthCalculator(n, y, x);
	
	//output
	printf("After %d years(s) at a %0.0f%% growth rate, the population will be %0.2lf\n", x, y, n);
	
	return 0;
}


//MAIN
int main() {

	//variables to use
	int menuChoice;

	//do while menu
	do {
		menuChoice = menu();
		
		//computation
		if (menuChoice == 1) {
			growth();
		}
		
		//checks for other input
		else if (menuChoice > 2) {
			printf("incorrect manu input\n");
		}
		
	} while (menuChoice != 2); //terminates program
	
	return 0;
}
