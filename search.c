#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *search(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key == root->data) {
        return root;
    }
    else if (key < root->data) {
        return search(root->left, key);
    }
    else {
        return search(root->right, key);
    }
}

int main() {
    struct node* root = NULL;
    struct node* current = NULL;
    struct node* child = NULL;
    int choice, data;
    int searchKey; // Declare the searchKey variable

    // Create the root node
    printf("Enter data for the root node: ");
    scanf("%d", &data);
    root = createNode(data);
    current = root;

    // Loop to handle user actions
    while (1) {
        printf("\nCurrent node is %d. Choose an option:\n", current->data);
        printf("1. Add a left child\n");
        printf("2. Add a right child\n");
        printf("3. Move to the left child\n");
        printf("4. Move to the right child\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choices
        if (choice == 1) { // Add a left child
            if (current->left == NULL) {
                printf("Enter data for the left child: ");
                scanf("%d", &data);
                child = createNode(data);
                current->left = child;
                printf("Left child added.\n");
            } 
        } 
        
        else if (choice == 2) { // Add a right child
            if (current->right == NULL) {
                printf("Enter data for the right child: ");
                scanf("%d", &data);
                child = createNode(data);
                current->right = child;
                printf("Right child added.\n");
            } 
        } 
        
        else if (choice == 3) { // Move to the left child
            if (current->left != NULL) {
                current = current->left;
            } 
        } 
        
        else if (choice == 4) { // Move to the right child
            if (current->right != NULL) {
                current = current->right;
            } 
        } 
            
        else if (choice == 5) { // Exit
            printf("Exiting tree creation.\n");
            break; // Exit the loop
        }
    }

    // Ask for search key after tree creation
    printf("Enter data to search for: ");
    scanf("%d", &searchKey);

    struct node* n = search(root, searchKey); // Use searchKey for the search
    if (n != NULL) {
        printf("Found: %d\n", n->data);
    }
    else {
        printf("Element not found\n");
    }

    return 0;
}
