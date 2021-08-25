#include<stdio.h>

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

//Uncomment and write suitable code inside the function.
/*
//This function prints the string text, count many times.
void multiStringPrint(char text[],unsigned int count)
{

}
*/

//Uncomment and write suitable code inside the function.
/*
//This function prints the substring of the given string text, between indices i and j, inclusive.
void substringPrint(char text[],unsigned int i, unsigned int j)
{

}
*/

int main()
{
    char string[20]="Applesauce";
    printf("\n Length is %u \n",stringLength(string));
    multiCharPrint('*',10);
    return 0;
}
