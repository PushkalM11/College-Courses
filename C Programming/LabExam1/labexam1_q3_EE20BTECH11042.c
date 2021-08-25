#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    double a[n],b[n];
    printf("Enter the Values of a: ");
    for(int i=0;i<n;i++)                                        //Storing values within a[n]
    {
        scanf("%lf",&a[i]);
    }
    printf("Enter the Values of b: ");
    for(int i=0;i<n;i++)                                        //Storing values within b[n]
    {
        scanf("%lf",&b[i]);
    }
    for(int i=n-1;i>0;i--)
    {
        b[i]=b[i]+a[i];                                         //The two right most resistances are in series, storing in b[i]
        b[i-1]=(b[i-1]*b[i])/(b[i-1]+b[i]);                     //The two right most resistances are in parallel, storing in b[i-1]
    }
    printf("The effective resistance is: %lf.\n",(a[0]+b[0]));  //Last two series resistances is left out
    return EXIT_SUCCESS;
}
