#include<stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    c=a/b;
    printf("The quotient when %d is divided by %d is %d and the remainder is %d",a,b,c,(a%b));
    return 0;
}
