//LIBRARY MANAGMENT
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct books
{

    int id;
    char bookname[30];
    char authorname[30];
    char date[15];
}b;

struct student
{
    int id;
    char sname[30];
    char sclass[30];
    int roll;
    char bookname[30];
    char date[12];
}s;
 

 void main()
 {
    int ch;


     void add();
     void book_list();
     void remove_book();
     void issue_book();
     void issued_book_list();


     while(1)
     {
         system("cls");
         system("color 0f");
         printf("*********LIBARARY MANAGEMENT SYSTEM***********");
         printf("\n 1.add book");
         printf("\n 2.book list");
         printf("\n 3.remove book");
         printf("\n 4.issue book");
         printf("\n 5.issued book list");
         printf("\n 6.exit");
         printf("\n \t\t\t\t\t  enter your choice");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1:
             add();
             break;

             case 2:
             book_list();
             break;

             case 3:
             remove_book();
             break;

             case 4:
             issue_book();
             break;

             case 5:
             issued_book_list(0);
             break;

             case 6:
             exit(0);
             break;


         }

     }
 }

 void add()
 {
     FILE*fp;
     system("cls");
     system("color 8f");
     printf("****************ADD  BOOK**************************");
     printf("\n\n\n enter book id:        ");
     scanf("%d",&b.id);
     fflush(stdin);
     printf("\n enter the book name:           ");
     gets(b.bookname);
     fflush(stdin);
     printf("\n enter the author name:           ");
     gets(b.authorname);
     fflush(stdin);

     char mydate[15];
     time_t t=time(NULL);
     struct tm tm=*localtime(&t);
     sprintf(mydate,"%02d/%02d/%02d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
     strcpy(b.date,mydate);
     printf("\n------------BOOK ADDED SUCCESSFULLY------------------");


     fp=fopen("book.txt","ab");
     fwrite(&b,sizeof(b),1,fp);
     fclose(fp);
     
     getch();
 }


void book_list()
{
    
    system("cls");
    system("color e8");
    FILE*fp;
    printf("**********LIST OF THE BOOKS ARE GIVEN BELOW**********\n\n");
    printf("%-10s %-30s %-20s %s\n\n","BOOK ID","BOOK NAME","AUTHOR NAME","DATE");
    fp=fopen("book.txt","rb");
    while(fread(&b,sizeof(b),1,fp)!=NULL)
    {
        printf("%-10d %-30s %-20s %s\n",b.id,b.bookname,b.authorname,b.date);
    }
    fclose(fp);
    getch();
}


void remove_book()
{
    system("cls");
    system("color f8");
    int n,f=0;
    FILE*fp;
    FILE*fpp;
    printf("************REMOVE BOOK LIST**************\n\n");
    printf("enter the id no. you want to delete:\n");
    scanf("%d",&n);
    fp=fopen("book.txt","rb");
    fpp=fopen("temp.txt","wb");
    while(fread(&b,sizeof(b),1,fp)!=NULL)
    {
        if(n==b.id)
        {
            f=1;
        }

        else
        {
            fwrite(&b,sizeof(b),1,fpp);
        }

    }
    if(f==0)
    {
        printf("\n book are not found");
    }
    else
    {
        printf("\n delete successfully");
    }

    fclose(fp);
    fclose(fpp);
    remove("book.txt");
    rename("temp.txt","book.txt");
    getch();
}


void issue_book()
    {
         char mydate[15];
     time_t t=time(NULL);
     struct tm tm=*localtime(&t);
     sprintf(mydate,"%02d/%02d/%02d",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
     strcpy(s.date,mydate);
     
     int f=0;
     FILE*fp;
     system("cls");
     system("color 0c");
     printf("***************ISSUE BOOK***************\n");
     printf("Enter the book id to be issue:");
     scanf("%d",s.id);
     fp=fopen("book.txt","rb");
     while(fread(&b,sizeof(b),1,fp)!=NULL)
     {
         if(b.id==s.id)
         {
             strcpy(s.bookname,b.bookname);
             f=1;
             break;
         }
     }

     if(f==0)
     {
         printf("no book found\n");
         printf("please try again.....................");
         return;
     }
     
     fp=fopen("issue.txt","ab");
     printf("enter the student name:");
     fflush(stdin);
     gets(s.sname);

     printf("\nenter the student class:");
     fflush(stdin);
     gets(s.sclass);

     printf("\nenter the roll no.  :");
     fflush(stdin);
     scanf("%d",&s.roll);

     printf("\n\n___________----BOOK ISSUED SUCCESSFULLY----___________");
     fwrite(&s,sizeof(s),1,fp);
     fclose(fp);
     
     getch();

    }


    void issued_book_list()
    {
        FILE*fp;
        system("cls");
        system("color 8f");
        printf("***************ISSUED BOOK LIST****************\n\n");
        printf("%-10s %-30s %-20s %-10s %-30s\n\n","STD ID","NAME","CLASS","ROLL NO.","BOOK NAME","DATE");
        fp=fopen("issue.txt","rb");
        while(fread(&s,sizeof(s),1,fp)!=NULL){
            printf("%-10s %-30s %-20s %-10s %-30s\n",s.id,s.sname,s.sclass,s.roll,s.bookname,s.date);

        }
        getch();
    }

