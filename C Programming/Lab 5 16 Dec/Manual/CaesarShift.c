#include<stdio.h>

int main()
{
	char text[20],ch;
	int i,shift;

    printf("\n ** This program accepts a string and shifts each English character **");
	printf("\n Enter the string: ");
	fgets(text,20,stdin);
	printf("\n Enter the shift value: ");
	scanf("%d",&shift);

	shift=shift%26;
	if (shift<0) {shift=shift+26;}

    i=0;
    while (text[i]!='\0')
    {
        ch=text[i];
        if ((ch>='a') && (ch<='z'))
        {
            ch=ch-'a'; // If the character is lowercase English, then ch is now in {0,1,...,25}.
            ch=(ch+shift)%26;
            ch=ch+'a'; // Now ch is in {a,b,...,z}
        }
        else if ((ch>='A') && (ch<='Z'))
        {
            ch=text[i]-'A';
            ch=(ch+shift)%26;
            ch=ch+'A';
        }
        text[i]=ch;
        i=i+1;
    }

    printf("\n The shifted string is %s",text);

	return 0;
}
