#include <stdio.h>
#include <stdlib.h>

double sumarray(double input[],int i, int j)
{
    double sum=0;
    for(int k=i;k<=j;k++)
    {
        sum+=input[k];
    }
    return sum;
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    double input[n];
    printf("Enter the values of the array(Like 3 4 9.....): ");
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&input[i]);
    }
    int i,j;
    printf("Enter the indices i and j(Like 0 9): ");
    scanf("%d %d",&i,&j);
    printf("The sum of numbers is: %lf\n",sumarray(input,i,j));
    return EXIT_SUCCESS;
}
