#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char fname[20],tmp[100];
    printf("Enter the text file name: ");
    scanf("%s",fname);
    f=fopen(fname,"r");
    if(f==NULL)
    {
        printf("Error in opening the file!\n");
        return 1;
    }
    fpos_t *pos;
    pos=(fpos_t *)calloc(10000,sizeof(fpos_t));
    int count=0,i;
    while(!feof(f))
    {
        fgets(tmp,sizeof(tmp),f);
        fgetpos(f,(pos+count));
        count+=1;
    }
    count-=2;
    for(i=count;i>-1;i--)
    {
        fsetpos(f,(pos+i));
        fgets(tmp,sizeof(tmp),f);
        printf("%s",tmp);
        if(feof(f))
            printf("\n");
    }
    fseek(f,0,SEEK_SET);
    fgets(tmp,sizeof(tmp),f);
    printf("%s",tmp);
    free(pos);
    fclose(f);
    return 0;
}
