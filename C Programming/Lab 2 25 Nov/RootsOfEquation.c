#include<stdio.h>
#include<math.h>
#include<complex.h>
int main()
{
    float a,b,c,D,r1,r2;
    printf("For the quadratic equation: ax^2+bx+c=0\nEnter a= ");
    scanf("%f",&a);
    if(a==0)
    {
        printf("Error..!!, It's not a Quadratic Equation");
    }
    else
    {
        printf("Enter b= ");
        scanf("%f",&b);
        printf("Enter c= ");
        scanf("%f",&c);
        D=(b*b)-(4*a*c);
        if(D>0)
        {
            r1=((-b)+sqrt(D))/(2*a);
            r2=((-b)-sqrt(D))/(2*a);
            printf("The roots are: %.3f and %.3f\nAnd they are Real and Distinct",r1,r2);
        }
        else if(D==0)
        {
            r1=(-b)/(2*a);
            printf("The Roots are Real and Equal to each other\nAnd are Equal to: %.3f",r1);
        }
        else
        {
            float complex z1=(-b)/(2*a)+(sqrt(-D)/(2*a))*I,z2=(-b)/(2*a)-(sqrt(-D)/(2*a))*I;
            printf("The Roots are Imaginary\nThey are: %.3f+%.3f*I and %.3f+%.3f*I",creal(z1),cimag(z1),creal(z2),cimag(z2));
        }
    }
    return 0;
}
