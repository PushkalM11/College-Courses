#include<stdio.h>
#include<string.h>
#include<math.h>

int max_setbit(int in)
{
    int i=-1,mask=1,count=1;
    while(in!=0)
    {
        if((in & mask)==1)
            i=count;
        in=in>>1;
        count+=1;
    }
    return i;
}

int main()
{
    char in[30];
    printf("Enter the string (not more than 30 words: ");
    scanf("%s",in);
    int l=(int)strlen(in);
    int mask=1;
    int n=pow(2,l);
    int tmp,count=1;
    for(int i=1;i<n;i++)
    {
        printf("%d. ",count);
        tmp=i;
        for(int x=0;x<max_setbit(i);x++)
        {
            if((mask&tmp)==1)
            {
                printf("%c",in[x]);
            }
            tmp>>=1;
        }
        count+=1;
        if(i!=n-1)
            printf("\n");
    }
    printf("\n");
    return 0;
}
