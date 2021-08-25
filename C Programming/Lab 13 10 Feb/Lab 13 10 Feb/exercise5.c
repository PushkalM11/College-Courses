#include <stdio.h>

int main()
{
    char headerInfo[55];
    unsigned char R,G,B,tmp;
    FILE *f_in,*f_out;
    f_in=fopen("redSanta.bmp","rb");                //Opening a file.
    if(f_in==NULL)                                  //If file does not exist.
    {
        printf("\n Open Error");
        return 1;
    }
    f_out=fopen("redSantaCopy.bmp","wb");           //Creating a file.
    if(f_out==NULL)                                 //If error in creating.
    {
        printf("Open Error\n");
        return 1;
    }
    fread(headerInfo,54,1,f_in);
    fwrite(headerInfo,54,1,f_out);
    while(!feof(f_in))
    {
        B=fgetc(f_in);
        G=fgetc(f_in);
        R=fgetc(f_in);
        if((R>20) && (G==0 || G==1) && (B==0 || B==1))                      //Santa's suit colours.
        {                                                                   //Exchanging red with blue.
            tmp=R;
            R=B;
            B=tmp;
        }
        fputc(B,f_out);
        fputc(G,f_out);
        fputc(R,f_out);
    }
    fclose(f_in);
    fclose(f_out);
    printf("Success! Please check file redSantaCopy.bmp\n");
    return 0;
}
