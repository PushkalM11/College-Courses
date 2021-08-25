#include <stdio.h>
#include <string.h>

struct string_t
{
    char s[20];
};

typedef struct string_t in_str;

int compare(char *s1, char *s2)
{
    int x=-1,n1=(int)strlen(s1),n2=(int)strlen(s2),tmp1,tmp2,i;
    int n=(n1>n2)?n2:n1;
    for(i=0;i<n;i++)
    {
        tmp1=*(s1+i);
        tmp2=*(s2+i);
        if(tmp1<tmp2)
        {
            x=1;
            break;
        }
        if(tmp1>tmp2)
        {
            x=2;
            break;
        }
    }
    if(i==n)
    {
        if((n==n1)&&(n1!=n2)) x=1;
        if((n==n2)&&(n1!=n2)) x=2;
        if(n1==n2) x=0;
    }
    return x;
}

int main()
{
    printf("\nPlease enter all the strings in upper-case/lower-case only.\n\n");
    int n,index=0;
    printf("Enter the number of strings: ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Please enter a number greater than 0.\n");
        return 0;
    }
    in_str in[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter string %d: ",i+1);
        scanf("%s",in[i].s);
    }
    for(int i=1;i<n;i++)
    {
        int y=compare(in[index].s,in[i].s);
        if(y==2) index=i;
    }
    printf("The earliest string is %s.\n",in[index].s);
    return 0;
}
