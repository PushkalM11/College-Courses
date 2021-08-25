#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,at_no;
    char sym[3],name[20],at[3],mass[10];
    printf("Enter a number between 1 and 112: ");
    scanf("%d",&n);
    if((n<1)||(n>112))                                          //If invalid atomic number.
    {
        printf("Please enter a valid number!\n");
        return 1;
    }
    FILE *f;
    f=fopen("chemicalElements.txt","r");                        //Opening a file.
    if(f==NULL)                                                 //If file does not exist.
    {
        printf("Error in opening the file!\n");
        return 1;
    }
    for(int i=0;;i++)
    {
        fscanf(f,"%s %s %s %s",at,sym,name,mass);
        at_no=atoi(at);                                         //Reading string as integer;
        if(at_no==n)                                            //If the read at. no. matches the given number.
        {
            printf("Atomic Number: %d \nSymbol: %s \nName: %s \nMass: %s\n",at_no,sym,name,mass);
            break;
        }
    }
    fclose(f);
    return 0;
}

