#include<stdio.h>

int main()
{
    char c,s;
    int i;
    printf("Enter an english letter: ");
    scanf("%c",&c);
    printf("Enter a whole number: ");
    scanf("%d",&i);
    s=c+i;
    printf("The letter %c shifted by %d positions is %c\n",c,i,s);
    return 0;
}
