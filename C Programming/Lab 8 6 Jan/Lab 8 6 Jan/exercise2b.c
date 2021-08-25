#include <stdio.h>
#include <math.h>

#define degree_to_rad (3.1415926535/180)

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

xypt rt_to_xy(rtpt rt)
{
    xypt xy;
    xy.y=rt.r*sin(degree_to_rad*rt.t);
    xy.x=rt.r*cos(degree_to_rad*rt.t);
    return xy;
}

int main()
{
    xypt xy;
    rtpt rt;
    printf("Enter r-theta coordinates, theta in degrees(Like for (3,50) enter as 3 50): ");
    scanf("%lf %lf",&rt.r,&rt.t);
    xy=rt_to_xy(rt);
    printf("The x and y coordinates are: (%lf,%lf)\n",xy.x,xy.y);
    return 0;
}
