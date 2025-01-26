// inserrting node at the end from right side
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data ;
    struct node *next ;
}sl ;
sl* insert(sl*);
int main (){
    int ch = 1,v ;
    sl *head = NULL , *new = NULL , *temp = NULL ;
    head=0;
    while(ch){
        new = (sl*)malloc(sizeof(sl));
           
            printf("Enter the no to be :- ");
            scanf("%d",&v);
            new->data = v ;
           
            if(head==NULL && temp == NULL) 
            head = temp=new ;
            else{
                temp->next = new ;
                temp = new ;
            }
        
        printf("Enter 0 to break or 1 to cont... :- ");
        scanf("%d",&ch);
      
    }
   head= insert(head);
    temp = head ;
    printf("\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->next ;
    }
}
sl* insert(sl *ptr){
    sl *prev=NULL,*new=NULL,*nextn=NULL;
    prev=0;
    nextn=new=ptr;
    while(nextn!=NULL){
        nextn=nextn->next;
        new->next=prev;
        prev=new;
        new=nextn;
    }
   return prev;
}
  