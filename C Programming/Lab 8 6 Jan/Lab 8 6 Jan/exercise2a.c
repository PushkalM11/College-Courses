#include <stdio.h>
#include <math.h>

#define rad_to_degree (180/3.1415926535)

struct xypoint_t
{
    double x;
    double y;
};

struct rtpoint_t
{
    double r;
    double t;
};

typedef struct xypoint_t xypt;
typedef struct rtpoint_t rtpt;

rtpt xy_to_rt(xypt xy)
{
    rtpt rt;
    rt.r=sqrt(pow(xy.x,2)+pow(xy.y,2));
    rt.t=rad_to_degree*atan((xy.y/xy.x));
    return rt;
}

int main()
{
    xypt xy;
    rtpt rt;
    printf("Enter x-y coordinates(Like for (11,5) enter as 11 5): ");
    scanf("%lf %lf",&xy.x,&xy.y);
    rt=xy_to_rt(xy);
    printf("The r-t coordinates are: (%lf,%lf)\n",rt.r,rt.t);
    return 0;
}
