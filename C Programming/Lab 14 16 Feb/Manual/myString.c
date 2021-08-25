#include "myString.h"
#include<stdio.h>
void printVertical(char text[])
{
    int i=0;
    while (text[i]!='\0')
    {
        printf("\n %c",text[i]);
        i=i+1;
    }
}
void printMany(char *string,unsigned int d)
{
    for (unsigned int i=0;i<d;i++)
        printf("\n%s",string);
}

void readString(char *text, int length)
{
    int i=0;
    fgets(text,length,stdin);
    while ((text[i]!='\n') && (text[i]!='\0'))
    {
        i=i+1;
    }
    text[i]='\0';
}
