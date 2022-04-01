#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void search();
void modify();
void deleterec();
struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
};
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls");
    printf("<--:SEARCH RECORD:-->");
    printf("Enter name of student : ");
    fflush(stdin);
    fgets(stname,25,stdin);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0){
            printf("Name : %s",std.name);
            printf("Mobile Number : %s",std.mobile);
            printf("Roll No : %d",std.rollno);
            printf("Course : %s",std.course);
            printf("Branch : %s",std.branch);
        }
    }
    fclose(fp);
    printf("Press any key to continue.");
    getchar();
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");
    printf("<--:MODIFY RECORD:-->");
    printf("Enter name of student to modify: ");
    fflush(stdin);
    fgets(stname,25,stdin);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0){
            printf("Enter name: ");
            fgets(std.name,25,stdin);
            printf("Enter mobile number : ");
            fgets(std.mobile,10,stdin);
            printf("Enter roll no : ");
            scanf("%d",&std.rollno);
            printf("Enter Course : ");
            fflush(stdin);
            fgets(std.course,25,stdin);
            printf("Enter Branch : ");
            fflush(stdin);
            fgets(std.branch,25,stdin);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    printf("Press any key to continue.");
    getchar();
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    printf("<--:DELETE RECORD:-->");
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    fgets(stname,25,stdin);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("Press any key to continue.");
    getchar();
    menu();
}