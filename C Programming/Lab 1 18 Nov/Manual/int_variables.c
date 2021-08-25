#include<stdio.h>

main()
{
    int a,b,c;

    a=10;
    b=20;

    printf("\n The value of a is: %d",a);
    printf("\n The values of a and b are: %d and %d", a, b);
    // Note the use of %d. The two "%d" are matched and "replaced" by the compiler to the values of the variables num1 and num2. */

    a = a + b;

    printf("\n Now the values of a and b are: %d and %d",a,b);

    b = b * a;

    printf("\n Now a is %d and b is %d",a,b);
	printf("\n");

}
