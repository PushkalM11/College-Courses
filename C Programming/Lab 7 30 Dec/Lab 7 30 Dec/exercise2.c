#include <stdio.h>
#include <stdlib.h>

// This function returns the length of text.
unsigned int stringLength(char text[])
{
    unsigned int i;
    i=0;
    while (text[i]!='\0')
    {
        i=i+1;
    }
    return i;
}

// This function prints the character ch count many times.
void multiCharPrint(char ch,unsigned int count)
{
    unsigned int i=1;
    while (i<=count){
        printf("%c",ch);
        i=i+1;
    }
}


//This function prints the string text, count many times.
void multiStringPrint(char text[],unsigned int count)
{
    unsigned int length=stringLength(text)+1;
    for(unsigned int i=0;i<count;i++)                  //Printing the text count number of times
    {
        for(int j=0;j<length;j++)                      //Printing particular character
            multiCharPrint(text[j], 1);
        printf("\n");
    }
}


//This function prints the substring of the given string text, between indices i and j, inclusive.
void substringPrint(char text[],unsigned int i, unsigned int j)
{
    unsigned int k,l,m;
    for(k=i;k<=j;k++)                                //To print from ith to jth position
    {
        for(l=k;l<=j;l++)                            //To print subset of string between kth and jth positions
        {
            for(m=k;m<=l;m++)                        //To print the string
            {
                printf("%c",text[m]);
            }
            printf("\n");
        }
    }
}


int main()
{
    char string[20]="Applesauce";
    printf("\nLength of \"Applesauce\" is %u\n",stringLength(string));
    int n;
    printf("\nEnter the number of times you want to print: ");
    scanf("%d",&n);
    multiCharPrint('*',n);
    printf("\n");
    multiStringPrint(string,n);
    printf("\n");
    unsigned int i,j;
    printf("Enter the values of indices i and j(Like 0 9): ");
    scanf("%d %d",&i,&j);
    substringPrint(string,i,j);
    return EXIT_SUCCESS;
}
