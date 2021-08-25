#include <stdio.h>

int main()
{
    printf("Copying data from file 2 to file 1-\n");
    FILE *f1,*f2;
    char fname1[20],fname2[20],tmp;
    printf("Enter the filename for first file: ");
    scanf("%s",fname1);
    f1=fopen(fname1,"a");
    if(f1==NULL)
    {
        printf("Error in opening first file!\n");
        return 1;
    }
    printf("Enter the filename for second file: ");
    scanf("%s",fname2);
    f2=fopen(fname2,"r");
    if(f2==NULL)
    {
        printf("Error in opening second file!\n");
        return 1;
    }
    tmp=fgetc(f2);
    while(!feof(f2))
    {
        fprintf(f1,"%c",tmp);
        tmp=fgetc(f2);
    }
    printf("Success! Please check %s.\n",fname1);
    fclose(f1);
    fclose(f2);
    return 0;
}
