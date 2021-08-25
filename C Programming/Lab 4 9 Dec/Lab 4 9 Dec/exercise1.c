#include <stdio.h>
#include<math.h>
#include "factorial_header.h"

int main()
{
    char sub_q;
    int n;
    printf("Enter the question subpart(a or b or c or d): ");
    scanf("%c",&sub_q);
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    
    
    
    if(sub_q=='a')
    {
        for(int i=1;i<=n;i++)
            printf("*");
        printf("\n");
    }
    
    
    
    else if(sub_q=='b')
    {
        int square_num=1,temporary=1;
        printf("Square Numbers between 1 and %d are: ",n);
        for(;square_num<=n;square_num=pow(temporary,2))
        {
            printf("%d ",square_num);
            ++temporary;
        }
        printf("\n");
    }
    
    
    
    else if(sub_q=='c')
    {
        double fact=factorial(n);
        printf("The factorial of %d is: %.0lf\n",n,fact);
    }
    
    
    
    else if(sub_q=='d')
    {
        int i;
        double input_num,sum=0;
        for(i=1;i<=n;++i)
        {
            printf("Enter Number %d :",i);
            scanf("%lf",&input_num);
            sum+=input_num;
        }
        printf("The Sum of the above given numbers are: %lf\n",sum);
    }
    
    
    
    else
        printf("Enter a valid subquestion!!!\n");
    return 0;
}
