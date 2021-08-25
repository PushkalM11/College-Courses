#include<stdio.h>
#include<math.h>
#define PI 3.1416

int main()
{
    int i;
    unsigned int n;
    double sine,cosine,tangent;
    double angle;
    double angle_deg;

    i=0;

    printf("Enter the value of n: ");
    scanf("%u",&n);

    printf("x sin cos tan");
    while (i<n)
    {
        angle=i*PI/n;
        sine=sin(angle);
        cosine=cos(angle);
        tangent=tan(angle);
        angle_deg=angle*180/PI;
        printf("\n %0.2f %0.2f %0.2f %0.2f",angle_deg,sine,cosine,tangent);
        i=i+1;
    }

	return 0;
}
