#include<stdio.h>
int main()
{
    char name[20];
    printf("Hello, user. What’s your name?-");
    scanf("%s",name);
    name[0]='Z';
    printf("Welcome, %s",name);
    return 0;
}
