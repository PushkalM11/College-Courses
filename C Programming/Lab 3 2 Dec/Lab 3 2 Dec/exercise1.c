#include<stdio.h>
//The objective here is to re-assign the values of a,b,c such that a>b>c
int main()
{
    int a,b,c,x;
    printf("Enter 3 Numbers: ");
    scanf("%d %d %d",&a,&b,&c);
    if(b>a)
    {
        x=b;
        b=a;
        a=x;
    }
    if(c>b)
    {
        x=c;
        c=b;
        b=x;
    }
    if(b>a)
    {
        x=b;
        b=a;
        a=x;
    }
    printf("The numbers in increasing order are: %d, %d, %d\n",c,b,a);
    return 0;
}
