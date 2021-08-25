#include <stdio.h>
#include <complex.h>

struct complex_t
{
    double x;
    double y;
};

typedef struct complex_t complext;

complext complex_sum(complext a,complext b)
{
    complext sum;
    sum.x=a.x+b.x;
    sum.y=a.y+b.y;
    return sum;
}

complext complex_prod(complext a,complext b)
{
    complext sum;
    sum.x=((a.x)*(b.x))-((a.y)*(b.y));
    sum.y=((a.y)*(b.x))+((a.x)*(b.y));
    return sum;
}

void part3(double m,double n,double complex *c)
{
    printf("\nAn example of a complex number: %lf + %lf*I\n",creal(*c),cimag(*c));
    printf("The first complex number is: %lf + %lf*I\n",m,n);
}

int main()
{
    complext a,b,sum,prod;
    double complex c=2.0+3.0*I;
    printf("\nEnter the first complex number (Like for 2 + 3*I, enter 2 3): ");
    scanf("%lf %lf",&a.x,&a.y);
    printf("Enter the second complex number: ");
    scanf("%lf %lf",&b.x,&b.y);
    sum=complex_sum(a,b);
    printf("\nThe sum of the two given complex numbers are: %lf + %lf*I\n",sum.x,sum.y);
    prod=complex_prod(a,b);
    printf("\nThe product of the two given complex numbers are: %lf + %lf*I\n",prod.x,prod.y);
    part3(a.x,a.y,&c);
    return 0;
}
