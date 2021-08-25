#include<stdio.h>
#include<stdlib.h>

struct complex_t
{
    double real;
    double img;
};
typedef struct complex_t complex;

void twice(void *x)
{
    *(int *)x=2*(*(int* )x);
}

void conjugate(void *x)
{
    ((complex *)x)->img=-((complex *)x)->img;
}

// Computes the iterated function of f iteratively,
// This assumes that f stores its result in its argument!
void iterFun(void (*f)(void *),unsigned int d,void *x)
{
    int i;
    for (i=0;i<d;i++){
        //Fill this!
        (*f)(x);
    }
}


int main()
{
    int a;
    complex z;

    a=5;
    iterFun(twice,3,&a);
    printf("\n a=%d",a);

    z.real=2.5;
    z.img=5.0;
    iterFun(conjugate,3,(void *)&z);
    printf("\n z=%lf + %lf i",z.real,z.img);
    iterFun(conjugate,3,(void *)&z);
    printf("\n z=%lf + %lf i",z.real,z.img);

    return 0;
}
