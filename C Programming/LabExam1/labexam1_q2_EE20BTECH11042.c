#include <stdio.h>
#include<stdlib.h>

int main()
{
    char input;
    printf("Enter a character: ");
    scanf("%c",&input);
    int num=input;
    if((num>64)&&(num<91))                                   //If character is between A and Z
    {
        for(int i=num;i<91;i++)
        {
            printf("%c ",i);
        }
        for(int i=65;i<num;i++)                              //To print chracters before given character
        {
            printf("%c ",i);
        }
    }
    else if((num>96)&&(num<123))                             //If character is between a and z
    {
        for(int i=num;i<123;i++)
        {
            printf("%c ",i);
        }
        for(int i=97;i<num;i++)                              //To print chracters before given character
        {
            printf("%c ",i);
        }
    }
    else
    {
        printf("%c is not an English Letter.",input);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

