#include<stdio.h>
#include<string.h>

void printbits(unsigned int n)
{
    if (n==0) return;
    printbits(n/2);
    printf(" %u",n%2);
}

// Prints the string str with all possible subsets of the first n characters and the remaining fixed.
void printsubsets(char *str,int n)
{
    char temp[n+1];
    if (n==0)
    {
        printf("\n %s",str);
        return;
    }
    strcpy(temp,str);
    printsubsets(temp,n-1);
    temp[n-1]=' ';
    printsubsets(temp,n-1);
}

int main()
{
    char text[]="PEAR";
    printbits(100);
    printsubsets(text,4);
    return 0;
}
