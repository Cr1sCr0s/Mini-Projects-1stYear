#include<stdio.h>
// 02/18/25

//GET INPUT
void getInput(int *x, int *y){

	//input
	printf("Enter x: ");
	scanf("%d", x);
	printf("Enter y: ");
	scanf("%d", y);

	return;
}


//SWAP VALUES
void swapValues(int *x, int *y){

	int temp; //to temporarily store the value of *y

	if(*x > *y){ //swap
		temp = *y;
		*y = *x;
		*x = temp;
	}

	return;
}


//PRIME CHECKER
int primeChecker(int i){
	if(i>=2){ //includes 2 as prime
		int count = 0; //tracks how many times remainder is 0
		for (int j = 1; j <= i; j++) { //iterates from 1 to i
			if (i % j == 0) //checks if when divided there is no remainder
				count++;
		}
		if (count == 2){ //if it is only divisible by 1 or itself then it is prime, return 1
			return 1;
		}
		else {
			return 0; //breaks the function, no prime numbers
		}
	}
	else {
		return 0;
	}
}


//GET LARGEST
void getLargest(int *x, int *y, int *prime1, int *prime2, int *prime3){

	for (int i = *x; i <= *y; i++){ //iterates from value of *x to *y
		if (i < 2) { //only starts if i >= 2
			continue;
		}
		else if (primeChecker(i) == 1){ //calls primeChecker with the current value of i
			if (i>*prime3){ //swap if there is a prime
				*prime1 = *prime2;
				*prime2 = *prime3;
				*prime3 = i;
			}
		}
		
	}

	return;
}


//PRINT LARGEST
void printLargest(int *prime1, int *prime2, int *prime3){

//as long as it is greater than 0, it will print the output
//if not say there are no prime numbers

	if (*prime1 > 0 && *prime2 > 0 && *prime3 > 0){
		printf("The three largest prime numbers are: %d %d %d", *prime3, *prime2, *prime1);
	} 
	else if (*prime2 > 0 && *prime3 > 0){
		printf("There are two prime numbers: %d %d", *prime3, *prime2);
	}
	else if (*prime3 > 0){
		printf("There is one prime number: %d",*prime3);
	}
	else {
		printf("There are no prime numbers");
	}

	return;
}


//MAIN FUNCTION
int main (){
	
	//variables
	int x;
	int y;
	int prime1 = 0;
	int prime2 = 0;
	int prime3 = 0;

	getInput(&x, &y);
	 //printf("%d\n%d\n", x,y);

	swapValues(&x, &y);
	 //printf("%d\n%d\n", x,y);

	if (x < 2 && y < 2){ //checks if bot inputs are less than 2
		printf("Invalid range!\n");
	} //calls getLargest and printLargest function
	else {
		getLargest(&x, &y, &prime1, &prime2, &prime3);
		printLargest(&prime1, &prime2, &prime3);
	}

	return 0;
}

