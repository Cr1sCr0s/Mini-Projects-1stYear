#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 05/04/25

//STRUCTURES
// Node for each of the grocery items
typedef struct GroceryItem {
    char name[100];
    int price;
    int stock;
    struct GroceryItem *next;
} GroceryItem;

// Node for each of the buyers
typedef struct Buyer {
    char name[100];
    char itemsBought[5][100];
    int itemsCount;
    int totalCost;
    struct Buyer *next;
} Buyer;

//LOAD DATA
void loadData(GroceryItem **groceryHead, Buyer **buyerHead) {
    FILE *f = fopen("groceryItem.txt", "r");
    if (!f) {
        printf("groceryItem.txt is not found. Starting with empty list.\n");
    
    } else {
        int count;
        fscanf(f, "%d", &count);
        
        for (int i = 0; i < count; i++) {
            GroceryItem *newItem = (GroceryItem*)malloc(sizeof(GroceryItem));
            fgetc(f);
            fgets(newItem->name, 100, f);
            newItem->name[strlen(newItem->name)-1] = '\0';
            fscanf(f, "%d", &newItem->price);
            fscanf(f, "%d", &newItem->stock);
            
            // every grocery item loaded is instered in alphabetical order
            GroceryItem *prev = NULL, *curr = *groceryHead;
            while (curr && strcmp(newItem->name, curr->name) > 0) {
                prev = curr;
                curr = curr->next;
            }
            newItem->next = curr;
            if (prev == NULL)
                *groceryHead = newItem;
            else
                prev->next = newItem;

        }
        fclose(f);
    }

    f = fopen("buyers.txt", "r");
    if (!f) {
        printf("buyers.txt not found. Starting with empty list.\n");
    } else {
        int count;
        fscanf(f, "%d", &count);
        
        for (int i = 0; i < count; i++) {
            Buyer *newBuyer = (Buyer*)malloc(sizeof(Buyer));
            fgetc(f);
            fgets(newBuyer->name, 100, f);
            newBuyer->name[strlen(newBuyer->name)-1] = '\0';
            fscanf(f, "%d", &newBuyer->itemsCount);
            fgetc(f);
            
            for (int j = 0; j < newBuyer->itemsCount; j++) {
                fgets(newBuyer->itemsBought[j], 100, f);
                newBuyer->itemsBought[j][strlen(newBuyer->itemsBought[j])-1] = '\0';
            }
            
            fscanf(f, "%d", &newBuyer->totalCost);
            newBuyer->next = *buyerHead;
            *buyerHead = newBuyer;
        }
        fclose(f);
    }
}

//SAVE DATA
void saveData(GroceryItem *groceryHead, Buyer *buyerHead) {
    int gCount = 0, bCount = 0;
    
    GroceryItem *curr = groceryHead;
    Buyer *bcurr = buyerHead;

    while (curr) { gCount++; curr = curr->next; }
    while (bcurr) { bCount++; bcurr = bcurr->next; }

    if (gCount == 0 && bCount == 0) {
        printf("No data to save.\n");
    }

    FILE *f = fopen("groceryItem.txt", "w");
    fprintf(f, "%d\n", gCount);
    curr = groceryHead;
    
    while (curr) {
        fprintf(f, "%s\n%d\n%d\n", curr->name, curr->price, curr->stock);
        curr = curr->next;
    }
    fclose(f);

    f = fopen("buyers.txt", "w");
    fprintf(f, "%d\n", bCount);
    bcurr = buyerHead;
    while (bcurr) {
        fprintf(f, "%s\n%d\n", bcurr->name, bcurr->itemsCount);
        for (int i = 0; i < bcurr->itemsCount; i++) {
            fprintf(f, "%s\n", bcurr->itemsBought[i]);
        }
        fprintf(f, "%d\n", bcurr->totalCost);
        bcurr = bcurr->next;
    }
    fclose(f);
     printf("Data saved successfully.\n");
}

//CHECK ITEM BOUGHT
int isItemBought(Buyer *buyerHead, const char *itemName) {
    while (buyerHead) {
        for (int i = 0; i < buyerHead->itemsCount; i++) {
            if (strcmp(buyerHead->itemsBought[i], itemName) == 0)
                return 1;
        }
        buyerHead = buyerHead->next;
    }
    return 0;
}

//ADD ITEM
void addGroceryItem(GroceryItem **groceryHead) {
    GroceryItem *newItem = (GroceryItem*)malloc(sizeof(GroceryItem));

    printf("Enter item name: ");
    fgets(newItem->name, 100, stdin);
    newItem->name[strlen(newItem->name)-1] = '\0';

    GroceryItem *curr = *groceryHead;
    while (curr) {
        if (strcmp(curr->name, newItem->name) == 0) {
            printf("Item already exists.\n");
            free(newItem);
            return;
        }
        curr = curr->next;
    }

    printf("Enter price: ");
    scanf("%d", &newItem->price);
    printf("Enter stock: ");
    scanf("%d", &newItem->stock);
    getchar();

    // Insert in alphabetical order
    GroceryItem *prev = NULL;
    curr = *groceryHead;
    while (curr && strcmp(newItem->name, curr->name) > 0) {
        prev = curr;
        curr = curr->next;
    }
    newItem->next = curr;
    if (prev == NULL)
        *groceryHead = newItem;
    else
        prev->next = newItem;

    printf("Item added successfully.\n");
}

//EDIT ITEM
void editGroceryItem(GroceryItem *groceryHead) {
    if (!groceryHead) { //cannot edit if there are no grocery items
        printf("No grocery items available.\n");
        return;
    }

    char name[100];
    printf("Enter item name to edit: ");
    fgets(name, 100, stdin);
    name[strlen(name)-1] = '\0';

    GroceryItem *curr = groceryHead;
    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            printf("Enter new price: ");
            scanf("%d", &curr->price);
            printf("Enter new stock: ");
            scanf("%d", &curr->stock);
            getchar();
            printf("Item updated successfully.\n");
            return;
        }
        curr = curr->next;
    }
    printf("Item not found.\n");
}

//DELETE ITEM
void deleteGroceryItem(GroceryItem **groceryHead, Buyer *buyerHead) {
    if (*groceryHead == NULL) { //cannot delete if there are no items
        printf("No grocery items available.\n");
        return;
    }

    char name[100];
    printf("Enter item name to delete: ");
    fgets(name, 100, stdin);
    name[strlen(name)-1] = '\0';

    if (isItemBought(buyerHead, name)) {
        printf("Item cannot be deleted because it has been bought.\n");
        return;
    }

    GroceryItem *curr = *groceryHead, *prev = NULL;
    while (curr) {
        if (strcmp(curr->name, name) == 0) {
            if (prev == NULL)
                *groceryHead = curr->next;
            else
                prev->next = curr->next;
            free(curr);
            printf("Item deleted successfully.\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Item not found.\n");
}

//VIEW ALL ITEMS
void viewAllGroceryItems(GroceryItem *groceryHead) {
    GroceryItem *curr = groceryHead;
    
    if (!curr) {
        printf("No items.\n");
        return;
    }

    while (curr) {
        printf("Name: %s\nPrice: %d\nStock: %d\n\n", curr->name, curr->price, curr->stock);
        curr = curr->next;
    }
}

//VIEW BUYERS
void viewAllBuyers(Buyer *buyerHead) {
    Buyer *curr = buyerHead;
    
    if (!curr) {
        printf("There are no buyers yet.\n");
        return;
    }

    while (curr) {
        printf("Buyer: %s\nItems:\n", curr->name);
        for (int i = 0; i < curr->itemsCount; i++) {
            printf("- %s\n", curr->itemsBought[i]);
        }
        printf("Total: %d\n\n", curr->totalCost);
        curr = curr->next;
    }
}

//BUY ITEM
void buyGroceryItem(GroceryItem *groceryHead, Buyer **buyerHead) {
    if (groceryHead == NULL) { //cannot buy if there are no items
        printf("No grocery items available.\n");
        return;
    }

    char buyerName[100];
    printf("Enter buyer name: ");
    fgets(buyerName, 100, stdin);
    buyerName[strlen(buyerName)-1] = '\0';

    Buyer *buyer = *buyerHead;
    while (buyer) {
        if (strcmp(buyer->name, buyerName) == 0)
            break;
        buyer = buyer->next;
    }

    if (!buyer) {
        buyer = (Buyer*)malloc(sizeof(Buyer));
        strcpy(buyer->name, buyerName);
        buyer->itemsCount = 0;
        buyer->totalCost = 0;
        buyer->next = *buyerHead;
        *buyerHead = buyer;
    }

    if (buyer->itemsCount >= 5) {
        printf("Item limit reached.\n");
        return;
    }

    GroceryItem *curr = groceryHead;
    int i = 1;
    while (curr) {
        printf("[%d] %s (%d)\n", i++, curr->name, curr->stock);
        curr = curr->next;
    }

    int choice;
    printf("Choose item number: ");
    scanf("%d", &choice);
    getchar();

    curr = groceryHead;
    for (int j = 1; j < choice && curr; j++) {
        curr = curr->next;
    }

    if (!curr || curr->stock == 0) {
        printf("Invalid choice or out of stock.\n");
        return;
    }

    //info updates
    strcpy(buyer->itemsBought[buyer->itemsCount], curr->name);
    buyer->itemsCount++;
    buyer->totalCost += curr->price;
    curr->stock--;
    printf("Purchase successful!\n");
}

//MAIN
//linked list head, menu, function calls
int main() {
    GroceryItem *groceryHead = NULL;
    Buyer *buyerHead = NULL;

    loadData(&groceryHead, &buyerHead);

    int choice;
    do {
        printf("\n~~~MENU~~~\n");
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

        if (choice == 1) 
            addGroceryItem(&groceryHead);
        else if (choice == 2) 
            buyGroceryItem(groceryHead, &buyerHead);
        else if (choice == 3) 
            editGroceryItem(groceryHead);
        else if (choice == 4) 
            deleteGroceryItem(&groceryHead, buyerHead);
        else if (choice == 5) 
            viewAllGroceryItems(groceryHead);
        else if (choice == 6) 
            viewAllBuyers(buyerHead);
        else if (choice == 7)
            saveData(groceryHead, buyerHead);
        else 
            printf("Invalid.\n");

    } while (choice != 7);

    return 0;
}
