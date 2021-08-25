#include <stdio.h>

int main()
{
    int in,tmp;
    printf("Enter the positive integer: ");
    scanf("%d",&in);
    if(in<=0)                                       //Error case.
    {
        printf("Please enter a valid number!\n");
        return 1;
    }
    tmp=in % 10;                                    //Last digit of in stored in tmp.
    //( (int)1357/(int)10 )=135
    printf("The right rotated number is: %d%d\n",tmp,(in/10));                   //Printing the last digit first and then the rest of the digits.
    return 0;
}
