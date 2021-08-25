#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int n)
{
    if(n==0)
        return 1;
    return (n*factorial(n-1));
}

unsigned long long fallingFactorial(int x , int n)
{
    int k=x-n;
    return (factorial(x)/factorial(k));
}

unsigned long long realBinomialCoefficient(int x,int n)
{
    return (fallingFactorial(x,n)/factorial(n));
}

int main()
{
    char q;
    printf("Enter the subquestion(a or b): ");
    scanf("%c",&q);
    if(q=='a')
    {
        int x;
        printf("Enter the value of x: ");
        scanf("%d",&x);
        int n;
        printf("Enter the value of n: ");
        scanf("%d",&n);
        printf("%llu\n",fallingFactorial(x,n));
    }
    else if(q=='b')
    {
        int x;
        printf("Enter the value of x: ");
        scanf("%d",&x);
        int n;
        printf("Enter the value of n: ");
        scanf("%d",&n);
        printf("%llu\n",realBinomialCoefficient(x,n));
    }
    else
        printf("Enter a valid subquestion(from a or b) !\n");
    return EXIT_SUCCESS;
}
