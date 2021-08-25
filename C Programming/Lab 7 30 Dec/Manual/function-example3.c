#include<stdio.h>

double successor(double a)
{
    return a+1;
}

void pseudoIncrement(double a)
{
    a=a+1;
}

//Increments the first count many elements of a
void arrayIncrement(double a[],unsigned int count)
{
    unsigned int i;
    for (i=0;i<count;i++)
        a[i]=a[i]+1;
}

int main()
{
    double x,y,z[5]={1,2,3,4,5};
    x=2.5;
    y=successor(x);
    printf("\n The values of x and y are %lf and %lf",x,y);
    pseudoIncrement(x);
    printf("\n The value of x is %lf",x);
    printf("\n The values of z are: %lf %lf %lf %lf %lf",z[0],z[1],z[2],z[3],z[4]);
    arrayIncrement(z,3);
    printf("\n The values of z are: %lf %lf %lf %lf %lf",z[0],z[1],z[2],z[3],z[4]);
    return 0;
}

