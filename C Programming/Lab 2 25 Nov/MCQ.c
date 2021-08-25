#include<stdio.h>
int main()
{
    int a;
    printf("How many Union Territories does India have?\n(1)5    (2)7\n(3)8    (4)10\nEnter your Option Number: ");
    scanf("%d",&a);
    if(a==3)
        printf("Correct Answer...!!!");
    else
        printf("Wrong Answer. India has 8 Union Territories");
    return 0;
}
