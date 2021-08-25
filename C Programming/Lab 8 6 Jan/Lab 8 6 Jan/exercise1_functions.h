#include <stdio.h>

struct student_record_t
{
    char fname[20];
    char lname[20];
    int btype;
    int branch;
    int yr;
    int ht;
    int wt;
};

typedef struct student_record_t srecord;

void print_record(char a[20],char b[20],int c,int d,int e,int f,int g)
{
    printf("%s %s ",a,b);
    switch(c)
    {
        case 0:printf("ANEGATIVE ");break;
        case 1:printf("BNEGATIVE ");break;
        case 2:printf("ABNEGATIVE ");break;
        case 3:printf("ONEGATIVE ");break;
        case 4:printf("APOSITIVE ");break;
        case 5:printf("BPOSITIVE ");break;
        case 6:printf("ABPOSITIVE ");break;
        case 7:printf("OPOSITIVE ");break;
    }
    switch(d)
    {
        case 0:printf("AI ");break;
        case 1:printf("BM ");break;
        case 2:printf("BT ");break;
        case 3:printf("CHE ");break;
        case 4:printf("CHY ");break;
        case 5:printf("CSE ");break;
        case 6:printf("EE ");break;
        case 7:printf("ES ");break;
        case 8:printf("MA ");break;
        case 9:printf("ME ");break;
        case 10:printf("MSME ");break;
    }
    printf(" %d %dcm %dKg\n",e,f,g);
}

void branch_determiner(int a)
{
    switch(a)
    {
        case 0:printf("AI-");break;
        case 1:printf("BM-");break;
        case 2:printf("BT-");break;
        case 3:printf("CHE-");break;
        case 4:printf("CHY-");break;
        case 5:printf("CSE-");break;
        case 6:printf("EE-");break;
        case 7:printf("ES-");break;
        case 8:printf("MA-");break;
        case 9:printf("ME-");break;
        case 10:printf("MSME-");break;
    }
    printf("\n");
}

