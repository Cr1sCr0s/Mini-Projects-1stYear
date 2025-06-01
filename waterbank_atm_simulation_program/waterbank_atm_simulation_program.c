#include<stdio.h>
// 02/11/25

//MENU
int menu() {

	printf("\nWELCOME TO WATER BANK\n");
	printf("[1] Check Balance\n");
	printf("[2] Deposit\n");
	printf("[3] Withdraw\n");
	printf("[4] Change PIN\n");
	printf("[5] End Transaction\n");
	
	int menu;
	
	printf("Please enter your choice: ");
	scanf("%d", &menu);
	
	return menu;
}


//DEPOSIT
int deposit(int balance) {
	
	//variables to use
	int deposit;
	
	//do while function incase input is below 0
	do {
		printf("Current Balance: %d PHP\n",balance);
		printf("Deposit Amount: ");
		scanf("%d",&deposit);
		
		if (deposit < 0) {
			printf("cannot be below 0");
		}
		
	} while (deposit < 0);
	
	//changes balance
	balance = balance + deposit;
	
	return balance;
}


//WITHDRAW
int withdraw(int balance) {

	//variables to use
	int withdraw;
	
	//do while function to make sure withdraw amount is less than current balance
	do {
		printf("Current Balance: %d PHP\n",balance);
		printf("Withdrawal Amount: ");
		scanf("%d",&withdraw);
		
		if (withdraw > balance) {
			printf("insufficient balance!\n");
		}
		
	} while (withdraw > balance);
	
	//change balance
	balance = balance - withdraw;
	
	return balance;
}


//CHANGE PIN
int changePin(int pin) {

	//variables to use
	int newPin;

	//ask for new pin
	printf("Enter your new 4-digit PIN: ");
	scanf("%d",&newPin);
	
	if (newPin >= 1000 && newPin <= 9999) { //cannot be <= 999 and >= 10,000
		pin = newPin;
		printf("PIN successfully changed!\n");
	}
	
	else {
		printf("invalid PIN\n");
	}
	
	return pin;
}


//PIN FUNCTION
void pinFunction(int pin) {
	
	//variables to use
	int inputPin;
	
	//do while function for correct pin
	do {
		
		printf("Please enter your 4-digit PIN: ");
		scanf("%d", &inputPin);
	
		if (inputPin != pin) {
			printf("incorrect PIN\n");
		}
		
		
	} while (inputPin != pin);
	
	return;
}


//MAIN
int main() {

	//variables to use
	int menuChoice;
	int balance = 0;
	int pin = 1234;
	
	
	//do while menu
	do {
		menuChoice = menu();
		
		//checkBalance, asks for pin
		if (menuChoice == 1) {
			pinFunction(pin);
			printf("Balance: %d PHP\n",balance);
		}
		
		//deposit call function, asks for pin, updates balance
		else if (menuChoice == 2) {
			pinFunction(pin);
			balance = deposit(balance);
			printf("Updated balance: %d PHP\n",balance);
		}
		
		//withdraw call function, asks for pin, updates balance
		else if (menuChoice == 3) {
			pinFunction(pin);
			balance = withdraw(balance);
			printf("Updated balance: %d PHP\n",balance);
		}
		
		//change pin function, asks for pin
		else if (menuChoice == 4) {
			pinFunction(pin);
			pin = changePin(pin);
		}
		
		//terminates program
		else {
			break;
		}
		
	} while (menuChoice != 5);
	
	return 0;
}
