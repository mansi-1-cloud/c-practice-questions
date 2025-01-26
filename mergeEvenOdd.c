#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to merge two linked lists (even first, odd second)
struct Node* mergeEvenOdd(struct Node* list1, struct Node* list2) {
    struct Node *evenHead = NULL, *oddHead = NULL;
    struct Node *evenTail = NULL, *oddTail = NULL;

    // Traverse the first list and separate even and odd numbers
    struct Node* current = list1;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }

    // Traverse the second list and separate even and odd numbers
    current = list2;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }

    // Merge the even list and odd list
    if (evenTail != NULL) {
        evenTail->next = oddHead;
    }
    if (oddTail != NULL) {
        oddTail->next = NULL;
    }

    // Return the head of the merged list (evenHead)
    return evenHead;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, data;

    // Create the first linked list
    printf("Enter the number of elements for the first list: ");
    scanf("%d", &n);
    printf("Enter the elements of the first list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&list1, data);
    }

    // Create the second linked list
    printf("Enter the number of elements for the second list: ");
    scanf("%d", &n);
    printf("Enter the elements of the second list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insertEnd(&list2, data);
    }

    // Print the original lists
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Merge the lists (even numbers first, odd numbers second)
    struct Node* mergedList = mergeEvenOdd(list1, list2);

    // Print the merged list
    printf("Merged List (Even first, Odd second): ");
    printList(mergedList);

    return 0;
}
