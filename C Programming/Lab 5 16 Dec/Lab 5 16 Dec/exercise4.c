#include <stdio.h>

int main()
{
    int m,n;
    printf("Enter the value of m: ");
    scanf("%d",&m);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(int i=1;i<=m;++i)
    {
        if(i==1||i==m)
        {
            for(int j=1;j<=n;++j)
                printf("* ");
            printf("\n");
        }
        else
        {
            printf("* ");
            for(int j=1;j<=n-2;++j)
                printf("  ");
            printf("*");
            printf("\n");
        }
    }
    return 0;
}
