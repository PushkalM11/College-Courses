#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Considering the polynomial as:
//a0 + a1*x + a2*x^2 + a3*x^3 +............ an*x^n
typedef struct
{
    int n;
    double a[51];
} poly;

double value_poly(poly p, double x)
{
    double value=0;
    int tmp=p.n+1;
    for(int i=0;i<tmp;i++)
    {
        value+=p.a[i]*pow(x,i);
    }
    return value;
}

double binary_search_polyroot(poly p,double a,double b,double t)
{
    double tmp;
    while(1)
    {
        if(fabs(a-b)<t)
            break;
        tmp=((a+b)/2);
        if(value_poly(p,tmp)==0)
            return tmp;
        else if((value_poly(p,tmp)*value_poly(p,a))<0)
            b=tmp;
        else
            a=tmp;
    }
    return ((a+b)/2);
}

int main()
{
    printf("Searching for roots of the given polynomial using binary search method-\n");
    poly p;
    int tmp;
    printf("Enter the degree of polynomial(From 1 to 50 only) : ");
    scanf("%d",&p.n);
    if(p.n<1||p.n>50)
    {
        printf("Degree exceeds the limit!\n");
        return 1;
    }
    tmp=p.n+1;
    printf("The polynomial is of the form a0 + a1*x + a2*x^2 + a3*x^3 +............ an*x^n\n");
    for(int i=0;i<tmp;i++)
    {
        printf("Enter the value of a%d: ",i);
        scanf("%lf",&p.a[i]);
    }
    double a,b,t,root;
    printf("Please enter a and b such that f(a)*f(b)<0 -\n");
    while(1)
    {
        printf("Enter the value of a: ");
        scanf("%lf",&a);
        printf("Enter the value of b: ");
        scanf("%lf",&b);
        if(value_poly(p,a)*value_poly(p,b)>0)
            printf("Please re-enter valid a and b!");
        else
            break;
    }
    if(b<a)
    {
        double tmp=b;
        b=a;
        a=tmp;
    }
    if(value_poly(p,a)==0)
    {
        printf("The root is: %lf\n",a);
        return 0;
    }
    if(value_poly(p,b)==0)
    {
        printf("The root is: %lf\n",b);
        return 0;
    }
    printf("Enter the precision t: ");
    scanf("%lf",&t);
    if(t<0)
    {
        printf("Please enter a valid precision!\n");
        return 1;
    }
    root=binary_search_polyroot(p,a,b,t);
    printf("Approximately one root between %lf and %lf is: %lf\n",a,b,root);
    return 0;
}
