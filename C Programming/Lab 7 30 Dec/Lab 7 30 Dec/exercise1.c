#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    double matrix[n][n],vector[n];
    printf("Enter the values for a row like: 5 39 12 .....\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the values of the matrix M for row %d: ",i+1);
        for(j=0;j<n;j++)
        {
            scanf("%lf",&matrix[i][j]);
        }
    }
    printf("Enter the vector(Like 5 39 12 ......): ");
    for(i=0;i<n;i++)
    {
        scanf("%lf",&vector[i]);
    }
    printf("The dot product of Matrix(%d x %d) and the Vector(%d x 1) is:\n",n,n,n);
    for(i=0;i<n;i++)
    {
        double tmp=0;
        for(j=0;j<n;j++)
        {
            tmp+=matrix[i][j]*vector[j];
        }
        printf("%lf\n",tmp);
    }
    return EXIT_SUCCESS;
}
