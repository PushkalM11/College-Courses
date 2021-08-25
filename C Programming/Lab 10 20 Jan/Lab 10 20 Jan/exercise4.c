#include <stdio.h>

struct Polynomial
{
    int n;
    double a[100];
};

typedef struct Polynomial poly;

int main()
{
    int n1,n2;
    printf("Enter the degree of first polynomial: ");
    scanf("%d",&n1);
    poly px;
    px.n=n1;
    for(int i=n1;i>-1;i--)
    {
        printf("Enter the value of a%d: ",i);
        scanf("%lf",&px.a[n1-i]);
    }
    printf("Enter the degree of second polynomial: ");
    scanf("%d",&n2);
    poly qx;
    px.n=n2;
    for(int i=n2;i>-1;i--)
    {
        printf("Enter the value of a%d: ",i);
        scanf("%lf",&qx.a[n2-i]);
    }
    if(n1<n2)
    {
        for(int i=0;i<n1+1;i++)
        {
            if(i==0||px.a[i]<0)
                printf("%lfx^%d",px.a[i],n1-i);
            else
                printf("+%lfx^%d",px.a[i],n1-i);
        }
        printf("\n");
    }
    else
    {
        int t1=n1-n2;
        for(int t=0;t<=t1;t++)
        {
            double x=(px.a[0])/(qx.a[0]);
            for(int i=0;i<=n2;i++)
                px.a[i]=(px.a[i])-((qx.a[i])*x);
            for(int i=0;i<=(n1-t);i++)
                px.a[i]=px.a[i+1];
        }
        n1=n1-t1-1;
        for(int i=0;i<=n1;i++)
        {
            if(i==0||px.a[i]<0)
                printf("%lfx^%d",px.a[i],n1-i);
            else
                printf("+%lfx^%d",px.a[i],n1-i);
        }
        printf("\n");
    }
    return 0;
}

