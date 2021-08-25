#include <stdio.h>
#include <string.h>

//This function compares s1 and s1, if they are equal it returns 0 else returns 100
int my_compare(char *s1,char *s2,int n)
{
    int r=100;
    for(int i=0;i<n;i++)
    {
        char c1=*(s1+i),c2=*(s2+i);
        if(c1==' '||c1=='\0'||c2==' '||c2=='\0'||c2==13)            //If any of the string has reached their end
        {
            if((c1==' '||c1=='\0')&&(c2==' '||c2=='\0'||c2==13))    //If both the strings have reached their end
                r=0;
        }
        if(c1!=c2)              //If any of the character is different
            break;
    }
    return r;
}

//This function sets all the characters to NULL.
void my_clear(char *in,int n)
{
    for(int i=0;i<n;i++)
        *(in+i)='\0';
}

int main()
{
    char in[20],tmp[20];
    int t,flag=-1;
    my_clear(in,20);
    printf("Enter the word: ");
    scanf("%s",in);
    
    //Checking in the first file
    FILE *f1=fopen("1syllablenouns.txt","r");
    if(f1==NULL)
    {
        printf("Error in opening 1syllablenouns.txt\n");
        return 1;
    }
    while(!feof(f1))
    {
        fgets(tmp,sizeof(tmp),f1);                  //Reading the string
        t=my_compare(in,tmp,20);
        if(t==0)
        {
            printf("The given word %s has 1 syllable.\n",in);
            flag=1;                                 //If found, set flag as 1
            break;
        }
        my_clear(tmp,20);
    }
    if(flag==1)                                     //If found, exit the program
    {
        return 0;
    }
    fclose(f1);
    
    //Checking in the second file
    FILE *f2=fopen("2syllablenouns.txt","r");
    if(f2==NULL)
    {
        printf("Error in opening 2syllablenouns.txt\n");
        return 1;
    }
    while(!feof(f2))
    {
        fgets(tmp,sizeof(tmp),f2);              //Reading the string
        t=my_compare(in,tmp,20);
        if(t==0)
        {
            printf("The given word %s has 2 syllables.\n",in);
            flag=1;                             //If found, set flag as 1
            break;
        }
        my_clear(tmp,20);
    }
    if(flag==1)                                 //If found, exit the program
    {
        return 0;
    }
    fclose(f2);
    
    //Checking in the third file
    FILE *f3=fopen("3syllablenouns.txt","r");
    if(f3==NULL)
    {
        printf("Error in opening 3syllablenouns.txt\n");
        return 1;
    }
    while(!feof(f3))
    {
        fgets(tmp,sizeof(tmp),f3);              //Reading the string
        t=my_compare(in,tmp,20);
        if(t==0)
        {
            printf("The given word %s has 3 syllables.\n",in);
            flag=1;                             //If found, set flag as 1
            break;
        }
        my_clear(tmp,20);
    }
    if(flag==1)                                //If found, exit the program
    {
        return 0;
    }
    fclose(f3);
    
    //Checking in the fourth file
    FILE *f4=fopen("4syllablenouns.txt","r");
    if(f4==NULL)
    {
        printf("Error in opening 4syllablenouns.txt\n");
        return 1;
    }
    while(!feof(f4))
    {
        fgets(tmp,sizeof(tmp),f4);              //Reading the string
        t=my_compare(in,tmp,20);
        if(t==0)
        {
            printf("The given word %s has 4 syllables.\n",in);
            flag=1;                             //If found, set flag as 1
            break;
        }
        my_clear(tmp,20);
    }
    if(flag==1)                                 //If found, exit the program
    {
        return 0;
    }
    fclose(f4);
    //If not found, send an error message
    printf("Unable to find number of syllabyes.\n");
    return 0;
}
