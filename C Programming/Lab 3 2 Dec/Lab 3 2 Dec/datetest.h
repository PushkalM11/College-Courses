#include<stdio.h>

int datetest(int d,int m,int y)
{
    int lc,a;
    lc=y%4;
    if(m==1&&d>31)
        a=0;
    else if(lc==0&&(m==2&&d>29))            //If leap year
        a=0;
    else if(lc!=0&&(m==2&&d>28))            //If not a leap year
        a=0;
    else if(m==3&&d>31)
        a=0;
    else if(m==4&&d>30)
        a=0;
    else if(m==5&&d>31)
        a=0;
    else if(m==6&&d>30)
        a=0;
    else if(m==7&&d>31)
        a=0;
    else if(m==8&&d>31)
        a=0;
    else if(m==9&&d>30)
        a=0;
    else if(m==10&&d>31)
        a=0;
    else if(m==11&&d>30)
        a=0;
    else if(m==12&&d>31)
        a=0;
    else if(m>12||m<1)
        a=0;
    else
        a=1;
    return a;
}
