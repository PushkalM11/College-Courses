#include <stdio.h>

void swap(double *a,double *b)
{
    double tmp=*a;
    *a=*b;
    *b=tmp;
}

int main()
{
    double a,b;
    printf("Enter the value of\na = ");
    scanf("%lf",&a);
    printf("b = ");
    scanf("%lf",&b);
    swap(&a,&b);
    printf("The values after swapping: a = %lf and b = %lf\n",a,b);
    return 0;
}
