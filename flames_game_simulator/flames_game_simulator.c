#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> //tolower() is alpha()
// 03/19/25

//MENU
int menu() {
	int menu;
	printf("\nFLAMES GAMES\n");
	printf("[1] Input names\n");
	printf("[2] Compute FLAMES results\n");
	printf("[3] Exit\n");
	
	printf("Enter your choice: ");
	scanf("%d", &menu);
	while (getchar() != '\n'); //Clear input buffer
	
	return menu;
}

//INPUTNAMES
void inputNames(int crushCount, char ***crushNames) {
	//variables
	int i;
	char name[50], filteredName[50];
	
    //Allocate memory for crush names, 2d Array
    *crushNames = (char **)malloc((crushCount) * sizeof(char *));

	//input crush names
    for (i = 0; i < crushCount; i++) { 
        printf("Enter name of crush #%d: ", i + 1);
        fgets(name, sizeof(name), stdin);

        //Convert to lowercase and remove unwanted characters
        int j = 0;
        for (int k = 0; name[k] != '\0'; k++) {
            if (isalpha(name[k])) {  //Check if character is a letter
                filteredName[j] = tolower(name[k]); //Convert to lowercase and store
				j++;
            }
        }
        filteredName[j] = '\0'; //Null-terminate the cleaned string

        //Allocate some memory for each name, 2D array
        (*crushNames)[i] = (char *)malloc((strlen(filteredName) + 1) * sizeof(char));
        //Copy filtered name into allocated memory
        strcpy((*crushNames)[i], filteredName);
    }
}

//COMPUTEFLAMES
void computeFlames(int crushCount, char *filteredUserName,char **crushNames) {
	//variables
	int i, j, characterCount, flamesIndex;
	char flames[] = "FLAMES";

	for(i = 0; i < crushCount; i++){  //iterate each row
		char userCopy[50], crushCopy[50], flamesCopy[10];

        //make duplicates
        strcpy(userCopy, filteredUserName);
        strcpy(crushCopy, crushNames[i]);
		strcpy(flamesCopy, flames);

        //Remove common letters in username and crush names
        for (j = 0; userCopy[j] != '\0'; j++) {
            for (int k = 0; crushCopy[k] != '\0'; k++) {
                if (userCopy[j] == crushCopy[k]) {  
                    userCopy[j] = '*';  //Mark as removed
                    crushCopy[k] = '*';
                    break; 
                }
            }
        }

		//DEBUGGING
		/*
        printf("Marked User:  %s\n", userCopy);
        printf("Marked Crush: %s\n", crushCopy);
		*/

        // Count remaining characters
        characterCount = 0;
        for (j = 0; userCopy[j] != '\0'; j++) {
            if (userCopy[j] != '*')
				{characterCount++;} } //from userCopy
        for (j = 0; crushCopy[j] != '\0'; j++) {
            if (crushCopy[j] != '*')
				{characterCount++;} } //from crushCopy

		printf("\nCrush #%d: %s\n", i + 1, crushNames[i]);
		printf("Remaining character count: %d\n", characterCount);

		//computing for last flames letter
		flamesIndex = 0;
		int flamesLength = strlen(flamesCopy);
		
		//DEBUGGING
		/*
		printf("Initial FLAMES: %s\n", flamesCopy);
		*/

		while (flamesLength > 1) { //while loop, stop when one letter left
			//index plus characterCount, minus 1 becuase index
			//% flamesLength to count from start again
			flamesIndex = (flamesIndex + characterCount - 1) % flamesLength;
		
			//DEBUGGING
			/*
			printf("Removing '%c' at index %d\n", flamesCopy[flamesIndex], flamesIndex);
			*/

			//Manually shift the letters, left
			for(j = flamesIndex; j < flamesLength - 1; j++) {
				flamesCopy[j] = flamesCopy[j + 1];
			}
			flamesLength--; //Reduch length of remaining letters
			flamesIndex = 0;

			//DEBUGGING
			/*
			printf("FLAMES after removal: ");
			for (int k = 0; k < flamesLength; k++) {
				printf("%c", flamesCopy[k]);
			}
			printf("\n");
			*/

		}

		//check meaning based on remaining letter, the table
		if (flamesCopy[0] == 'F'){
			printf("FLAMES result: Friends\n"); }
		else if (flamesCopy[0] == 'L'){
			printf("FLAMES result: Love\n"); }
		else if (flamesCopy[0] == 'A'){
			printf("FLAMES result: Affection\n"); }
		else if (flamesCopy[0] == 'M'){
			printf("FLAMES result: Marriage\n"); }
		else if (flamesCopy[0] == 'E'){
			printf("FLAMES result: Enemy\n"); }
		else if (flamesCopy[0] == 'S'){
			printf("FLAMES result: Siblings\n"); }

	}

}

//MAIN
int main() {
	//variables and arrays
	int menuChoice, crushCount, i;
	char userName[50], filteredUserName[50];
	char **crushNames = NULL;

	//input username
	printf("Enter your name: ");
	scanf(" %[^\n]", userName);
	
	//input no. of crushes
	printf("Enter the number of your crushes: ");
	scanf("%d", &crushCount);
	while (getchar() != '\n'); //clear input buffer

	//Convert to lowercase and remove unwanted characters
	int j = 0;
	for (i = 0; userName[i] != '\0'; i++) {
		if (isalpha(userName[i])) {  //Check if character is a letter
			filteredUserName[j] = tolower(userName[i]); //Convert to lowercase and store
			j++;
		}
	}
	filteredUserName[j] = '\0'; //end string with termination character

	//do while menu
	do {
		menuChoice = menu();
		
		if (menuChoice == 1) { //call inputNames
			inputNames(crushCount, &crushNames); }
		
		else if (menuChoice == 2) { //check if names, call computeFlames
			if (crushNames == NULL){
				printf("Invalid! There are no names yet!\n");
			}
			else {
				computeFlames(crushCount, filteredUserName, crushNames);
			}
		}
		
		else if (menuChoice > 3) { //check if other numbers
			printf("incorrect menu input\n");
		}
		
	} while (menuChoice != 3); //terminates program

	//deallocation, free the 2D array
	for (i = 0; i < crushCount; i++) {
		free(crushNames[i]); // Free each allocated name
	}
	free(crushNames); // Free the array itself
	
	printf("Thank You!\n");
	return 0;
}
