#include<stdio.h>

double sum(double a,double b)
{
    double c;
    c=a+b;
    return c;
}

int main()
{
    double x,y,z;
    x=2.5;
    y=4.5;
    z=-2.5;
    printf("\n The sum of x and y is %lf",sum(x,y));
    printf("\n The sum of y and z is %lf",sum(y,z));
    printf("\n The sum of z and x is %lf",sum(z,x));
    return 0;
}

