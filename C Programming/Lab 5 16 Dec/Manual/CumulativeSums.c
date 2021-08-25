#include<stdio.h>

int main()
{

    int a[20],b[20],i,n;

    printf("\n **Program to find cumulative sum of n integers **");
    printf("\n Enter the value of n: ");
    scanf("%d",&n);

    i=0;
    while (i<n)
    {
        printf("Enter the value of integer %d: ",i+1);
        scanf("%d",&a[i]);
        i=i+1;
    }
    b[0]=a[0];
    i=1;
    while (i<n)
    {
        b[i]=b[i-1]+a[i];
        i=i+1;
    }

    for (i=0;i<n;i++)
        printf(" %d",b[i]);

    return 0;
}
