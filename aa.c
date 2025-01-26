#include<stdio.h>
void main(){
    int num,aa,p,r=0,a,c=0,t=0;
    scanf("%d",&num);
    aa=num;
    while(aa>0){
        r=aa%10;
        c++;
        aa=aa/10;
    }
    while(num>9){
        a=num/10;
        p=(num/100)%10;
        if((a-2)==p)
        t++;
        num=num/10;
    }
if(t==c-1)
printf("yesss");
else 
printf("noo");
}