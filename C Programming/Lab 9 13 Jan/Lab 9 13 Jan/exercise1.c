#include <stdio.h>

int main()
{
    int x[2][3][4],*a;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<4;k++)
            {
                a=&x[i][j][k];
                printf("%p  ",a);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
