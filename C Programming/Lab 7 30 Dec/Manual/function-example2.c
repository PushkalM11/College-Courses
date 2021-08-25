#include<stdio.h>

long long factorial(unsigned int n)
{
    long long f,i;
    f=1;
    for (i=2;i<=(long long)n;i++)
        f=f*i;
    return f;
}


// This function returns the largest element between indices first and last, inclusive.
double maxsubList(double list[],unsigned int first,unsigned int last)
{
    double max;
    unsigned int i;
    max=list[first];
    i=first+1;
    while (i<=last)
    {
        if (list[i]>max){max=list[i];}
        i=i+1;
    }
    return max;
}



int main()
{
    unsigned int n=8;
    double a[10]={4.0,1.6,2.7,5.5,2.0,3.0};
    printf("The factorial of n is %lld",factorial(n));
    printf("\n Max in the range a[0,2] is %lf",0,2,maxsubList(a,0,2));
    printf("\n Max in the range a[1,3] is %lf",maxsubList(a,1,3));
    return 0;
}
