#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char usercountry[100],country[100],hyphen[3],capital[100];
    FILE *ptr;
    int flag=0;

    if ((ptr=fopen("oneWordCapitals.txt","r"))==NULL)
    {
        printf("Error opening file.");
        return 1;
    }
    printf("\n*** Program to print the capital of a country ***");
    printf("\n Enter the country name: ");
    fscanf(stdin,"%s",usercountry);
    while (!feof(ptr))
    {

        fscanf(ptr,"%s %s %s",country,hyphen,capital);

        if (strcmp(country,usercountry)==0){
            printf("The capital of %s is %s",country,capital);
            flag=1;
        }
    }
    fclose(ptr);
    if (flag==0)
        printf("Country not found");
}
