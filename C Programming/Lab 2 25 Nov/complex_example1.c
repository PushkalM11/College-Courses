#include<stdio.h>
#include<complex.h>

int main()
{
    double complex z1=2.0+3.0*I,z2;
    double a,b;
    printf("z1=%.2lf+%.2lf*I\n",creal(z1),cimag(z1));
    printf("Enter Real part of z2: ");
    scanf("%lf",&a);
    printf("Enter Imaginary part of z2: ");
    scanf("%lf",&b);
    z2=a+b*I;
    printf("\nz3=z1*z2=%.2lf+%.2lf*I",creal(z1*z2),cimag(z1*z2));
    return 0;
}
