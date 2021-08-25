#include <stdio.h>
#include <math.h>

#define mask_last 0x01
#define mask_first 0x80000000

int main()
{
    unsigned n,count=0,remainder,tmp,reverse_decimal=0;
    int i=1;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    tmp=n;
    while(tmp>=1)                                       //To count number of places
    {
        ++count;
        tmp/=10;
    }
    tmp=n;
    while(tmp>=1)                                       //To reverse the number in decimal format
    {
        remainder=tmp%10;
        --count;
        reverse_decimal+=(remainder*pow(10,count));
        tmp/=10;
    }
    tmp=n;
    printf("\nThe reverse of the given number in decimal is: %d \n\nAnd in binary(reverse)right to left is: \n",reverse_decimal);
    
    
    while(i<=32)                                     //Right to Left in binary
    {
        if(tmp&mask_last)
            printf("1");
        else
            printf("0");
        if((i%4)==0)
            printf(" ");
        tmp>>=1;
        ++i;
    }
    tmp=n;
    i=1;
    
    printf("\n\nAnd in binary left to right is: \n");    //Left to Right in binary
    while(i<=32)
    {
        if(tmp&mask_first)
            printf("1");
        else
            printf("0");
        if((i%4)==0)
            printf(" ");
        tmp<<=1;
        ++i;
    }
    printf("\n");
    return 0;
}
