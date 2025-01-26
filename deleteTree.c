#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Post-order traversal function
void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// Find the minimum value node (for finding successor)
struct node* findMin(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted is found
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Find inorder successor
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct node* root = NULL;
    struct node* current = NULL;
    struct node* child = NULL;
    int choice, data, key;

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
        printf("5. Delete a node\n");
        printf("6. Exit\n");
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
            } else {
                printf("Left child already exists.\n");
            }
        } else if (choice == 2) { // Add a right child
            if (current->right == NULL) {
                printf("Enter data for the right child: ");
                scanf("%d", &data);
                child = createNode(data);
                current->right = child;
                printf("Right child added.\n");
            } else {
                printf("Right child already exists.\n");
            }
        } else if (choice == 3) { // Move to the left child
            if (current->left != NULL) {
                current = current->left;
                printf("Moved to the left child.\n");
            } else {
                printf("Left child does not exist.\n");
            }
        } else if (choice == 4) { // Move to the right child
            if (current->right != NULL) {
                current = current->right;
                printf("Moved to the right child.\n");
            } else {
                printf("Right child does not exist.\n");
            }
        } else if (choice == 5) { // Delete a node
            printf("Enter the value of the node to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            printf("Node deleted.\n");
        } else if (choice == 6) { // Exit
            printf("Exiting tree creation.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    // Display post-order traversal
    printf("Post-order traversal of the tree:\n");
    postOrder(root);
    printf("\n");

    return 0;
}
