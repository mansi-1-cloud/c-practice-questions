#include<stdio.h>
void main(){
    int n,i,j,k,c=0;
    scanf("%d",&n);
    while(n%2==0){
        n=n/2;
        c++;
    }
    k=1;
    for(i=1;i<=c;i++){
        k=k*2;
    }
    if(k==1){
        if(k==n)
        printf("yess");
    }
    else if((k+1)==n)
    printf("yess");
    else 
    printf("noo");
}