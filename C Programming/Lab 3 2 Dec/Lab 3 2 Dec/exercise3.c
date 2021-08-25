#include<stdio.h>
#include"datetest.h"
int main()
{
    int d,m,y,lc,td=0,y1,y2,day;
    printf("Enter Date Month and Year(DD MM YYYY) in numbers: ");
    scanf("%d %d %d",&d,&m,&y);
    int a=datetest(d,m,y);
    if(a==0)
    {
        printf("Please Enter a Valid Date !!\n");
    }
    else
    {
    y1=y-2000;
    lc=y1%4;                                                 //Number of years from the previous leap year
    y2=y1/4;                                                 //Number of leap years between 2000 and given year
    if(lc==0)                                                //If a leap year
    {
        td=(365*(y1-y2))+(366*(y2));                         //Number of days from 1st Jan 2000 to 31st Dec of previous year
        switch(m)
        {
            case 1:break;
            case 2:td+=31;break;
            case 3:td+=60;break;
            case 4:td+=91;break;
            case 5:td+=121;break;
            case 6:td+=152;break;
            case 7:td+=182;break;
            case 8:td+=213;break;
            case 9:td+=244;break;
            case 10:td+=274;break;
            case 11:td+=305;break;
            case 12:td+=335;break;
        }
        td=td+d-1;
    }
    else                                                   //If not a leap year
    {
        td=(365*(y1-y2-1))+(366*(y2+1));                   //Number of days from 1st Jan 2000 to 31st Dec of previous year
        switch(m)
        {
            case 1:break;
            case 2:td+=31;break;
            case 3:td+=59;break;
            case 4:td+=90;break;
            case 5:td+=120;break;
            case 6:td+=151;break;
            case 7:td+=181;break;
            case 8:td+=212;break;
            case 9:td+=243;break;
            case 10:td+=273;break;
            case 11:td+=304;break;
            case 12:td+=334;break;
        }
        td=td+d-1;
    }
    //I tried to combine the above two switch cases but I was facing some errors.
    
    
    day=td%7;                                             //Number of odd days
    switch(day)
    {
        case 0:printf("It is a Saturday\n");break;
        case 1:printf("It is a Sunday\n");break;
        case 2:printf("It is a Monday\n");break;
        case 3:printf("It is a Tuesday\n");break;
        case 4:printf("It is a Wednesday\n");break;
        case 5:printf("It is a Thursday\n");break;
        case 6:printf("It is a Friday\n");break;
    }
    }
    return 0;
}

