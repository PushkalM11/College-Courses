#include<stdio.h>

void inc_by_address(int *a)
{
    *a=*a+1;
}

void not_really_inc(int a)
{
    a=a+1;
}

int main()
{
    int x=5,y=10;
    printf("\n %d %d",x,y);
    inc_by_address(&x);
    not_really_inc(y);
    printf("\n %d %d",x,y);
    inc_by_address(&y);
    not_really_inc(x);
    printf("\n %d %d",x,y);

    return 0;
}
