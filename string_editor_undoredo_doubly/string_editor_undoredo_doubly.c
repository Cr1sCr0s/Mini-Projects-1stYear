#include <stdio.h>
#include <stdlib.h> // for malloc() & free()
#include <string.h> // for strcpy(), strcat(), strlen(), & strcspn()
// 05/16/25

// Structures
// Each node represents a version of the string.
typedef struct Node {
    char text[1000];
    struct Node *prev;
    struct Node *next;
} Node;

// Functions
// Helper to create a new node
Node *createNode(const char *str) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->text, str);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Append a new version after the current and discard redo history
void insertAfter(Node **current, const char *newStr) {
    Node *newNode = createNode(newStr);

    // Discard redo history
    if ((*current)->next) {
        Node *toDelete = (*current)->next;
        while (toDelete) {
            Node *temp = toDelete;
            toDelete = toDelete->next;
            free(temp);
        }
        (*current)->next = NULL;
    }

    
    (*current)->next = newNode;
    newNode->prev = *current;
    *current = newNode;
}

// Menu to edit string
void editString(Node **current) {
    int choice = 0;
        printf("\n==== MENU ====\n");
        printf("[1] Replace String\n");
        printf("[2] Change Character At\n");
        printf("[3] Append a String\n");
        printf("[4] Back to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            char newStr[1000];
            printf("Enter new string: ");
            fgets(newStr, sizeof(newStr), stdin);
            newStr[strcspn(newStr, "\n")] = 0;
            insertAfter(current, newStr);
            printf("Current String: %s\n", (*current)->text);
        }
        else if (choice == 2) {
            int index;
            char ch;
            printf("Enter index (0-%d): ", (int)strlen((*current)->text) - 1);
            scanf("%d", &index);
            getchar();
            
            if (index < 0 || index >= strlen((*current)->text)) {
                printf("Invalid index.\n");
                return;
            }
            printf("Enter character: ");
            scanf("%c", &ch);
            getchar();
            char modified[1000];
            strcpy(modified, (*current)->text);
            modified[index] = ch;
            insertAfter(current, modified);
            printf("Current String: %s\n", (*current)->text);
        }
        else if (choice == 3) {
            char add[1000];
            printf("Enter string to append: ");
            fgets(add, sizeof(add), stdin);
            add[strcspn(add, "\n")] = 0;
            char combined[1000];
            strcpy(combined, (*current)->text);
            strcat(combined, add);
            insertAfter(current, combined);
            printf("Current String: %s\n", (*current)->text);
        }
        else if (choice == 4) {
            printf("Returning to main menu.\n");
        }
        else {
            printf("Invalid choice.\n");
        }
    return;
}


int main() {
    char initial[1000];
    printf("Current string: ");
    fgets(initial, sizeof(initial), stdin);
    initial[strcspn(initial, "\n")] = 0;

    Node *head = createNode(initial);
    Node *current = head;

    int choice;
    do {
        printf("\n==== MENU ====\n");
        printf("[1] Edit String\n");
        printf("[2] Undo\n");
        printf("[3] Redo\n");
        printf("[4] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            editString(&current);
        }
        else if (choice == 2) {
            if (current->prev) {
                current = current->prev;
                printf("Current String: %s\n", current->text);
            } else {
                printf("Cannot Undo!\n");
            }
        }
        else if (choice == 3) {
            if (current->next) {
                current = current->next;
                printf("Current String: %s\n", current->text);
            } else {
                printf("Cannot Redo!\n");
            }
        }
        else if (choice == 4) {
            printf("Exiting program.\n");
        }
        else {
            printf("Invalid choice.\n");
        }
    
    } while (choice != 4);

    // Frees memory
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;

}
