#include <stdio.h>
#include <string.h>

int char_remove(char input[],char *output)
{
    int x,y=0,z=0;
    int n=(int)strlen(input);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(output[j]==input[i])
            {
                x=0;break;
            }
            else
            {
                x=1;
                continue;
            }
        }
        if(x==1)
        {
            output[y]=input[i];
            y+=1;
            z+=1;
        }
    }
    return z;
}

int main()
{
    char input[50],output[50];
    for(int i=0;i<50;i++)
    {
        output[i]='_';
    }
    printf("Enter the string: ");
    scanf("%s",input);
    int n=char_remove(input,output);
    printf("Output string: ");
    for(int i=0;i<n;i++)
    {
        printf("%c",output[i]);
    }
    printf("\n");
    return 0;
}
