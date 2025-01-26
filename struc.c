#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct time{
    int roll;
    char name[40];
   struct data
   {
       int d,m,y;
   }join;
   }d1[450] ;
  
 
 void code(int,int,int,int,int,int,int);
 void main(){
    int i,a,b,c;
   
    printf("enter year");
    scanf("%d%d%d",&a,&b,&c);

    for( i=0;i<3;i++)
    {  getchar();
        printf("enter name");
        gets(d1[i].name);
        printf("date of join");
        scanf("%d",&d1[i].join.d);
        scanf("%d",&d1[i].join.m);
         scanf("%d",&d1[i].join.y); 
    }
    for(int i=0;i<3;i++)
    {
        code(d1[i].join.d,d1[i].join.m,d1[i].join.y,a,b,c,i);
    }
        
    }
   void code(int a,int b,int c,int x,int y,int z,int k)
    {
        if(a==x&&b==y&&c==z)
        puts(d1[k].name);
    }
 