#include<stdio.h>

int main()
{
    int x;
    x=3;
    switch(x)
    {
    case 1:
        printf("\n One");
    case 2:
        printf("\n Two");
    case 3:
        printf("\n Three");
    case 4:
        printf("\n Four");
    default:
        printf("\n Bye");
    }
    return 0;
}
