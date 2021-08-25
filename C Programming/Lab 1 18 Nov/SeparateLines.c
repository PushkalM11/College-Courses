#include<stdio.h>
int main()
{
    int input,hplace,c,tplace,oplace;
    printf("Enter a number less than 1000 :");
    scanf("%d",&input);
    hplace=input/100;c=input-(hplace*100),tplace=c/10,oplace=c-(tplace*10);
    printf("\nThe number in the hundredth place is: %d",hplace);
    printf("\nThe number in the tens place is: %d",tplace);
    printf("\nThe number in the ones place is: %d",oplace);
    return 0;
}
