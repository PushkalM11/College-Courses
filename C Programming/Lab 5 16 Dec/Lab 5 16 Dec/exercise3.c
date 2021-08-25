#include <stdio.h>

int main()
{
    char s[100],tmp;
    printf("Enter the string(Without any spaces): ");
    scanf("%s",s);
    int n,j=0;
    printf("Enter the number of left-rotations: ");
    scanf("%d",&n);
    while(s[j]!='\0')                                   //To check number of characters entered
        ++j;
    for(int i=1;i<=n;++i)
    {
        tmp=s[0];
        for(int k=0;k<=j-2;++k)                        
            s[k]=s[k+1];
        s[j-1]=tmp;
    }
    printf("The rotated string is: %s\n",s);
    return 0;
}
