#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student {
    int rollNo;
    char name[50];
    char course[50];
    char depart[50];
    int year;
};
void yearNames(struct student s[],int n,int Year){
    for(int i=0;i<n;i++){
    if(s[i].year==Year){
        printf("%s",s[i].name);
    }
    }
}
void printDetails(struct student s[],int n,int RollNo){
    for(int i=0;i<n;i++){
        if(s[i].rollNo==RollNo){
        printf("Roll Number : %d\n", s[i].rollNo);
        printf("Name : %s\n", s[i].name);
        printf("Course : %s\n", s[i].course);
        printf("Department : %s\n", s[i].depart);
        printf("Year : %d\n", s[i].year);  
        }
    }
}
void sortStructure(struct student s[],int n){
    int trollNo,tyear;char tname[20],tcourse[20],tdepart[20];
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(s[j].rollNo>s[j+1].rollNo){
                trollNo=s[j].rollNo;
                s[j].rollNo=s[j+1].rollNo;
                s[j+1].rollNo=trollNo;

                tyear=s[j].year;
                s[j].year=s[j+1].year;
                s[j+1].year=tyear;

                strcpy(tname,s[j].name);
                strcpy(s[j].name,s[j+1].name);
                strcpy(s[j+1].name,tname);

                strcpy(tcourse,s[j].course);
                strcpy(s[j].course,s[j+1].course);
                strcpy(s[j+1].course,tcourse);

                strcpy(tdepart,s[j].depart);
                strcpy(s[j].depart,s[j+1].depart);
                strcpy(s[j+1].depart,tdepart);
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("Roll Number : %d\n", s[i].rollNo);
        printf("Name : %s\n", s[i].name);
        printf("Course : %s\n", s[i].course);
        printf("Department : %s\n", s[i].depart);
        printf("Year : %d\n", s[i].year);
    }
}
int main(){
    int n;
    printf("How many student details you have to store :\n");
    scanf("%d",&n);
    struct student s[n];
    for(int i=0;i<n;i++){
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll Number : ");
        scanf("%d",&s[i].rollNo);
        printf("Name : ");
        scanf(" %[^\n]", s[i].name); 
        printf("Course: ");
        scanf("%s", s[i].course);
        printf("Deparment  : ");
        scanf(" %[^\n]", s[i].depart);
        printf("Year of Joining : ");
        scanf("%d", &s[i].year);
    }
    printf("Structure after sorting:\n");
    sortStructure(s,n);
    return 0;
}