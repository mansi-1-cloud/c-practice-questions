#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct emp{
    int id;
    char name[40];
    int sal;
 };

 void main(){
    int i,n,j;
    struct emp d1[100],temp;
    printf("enter n");
    scanf("%d",&n);

    for( i=0;i<n;i++)
    {  getchar();
        printf("enter name");
        gets(d1[i].name);
        printf("sallary ");
        scanf("%d",&d1[i].sal);
        printf("id ");
        scanf("%d",&d1[i].id);
    }
    for( i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(d1[j].sal < d1[j+1].sal)
            {
                temp=d1[j];
                d1[j]=d1[j+1];
                d1[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\n",d1[i].name,d1[i].sal,d1[i].id);
      
    }}