#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for a string
#define MAX_STRING_LENGTH 100

// Define the node structure
typedef struct Node {
    char data[MAX_STRING_LENGTH];
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strncpy(newNode->data, data, MAX_STRING_LENGTH);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insert(Node** head, char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a string in the linked list
int search(Node* head, char* target) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data, target) == 0) {
            return 1; // Found
        }
        temp = temp->next;
    }
    return 0; // Not found
}

// Function to display all nodes in the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    Node* head = NULL;
    int choice;
    char input[MAX_STRING_LENGTH];
    
    while (1) {
        printf("\nBasic Search Engine\n");
        printf("1. Insert a new webpage/document\n");
        printf("2. Search for a webpage/document\n");
        printf("3. Display all webpages/documents\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter the webpage/document title to insert: ");
                fgets(input, MAX_STRING_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove the trailing newline character
                insert(&head, input);
                break;
            case 2:
                printf("Enter the webpage/document title to search: ");
                fgets(input, MAX_STRING_LENGTH, stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove the trailing newline character
                if (search(head, input)) {
                    printf("Webpage/document found!\n");
                } else {
                    printf("Webpage/document not found.\n");
                }
                break;
            case 3:
                printf("List of all webpages/documents:\n");
                display(head);
                break;
            case 4:
                // Free the allocated memory before exiting
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
