#include<stdio.h>

int main()
{

    int x,y,z;
    x=15&20;
    y=20&127;
    z=0&127;
    printf("\n x=%d y=%d z=%d",x,y,z);
    x=15>>2;
    y=15<<2;
    printf("\n x=%d y=%d z=%d",x,y,z);
    x=15|20;
    y=20|127;
    z=0|127;
    printf("\n x=%d y=%d z=%d",x,y,z);
}

