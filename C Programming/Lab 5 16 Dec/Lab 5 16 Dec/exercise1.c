#include<stdio.h>

int main()
{
    char c[100];
    int a=0,e=0,i=0,o=0,u=0,n=0;
    printf("Enter a String: ");
    scanf("%s",c);
    while(c[n]!='\0')
    {
        switch(c[n])
        {
            case 'A':
            case 'a':++a;break;
            case 'E':
            case 'e':++e;break;
            case 'I':
            case 'i':++i;break;
            case 'O':
            case 'o':++o;break;
            case 'U':
            case 'u':++u;break;
        }
        ++n;
    }
    printf("A: %d, E: %d, I: %d, O: %d, U: %d, Srting Length: %d\n",a,e,i,o,u,n);
    return 0;
}
