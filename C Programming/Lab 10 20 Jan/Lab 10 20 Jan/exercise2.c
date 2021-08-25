#include <stdio.h>
#include <string.h>

void permute(char *str,int n)
{
    char tmp[n];
    if(n==1)
    {
        printf("%s\n",str);
        return;
    }
    strcpy(tmp,str);
    permute(tmp,n-1);
}

int main()
{
    char input[50];
    int n;
    printf("Enter the string: ");
    scanf("%s",input);
    printf("Enter a number: ");
    scanf("%d",&n);
    permute(input,n);
    return 0;
}
