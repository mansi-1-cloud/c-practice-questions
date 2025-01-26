#include <stdio.h>
#include <stdlib.h>

// Definition of a TreeNode
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Definition of a ListNode
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// Function to create a new tree node
TreeNode* newTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a value into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return newTreeNode(val);
    
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

// Function to create a new list node
ListNode* newListNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to flatten BST into Linked List
ListNode* flattenBST(TreeNode* root) {
    if (root == NULL) return NULL;  // If tree is empty, return NULL

    // Flatten left and right subtrees
    ListNode* leftList = flattenBST(root->left);
    ListNode* rightList = flattenBST(root->right);

    // Create a new linked list node for the current root
    ListNode* currentNode = newListNode(root->val);

    // Connect left list to current node if it exists
    if (leftList) {
        currentNode->next = leftList;
    } else {
        currentNode->next = rightList;
    }

    // Return the head of the newly formed list
    return currentNode;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int n, val;
    TreeNode* root = NULL;
    
    // Accepting number of nodes in the BST
    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &n);

    printf("Enter the values for the BST:\n");
    
    // Accepting the node values from user and inserting them into the BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Flatten BST into Linked List
    ListNode* listHead = flattenBST(root);

    // Print the resulting linked list
    printf("Flattened BST (Linked List):\n");
    printList(listHead);

    return 0;
}
