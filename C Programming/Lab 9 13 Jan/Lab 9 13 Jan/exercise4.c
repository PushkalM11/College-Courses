#include <stdio.h>

int strln(char *s)
{
    int i=0;
    while(s[i]!='\0')
    {
        i+=1;
    }
    return i;
}

int strln_const(const char *s)
{
    int i=0;
    while(s[i]!='\0')
    {
        i+=1;
    }
    return i;
}

void str_cat(char *dest,const char *src)
{
    int a=strln(dest);
    int b=strln_const(src);
    int i,j=0,k=a+b+1;
    for(i=a;i<k;i++)
    {
        dest[i]=src[j];
        j+=1;
    }
}

int main()
{
    char s1[150]="Hello! this is the first string. ";
    const char s2[75]="This is the second string which will be concatenated with the first one.";
    printf("The first string is: %s\nThe second string is: %s\n",s1,s2);
    str_cat(s1, s2);
    printf("The appended strings are: %s\n",s1);
    return 0;
}
