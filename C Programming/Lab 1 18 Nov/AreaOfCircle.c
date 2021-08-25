#include<stdio.h>
int main()
{
    float r,a,c;
    printf("Enter Radius of Circle: ");
    scanf("%f",&r);
    a=3.14159*r*r,c=2*3.14159*r;
    printf("\nThe Area of the circle is: %.5f \nAnd the circumference of the circle is: %.5f",a,c);
    return 0;
}
