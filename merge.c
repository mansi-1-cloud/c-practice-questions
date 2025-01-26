// merge two linked lists
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} sl;

sl* insert(sl*,sl*);
void display(sl*);
int main() {
    int ch = 1, v,m,c=1;
    sl *head = NULL, *newNode = NULL,*temp=NULL;
    sl *h=NULL,*new=NULL,*t=NULL;

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
printf("enter for next list");
   while (c) {
        // Allocating memory for a new node
        new = (sl*)malloc(sizeof(sl));
        if (!new) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        printf("Enter the number: ");
        scanf("%d", &m);
        new->data =m;
        new->next = NULL; // Set next to NULL for the new node

        if (h == NULL) {
            // If the list is empty, initialize head and temp
            h = t = new;
        } else {
            // Link the new node to the current list
            t->next = new;
            t = new;
        }

        printf("Enter 0 to break or 1 to continue: ");
        scanf("%d", &c);
    }
   head= insert(head,h);
    display(head);
    return 0;

}
  sl* insert(sl *pp,sl *p){
   sl *ptr=pp;
    while(ptr->next!=NULL){
      ptr=ptr->next;
    }
    ptr->next=p;
    while(p!=NULL){
      p=p->next;
    }
    return pp;
  }
  void display(sl *head) {
    sl *temp = head;
    printf("\nCombined List:\n");
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}