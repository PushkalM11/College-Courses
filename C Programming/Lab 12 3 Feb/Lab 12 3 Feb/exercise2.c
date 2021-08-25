#include <stdio.h>
#include <stdlib.h>

int main()
{
    double **matrix;
    unsigned int m,n;
    printf("Enter the value of m: ");
    scanf("%u",&m);
    printf("Enter the value of n: ");
    scanf("%u",&n);
    matrix=(double **)malloc(m*sizeof(double *));               //Allotting memory for the rows of the matrix.
    for(unsigned int i=0;i<m;i++)
    {
        matrix[i]=(double *)malloc(n*sizeof(double));           //Allotting memory for a column.
    }
    if(matrix==NULL)
    {
        printf("Error!\n");
        free(matrix);
        return 1;
    }
    else
    {
        printf("Memory Allocation Successfull.\n");
        free(matrix);
        return 0;
    }
}
