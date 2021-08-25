#include<stdio.h>

long binomial(long n,long r)
{
    long x,y;
    if (r==0) return 1;
    if (r>n) return 0;
    x=binomial(n-1,r);
    y=binomial(n-1,r-1);
    printf(" %ld",x+y);
    return x+y;
}

int main()
{
    binomial(3,2);
    return 0;
}
