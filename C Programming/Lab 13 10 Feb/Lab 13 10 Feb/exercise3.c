#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year,tmp=7;
    printf("Enter a year between 1939 and 2019: ");
    scanf("%d",&year);
    if(year<1939||year>2019)                                //Checking for invalid year.
    {
        printf("Please enter a valid year!\n");
        return 1;
    }
    FILE *f;
    f=fopen("academylist-movies.txt","r");                  //Opening a file.
    if(f==NULL)                                             //If file does not exist.
    {
        printf("Error in opening the file!\n");
        return 1;
    }
    printf("The movie that won the Academy Award for the best film in %d is:\n",year);
    char s[56],yr[4];
    for(int i=0;;i++)
    {
        fgets(s,57,f);                                      //Scanning the whole sentence.
        for(int i=0;i<4;i++)
            yr[i]=s[i];
        if(atoi(yr)==year)                                  //If the scanned sentence corresponds to the given year.
        {
            for(;tmp<56;tmp++)                              //Printing the Name of the movie.
            {
                printf("%c",s[tmp]);
            }
            break;
        }
        for(int i=0;i<56;i++)                               //Resetting the array.
            s[i]=0;
    }
    fclose(f);
    return 0;
}
