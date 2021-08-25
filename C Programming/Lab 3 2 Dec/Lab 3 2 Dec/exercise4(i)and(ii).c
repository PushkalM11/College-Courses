#include<stdio.h>
#include<math.h>

int main()
{
    double x1,x2,x3,y1,y2,y3,area,m1,m2,m3,a1,a2,a3;
    double convert=180.0/3.141592;                               //Conversion factor from radian to degree
    printf("Enter the coordinates of the point (x1,y1): ");
    scanf("%lf %lf",&x1,&y1);
    printf("Enter the coordinates of the point (x2,y2): ");
    scanf("%lf %lf",&x2,&y2);
    printf("Enter the coordinates of the point (x3,y3): ");
    scanf("%lf %lf",&x3,&y3);
    area=fabs(0.5*((x1*(y2-y3))+(y1*(x3-x2))+(x2*y3)-(x3*y2))); //Standard formula of area of triangle
    if(area==0)
        printf("The given 3 points are collinear");
    else
    {
        m1=(y1-y2)/(x1-x2);                                    //Slope of a line formed by (x1,y1) and (x2,y2)
        m2=(y2-y3)/(x2-x3);                                    //Slope of a line formed by (x2,y2) and (x3,y3)
        m3=(y3-y1)/(x3-x1);                                    //Slope of a line formed by (x3,y3) and (x1,y1)
        a1=fabs(convert*atan((m1-m2)/(1+(m1*m2))));            //Angle between lines with slope m1 and m2
        a2=fabs(convert*atan((m2-m3)/(1+(m2*m3))));            //Angle between lines with slope m2 and m3
        a3=fabs(convert*atan((m3-m1)/(1+(m3*m2))));            //Angle between lines with slope m3 and m1
        printf("The area of the triangle formed by the given points is %lf\n",area);
        printf("And the angles of the triangle are(In Degrees) %.2lf, %.2lf, %.2lf",a1,a2,a3);
    }
    return 0;
}

