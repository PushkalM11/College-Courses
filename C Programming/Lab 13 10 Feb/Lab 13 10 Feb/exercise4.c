#include <stdio.h>
#include <string.h>

int IsHeterogram(char in[])
{
    int out=-1,i,j,l=(int)strlen(in);
    char tmp[l];
    tmp[0]=in[0];
    for(i=1;i<l;i++)
    {
        for(j=0;j<i;j++)
        {
            if(tmp[j]==in[i])
                break;
        }
        if(j!=i)
        {
            out=0;
            break;
        }
        else
            tmp[i]=in[i];
    }
    if(i==l)
        out=1;
    return out;
}

int main()
{
    char subq;
    printf("Enter the question subpart (a or b): ");
    scanf("%c",&subq);
    if(subq=='a')
    {
        char c[100];
        printf("Enter a string: ");
        scanf("%s",c);
        int n=IsHeterogram(c);
        if(n==1)
            printf("The word is a Heterogram.\n");
        else
            printf("The word is not a Heterogram.\n");
    }
    else if(subq=='b')
    {
        FILE *f_in;
        f_in=fopen("12letterwords.txt","r");
        if(f_in==NULL)
        {
            printf("Error in opening the file!\n");
            return 1;
        }
        FILE *f_out;
        f_out=fopen("12letter-Hgrams.txt","w");
        if(f_out==NULL)
        {
            printf("Error in creating a file!\n");
            return 1;
        }
        char tmp[12];
        int i=0;
        for(int j=0;i!=146;j++)
        {
            int out=-1;
            fscanf(f_in,"%s",tmp);
            out=IsHeterogram(tmp);
            if(out==1)
            {
                i+=1;
                fprintf(f_out,"%d. %s\n",i,tmp);
            }
        }
        printf("146 words were printed, please check 12letter-Hgrams.txt\n");
        fclose(f_in);
        fclose(f_out);
    }
    else
    {
        printf("Enter the correct subpart (a or b)!\n");
    }
    return 0;
}
