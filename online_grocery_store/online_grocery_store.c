#include <stdio.h>
#include <string.h>
// 04/25/25

//STRUCTURES
//One grocery item with name, price, and stock.
struct GroceryItem {
    char name[100];
    int price;
    int stock;
};

// Customer with name, list of bought items, total cost, and item count.
struct Buyer {
    char name[100];
    char itemsBought[5][100];
    int totalCost;
    int itemsCount;
};

//LOAD ITEMS
//Loads a grocery item data from the text file and fills the grocery items array
void loadGroceryData(struct GroceryItem groceryItems[], int *groceryCount) {
    FILE *f = fopen("groceryItem.txt", "r");

    if (f != NULL) {
        fscanf(f, "%d", groceryCount); //so it knows how many
        for (int i = 0; i < *groceryCount; i++) {
            fgetc(f);
            fgets(groceryItems[i].name, 100, f);
             groceryItems[i].name[strlen(groceryItems[i].name) - 1] = '\0';
            fscanf(f, "%d", &groceryItems[i].price);
            fscanf(f, "%d", &groceryItems[i].stock);
        }
        fclose(f) ;
    }
}

//LOAD BUYERS
//Loads Customer's data from the text file and fills the buyers array.
void loadBuyerData(struct Buyer buyers[], int *buyerCount) {
    FILE *f = fopen("buyers.txt", "r");
    if (f != NULL) {
        fscanf(f, "%d", buyerCount); //count all buyers
        
        //loaid the people
        for (int i = 0; i < *buyerCount; i++) {
            fgetc(f);
            fgets(buyers[i].name, 100, f);
            buyers[i].name[strlen(buyers[i].name) - 1] = '\0';
            fscanf(f, "%d", &buyers[i].itemsCount);
            fgetc(f);
            //customer's items
            for  (int j = 0; j < buyers[i].itemsCount; j++) {
                fgets(buyers[i].itemsBought[j], 100, f);
                buyers[i].itemsBought[j][strlen(buyers[i].itemsBought[j]) - 1] = '\0';
            }
            fscanf(f, "%d", &buyers[i].totalCost);
        }
        fclose(f);
    }
}

//SAVE
//Saves the current grocery and buyer datas to their respective text files.
void saveData(struct GroceryItem groceryItems[], int groceryCount, struct Buyer buyers[], int buyerCount) {
    FILE *f = fopen("groceryItem.txt", "w");
    
    fprintf(f, "%d\n", groceryCount);
    
    for (int i = 0; i < groceryCount; i++) { //save items
        fprintf(f, "%s\n%d\n%d\n", groceryItems[i].name, groceryItems[i].price, groceryItems[i].stock);
    }
    fclose(f);

    f = fopen("buyers.txt", "w");  //save customers
    fprintf(f, "%d\n", buyerCount);
    
    for (int i = 0; i < buyerCount; i++) {
        fprintf(f, "%s\n%d\n", buyers[i].name, buyers[i].itemsCount);
        for (int j = 0; j < buyers[i].itemsCount; j++) {
            fprintf(f, "%s\n", buyers[i].itemsBought[j]);
        }
        fprintf(f, "%d\n", buyers[i].totalCost);
    }
    
    fclose(f);
}


//ADD GROCERY
//Adds a new item to the list, if it's not a duplicate and limit not reached.
void addGroceryItem(struct GroceryItem groceryItems[], int *groceryCount) {
    if (*groceryCount >= 10) { //check if items are more than 10
        printf("Item list full.\n");
        return;
    }

    printf("Enter item name: "); //item input
    fgets(groceryItems[*groceryCount].name, 100, stdin);
    groceryItems[*groceryCount].name[strlen(groceryItems[*groceryCount].name) - 1] = '\0';


    for (int i = 0; i < *groceryCount; i++) { //check if item exists
        if (strcmp(groceryItems[i].name, groceryItems[*groceryCount].name) == 0) {
            printf("Item already exists!\n");
            return;
        }
    }

    //more inputs
    printf("Enter price: ");
    scanf("%d", &groceryItems[*groceryCount].price);
    printf("Enter stock: ");
    scanf("%d", &groceryItems[*groceryCount].stock);
    getchar();

    (*groceryCount)++;
    printf("Item added.\n");
}

//EDIT GROCERY
//Modifies the price and stock of a real grocery item.
void editGroceryItem(struct GroceryItem groceryItems[], int groceryCount) {
    if (groceryCount == 0) {//check if there is no items yet
        printf("No grocery items available to edit.\n");
        return;
    }
    char name[100];//shows items or edit
    printf("Enter grocery item name to edit: ");
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = '\0';

    for (int i = 0; i < groceryCount; i++) {
        if (strcmp(groceryItems[i].name, name) == 0) {
            printf("Enter new price: ");
            scanf("%d", &groceryItems[i].price);
            printf("Enter new stock: ");
            scanf("%d", &groceryItems[i].stock);
            getchar();
            printf("Item updated.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

//DELETE GROCERY
//Deletes a grocery item from the list.
void deleteGroceryItem(struct GroceryItem groceryItems[], int *groceryCount) {
    if (*groceryCount == 0) { //check if there is items yet
        printf("No grocery items to delete.\n");
        return;
    }
    char name[100];
    printf("Enter grocery item name to delete: ");
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = '\0';

    for (int i = 0; i < *groceryCount; i++) { //loop for deleting
        if (strcmp(groceryItems[i].name, name) == 0) {
            for (int j = i; j < *groceryCount - 1; j++) {
                groceryItems[j] = groceryItems[j + 1];
            }
            (*groceryCount)--;
            printf("Item deleted.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

//VIEW GROCERY
//Displays all of the grocery items, including without stock
void viewAllGroceryItems(struct GroceryItem groceryItems[], int groceryCount) {
    if (groceryCount == 0) { //check if there are no items yet
        printf("No grocery items available.\n");
        return;
    }
    
    for (int i = 0; i < groceryCount; i++) { //prints the items
        printf("Grocery Item: %s\nItem Price: %d\nStock: %d\n\n", groceryItems[i].name, groceryItems[i].price, groceryItems[i].stock);
    }
}

//VIEW BUYERS
//Shows all buyers and the items they bought.
void viewAllBuyers(struct Buyer buyers[], int buyerCount) {
    if (buyerCount == 0) { //check if there are no buyers yet
        printf("No buyers available.\n");
        return;
    }
    for (int i = 0; i < buyerCount; i++) { //loop for printing names
        printf("Customer Name: %s\nGrocery Items Bought:\n", buyers[i].name);
        for (int j = 0; j < buyers[i].itemsCount; j++) {
            printf("- %s\n", buyers[i].itemsBought[j]);
        }
        printf("Total Cost: %d\n\n", buyers[i].totalCost);
    }
}

//BUY ITEM
//Allows a buyer to purchase an item if it's available.
void buyGroceryItem(struct GroceryItem groceryItems[], int groceryCount, struct Buyer buyers[], int *buyerCount) {
    if (groceryCount == 0) { //check first if there are no items
        printf("No items available.\n");
        return;
    }

    char buyerName[100]; //inputs
    printf("Enter buyer name: ");
    fgets(buyerName, 100, stdin);
    buyerName[strlen(buyerName) - 1] = '\0';

    int buyerIndex = -1; //check for if the name already exists
    for (int i = 0; i < *buyerCount; i++) {
        if (strcmp(buyers[i].name, buyerName) == 0) {
            buyerIndex = i;
            break;
        }
    }

    if (buyerIndex == -1 && *buyerCount < 10) { //add the new buyer
        strcpy(buyers[*buyerCount].name, buyerName);
        buyers[*buyerCount].itemsCount = 0;
        buyers[*buyerCount].totalCost = 0;
        buyerIndex = *buyerCount;
        (*buyerCount)++;
    } 
    else if (buyerIndex == -1) { //condition for too much buyers
        printf("Buyer list full.\n");
        return;
    }

    printf("Available items:\n"); //shows only available items
    for (int i = 0; i < groceryCount; i++) {
        printf("[%d] %s (%d)\n", i + 1, groceryItems[i].name, groceryItems[i].stock);
    }

    int itemIndex;
    printf("Enter item number: ");
    scanf("%d", &itemIndex);
    getchar();
    itemIndex--; //so it starts at 0

    if (itemIndex < 0 || itemIndex >= groceryCount || groceryItems[itemIndex].stock == 0) { // no stock condidtion
        printf("Invalid or out of stock.\n");
        return;
    }

    if (buyers[buyerIndex].itemsCount >= 5) {
        printf("Limit reached.\n"); //can only purchase up to 5 per buyer
        return;
    }

    strcpy(buyers[buyerIndex].itemsBought[buyers[buyerIndex].itemsCount], groceryItems[itemIndex].name); //add item to buyer list
    buyers[buyerIndex].totalCost += groceryItems[itemIndex].price;
    buyers[buyerIndex].itemsCount++; //update total cost per buyer
    groceryItems[itemIndex].stock--; //decrease stock of item

    printf("Purchase successful!\n");
}

//MAIN
//menu and calls functions based on user input.
int main() {
    struct GroceryItem groceryItems[10];
    struct Buyer buyers[10];
    int groceryCount = 0;
    int buyerCount = 0;

    loadGroceryData(groceryItems, &groceryCount);
    loadBuyerData(buyers, &buyerCount);

    int choice;
    do {
        printf("\nMENU GROCERY STORE\n");
        printf("[1] Add Grocery Item\n");
        printf("[2] Buy Grocery Item\n");
        printf("[3] Edit Grocery Item\n");
        printf("[4] Delete Grocery Item\n");
        printf("[5] View All Grocery Items\n");
        printf("[6] View All Buyers\n");
        printf("[7] Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        
        if (choice == 1) {
            addGroceryItem(groceryItems, &groceryCount);
        } else if (choice == 2) {
            buyGroceryItem(groceryItems, groceryCount, buyers, &buyerCount);
        } else if (choice == 3) {
            editGroceryItem(groceryItems, groceryCount);
        } else if (choice == 4) {
            deleteGroceryItem(groceryItems, &groceryCount);
        } else if (choice == 5) {
            viewAllGroceryItems(groceryItems, groceryCount);
        } else if (choice == 6) {
            viewAllBuyers(buyers, buyerCount);
        } else if (choice == 7) {
            saveData(groceryItems, groceryCount, buyers, buyerCount);
            printf("Data saved. Goodbye!\n");
        } else {
            printf("Invalid choice.\n");
        }
    } while (choice != 7); //done

    return 0;
}