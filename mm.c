struct node{
    int data;
    struct node *next;

};
#include<stdlib.h>
#include<stdio.h>
void main(){
    struct node *head,*newnode,*temp;
    int ch;
    head=0;
    while(ch){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: \n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            temp=head=newnode;
            printf("enter data for beginning\n");
            scanf("%d",&newnode->data);
            newnode->next=head;
            head =newnode;
        }
        else {
            temp->next=newnode;
            temp=newnode;
        }
        printf("wanna 0,1\n");
        scanf("%d",&ch);
    }
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}