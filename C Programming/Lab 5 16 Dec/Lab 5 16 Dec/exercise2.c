#include <stdio.h>

int main()
{
    int n,max,min;
    printf("Enter number of integers for input: ");
    scanf("%d",&n);
    int input[n];
    for(int i=1;i<=n;++i)
    {
        printf("Enter Number %i: ",i);
        scanf("%d",&input[(i-1)]);
    }
    max=input[0];
    min=input[0];
    for(int i=1;i<=n-1;++i)
    {
        if(max<input[i])                              //To check for max
            max=input[i];
        if(min>input[i])                              //To check for min
            min=input[i];
    }
    printf("The greatest number from the given numbers is: %d\nThe smallest number from the given numbers is: %d\n",max,min);
    return 0;
}
