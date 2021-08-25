/*
Filename: fileRead-fgets.c
Description: Read from a text file using fgets
*/
#include<stdio.h>

int main()
{
	char filename[30],string[200];
	char *flag;

	FILE *ptr;

	printf("\n Enter the file name: ");
	scanf("%s",filename);

	ptr=fopen(filename,"r");

	if (ptr==NULL)
	{
		printf("\n Open Error");
		return 1;
	}

	while(!feof(ptr))
	{
		flag=fgets(string,sizeof(string),ptr);
		if (flag!=NULL)
			printf("%s",string);
	}

	fclose(ptr);

	return 0;
}
