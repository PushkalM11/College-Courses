#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f;
    f=fopen("1000CommonWords.txt","r");             //Opening file.
    if(f==NULL)                                     //If file does not exist.
    {
        printf("Error in opening the file!\n");
        return 1;
    }
    char word[50];
    int count=0;
    printf("The 7 letter words are:\n");
    for(int i=0;i<1000;i++)
    {
        fscanf(f,"%s",word);
        if(strlen(word)==7)                         //If length of scanned word is 7
        {
            ++count;
            printf("%d. %s\n",count,word);          //Then print.
        }
    }
    fclose(f);
    return 0;
}
