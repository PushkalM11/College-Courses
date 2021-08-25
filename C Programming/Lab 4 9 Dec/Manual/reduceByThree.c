#include<stdio.h>

int main()
{
    int m,n;

    printf("Enter the value of n: ");
    scanf("%d",&n);
    m=n;
    while(m>0)
    {
        printf("%d \n",m);
        m=m-3;
    }
}
