#include<stdio.h>

int main()
{
    int i,n;

    printf("Program to print many Hello Worlds");
    printf("\nHow many times do you want to print Hello World?: ");
    scanf("%d",&n);
    i=1;
    while(i<=n)
    {
        printf("\nHello World %d",i);
        i=i+1;
    }
    //printf("\nThe value of i is %d",i);
}
