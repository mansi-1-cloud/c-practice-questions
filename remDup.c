// remove dupli from single linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} sl;

sl* insert(sl*);

int main() {
    int ch = 1, v;
    sl *head = NULL, *newNode = NULL, *temp = NULL;

    while (ch) {
        // Allocating memory for a new node
        newNode = (sl*)malloc(sizeof(sl));
        if (!newNode) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter the number: ");
        scanf("%d", &v);
        newNode->data = v;
        newNode->next = NULL; // Set next to NULL for the new node

        if (head == NULL) {
            // If the list is empty, initialize head and temp
            head = temp = newNode;
        } else {
            // Link the new node to the current list
            temp->next = newNode;
            temp = newNode;
        }

        printf("Enter 0 to break or 1 to continue: ");
        scanf("%d", &ch);
    }

    // Remove duplicates from the unsorted list
    head = insert(head);

    // Display the list
    printf("\nUpdated List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    return 0;
}

// Function to remove duplicates from an unsorted linked list
sl* insert(sl *p) {
    sl *current = p;
    sl *prev = NULL, *temp = NULL;

    while (current != NULL) {
        prev = current;
        temp = current->next;

        while (temp != NULL) {
            if (current->data == temp->data) {
                // Duplicate found, remove it
                prev->next = temp->next;
                free(temp);  // Free the duplicate node
                temp = prev->next;  // Move temp to the next node
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        current = current->next;
    }

    return p;
}




