#include<stdio.h>
int main()
{
    float c;
    printf("Enter Temperature in Celsius: ");
    scanf("%f",&c);
    printf("The Temperature in Fahrenheit is: %.3f",((9*c)/5)+32);
    return 0;
}
