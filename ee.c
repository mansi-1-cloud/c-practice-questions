struct node{
    int data;
    struct node *next;
};

#include<stdlib.h>
#include<stdio.h>

void main(){
    struct node *head, *newnode, *temp;
    int ch;
    head = 0;
    printf("wanna 0,1");
    scanf("%d", &ch);
    while(ch){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if(head == 0){
            head = newnode;
            temp = head;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }
        printf("wanna 0,1");
        scanf("%d", &ch);
    }
    temp = head;
    while(temp != 0){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    getch();
}