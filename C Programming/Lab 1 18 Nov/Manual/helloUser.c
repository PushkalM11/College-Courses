/********************************
*Filename: helloUser.c
*********************************/

#include<stdio.h>

int main()
{
    char username[30];

    printf("\n Hello, user. What's your name? ");

    scanf("%s",username); // This is the statement which reads the input that was typed.

	printf("Welcome, %s \n",username);
    return 0;
}
