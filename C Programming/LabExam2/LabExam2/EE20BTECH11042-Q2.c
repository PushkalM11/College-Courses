#include <stdio.h>

struct Polynomial
{
    int n;
    double a[21];
};

typedef struct Polynomial poly;

int main()
{
    poly p;
    printf("Enter the degree of the first polynomial: ");
    scanf("%d",&p.n);
    if(p.n<0)
    {
        printf("Please enter a valid degree!!!\n");
        return 0;
    }
    for(int i=(p.n);i>-1;i--)
    {
        printf("Enter the value of a%d: ",i);
        scanf("%lf",&p.a[i]);
    }
    printf("The coefficients of the derivative are: ");
    if(p.n==0) printf("0.");
    for(int i=(p.n);i>0;i--)
    {
        if(i==1)
            printf("%lf.",(p.a[i]));
        else
            printf("%lf, ",(p.a[i]*(i)));
    }
    printf("\nThe coefficients of the integral are: ");
    for(int i=(p.n);i>-1;i--)
    {
        double x=(double)(p.a[i]/(i+1));
        if(i==0)
            printf("%lf, 0.\n",x);
        else
            printf("%lf, ",x);
    }
    return 0;
}
