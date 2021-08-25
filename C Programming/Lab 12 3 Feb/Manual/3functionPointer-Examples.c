#include<stdio.h>
#include<stdlib.h>

int twice(int x)
{
    return 2*x;
}

int square(int x)
{
    return x*x;
}

// Returns f(x), where the function f is passed as an argument
int compute(int (*f)(int),int x)
{
    return (*f)(x);
}

//Computes the iterated function of f iteratively
void iterFun(int (*f)(int),unsigned int d,int *x)
{
    int i;
    for (i=0;i<d;i++){
        *x=(*f)(*x);
    }
}

//Computes the iterated function of f recursively
int iterateFun(int (*f)(int),unsigned int d,int x)
{
    int y;
    if (d==1)
        return (*f)(x);
    y=iterateFun(f,d-1,x);
    return (*f)(y);
}


int main()
{
    int a=5,b,c;
    printf("\n %d",compute(twice,a));
    printf("\n %d",compute(square,a));
    b=iterateFun(twice,6,a);
    c=5;
    iterFun(square,2,&c);
    printf("\n %d %d",b,c);
    return 0;
}
