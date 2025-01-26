//Circualr Queue 
//cicular queue 
#include<stdio.h>
#include<stdlib.h>
#define MAX 5 
int cenq(int [] , int* , int* );
int cdeq(int [] , int* , int* );
void dis(int [] , int , int );
int main(){
    int ch = 0 , f = -1 , r = -1 , q[MAX];
    {
        do{
            printf("\nEnter 1 :- Enqueue\nenter 2 :- Dequeue\nEnter 3 :- Display\nEnter 4 :-Exit\n");
            scanf("%d",&ch);
            switch(ch){
                case 1 :
                    cenq(q,&f,&r);
                    break;
                case 2 :
                    cdeq(q,&f,&r); 
                    break;
                case 3:
                    dis(q,f,r);
                    break;
                case 4 :
                    printf("Exit");
            }
        }while(ch<=3);
    }
}
int cenq(int q[] ,  int *f , int *r ){
    if( ((*r)+1)%MAX == *f )printf("\nQueue is full "); // checking condition for circular queue 
    else{
        if(*f == -1) *f = 0 ;
        *r = (*r + 1) % MAX;  // Circular increment hoogaaaa....
        printf("\nEnter the to be enqueued :- ");
        scanf("%d",&q[(*r)]);
    }
    return 0 ;
}
int cdeq(int q[] , int *f , int *r){
    if(*f==-1&&*r==-1)printf("\nqueue is empty");
    else{
        printf("\nDequed element is :- %d",q[*f]);
        if(*f==*r)//age ek hee element insert hua hotoh
        *f = *r = -1 ;
        else{
            *f = (*f + 1)%MAX ; // incrementing it by 
        }
    }
    return 0;
}
void dis(int q[] , int f , int r ){
    int i ;
    i = f ;
    if(f == -1 && r == -1) {
        printf("Queue is empty\n");
    } else {
        printf("\nQueued elements are: ");
        int i = f;
        while(i != r ) {
            printf("%d ", q[i]);
            i = (i + 1) % MAX;  // Circular increment
        }
        printf("%d\n", q[r]);  // Print the last element
    }
}