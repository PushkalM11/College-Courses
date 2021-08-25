#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int input;
    printf("Enter a number: ");
    scanf("%d",&input);
    int h_place= ceil((input/100));                             //ceil(495/100)=ceil(4.95)=4  ==>hundredth's place
    int last_two= input-(100*h_place);                          //495-4*100=495-400=95        ==>Last Two Digits
    int t_place= ceil((last_two/10));                           //ceil(95/10)=ceil(9.5)=9     ==>Tenth's Place
    int o_place= last_two%10;                                   //95 % 10=5                   ==>One's Place
    printf("The number is");
    switch(h_place)
    {
        case 1: printf(" one hundred");break;
        case 2: printf(" two hundred");break;
        case 3: printf(" three hundred");break;
        case 4: printf(" four hundred");break;
        case 5: printf(" five hundred");break;
        case 6: printf(" six hundred");break;
        case 7: printf(" seven hundred");break;
        case 8: printf(" eight hundred");break;
        case 9: printf(" nine hundred");break;
    }
    if((h_place!=0)&&((t_place!=0)||(o_place!=0)))              //For printing " and " between hundredth and tens/ones place
    {
        printf(" and");
    }
    if(t_place!=1)                                              //Since naming is different, example "Eleven" and not " ten one"
    {
        switch(t_place)
        {
            case 2: printf(" twenty");break;
            case 3: printf(" thirty");break;
            case 4: printf(" fourty");break;
            case 5: printf(" fifty");break;
            case 6: printf(" sixty");break;
            case 7: printf(" seventy");break;
            case 8: printf(" eighty");break;
            case 9: printf(" ninety");break;
        }
        switch(o_place)
        {
            case 1: printf(" one");break;
            case 2: printf(" two");break;
            case 3: printf(" three");break;
            case 4: printf(" four");break;
            case 5: printf(" five");break;
            case 6: printf(" six");break;
            case 7: printf(" seven");break;
            case 8: printf(" eight");break;
            case 9: printf(" nine");break;
        }
    }
    else
    {
        switch(last_two)
        {
            case 10:printf(" ten");break;
            case 11:printf(" eleven");break;
            case 12:printf(" twelve");break;
            case 13:printf(" thirteen");break;
            case 14:printf(" fourteen");break;
            case 15:printf(" fifteen");break;
            case 16:printf(" sixteen");break;
            case 17:printf(" seventeen");break;
            case 18:printf(" eighteen");break;
            case 19:printf(" nineteen");break;
        }
    }
    printf(".\n");
    return EXIT_SUCCESS;
}
