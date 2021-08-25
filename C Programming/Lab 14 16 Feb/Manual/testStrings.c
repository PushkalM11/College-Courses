#include "myString.h"
#include<stdio.h>


int main()
{
	char string[20];
	readString(string,20);
	printMany(string,3);
	printVertical(string);

	return 0;
}

