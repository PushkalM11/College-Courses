#include <stdio.h>
#include "exercise5.h"

int main()
{
    long double a,b;
    printf("Enter first number: ");
    scanf("%Lf",&a);
    printf("Enter second number: ");
    scanf("%Lf",&b);
    printf("Their sum is: %Lf\n",my_sum(a,b));
    printf("Their difference is: %Lf\n",my_subtraction(a,b));
    printf("Their product is: %Lf\n",my_product(a,b));
    my_division(a,b);
    return 0;
}
