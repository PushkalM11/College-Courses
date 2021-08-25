#include<stdio.h>

int main()
{
    char days[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int matrix[3][3]={8,1,6,3,5,7,4,9,2};
    int anothermatrix[3][3]={{1,0,0},{0,1,0},{0,0,1}};
    int i,j;

    for (i=0;i<7;i++)
        printf("\n %s",days[i]);

    for (i=0;i<3;i++)
    {
        printf("\n");
        for (j=0;j<3;j++)
            printf(" %d",anothermatrix[i][j]);
    }

    //However, the assignment statement for arrays CANNOT be used outside the declaration.
    //days[0]="Tuesday";
    //matrix[3][3]={8,1,6,3,5,7,4,9,2};
    return 0;
}
