#include<stdio.h>
#include<complex.h>

int main()
{
    double complex z=2.0+3.0*I;
    printf(" %lf %lf",creal(z),cimag(z));

    return 0;
}


