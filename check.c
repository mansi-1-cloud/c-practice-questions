// post order
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// struct node* createNode(int data) {
//     struct node* n = (struct node*)malloc(sizeof(struct node));
//     n->data = data;
//     n->left = NULL;
//     n->right = NULL;
//     return n;
// }

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}


int main() {
    struct node* root = NULL;
    struct node* current = NULL;
    struct node* child = NULL;
    int choice, data;

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
            } }
            
            else if (choice == 5) { // Exit
            printf("Exiting tree creation.\n");
            break; // Exit the loop
        }
    }

    // Display pre-order traversal
    printf("Pre-order traversal of the tree:\n");
    preOrder(root);
    printf("\n");

    return 0;
}
