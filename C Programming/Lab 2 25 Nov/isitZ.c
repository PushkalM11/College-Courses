#include<stdio.h>

int main()
{
    char c;
    printf("This program checks whether the input character is Z or z.\nEnter a character: ");
    c=getchar();
    if (c=='Z')
    {
        printf("That was Z. \n");
    }
    else if(c=='z')
    {
        printf("That was z. \n");
    }
    else
    {
        printf("That wasn't either Z or z. \n");
    }
    return 0;
}
