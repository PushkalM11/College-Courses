#include<stdio.h>
#include<stdlib.h>

int main()
{
	char filename[30]="numberList.txt",num[5];
	int i;

	FILE *ptr;

	ptr=fopen(filename,"w");

	if (ptr==NULL)
	{
		printf("\n Open Error");
		return 1;
	}

	for (i=1;i<=1000;i++)
	{
	    itoa(i,num,10);
		fprintf(ptr,"%s\n",num);
		//fputs(num,ptr);fputs("\n",ptr);
	}

	fclose(ptr);
	printf("Number list written successfully");

	return 0;
}
