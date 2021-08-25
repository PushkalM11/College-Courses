#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void* my_pow(void *x,void *y)                               //Creating my own power function since the inbuilt one requires double arguments.
{
    *(double *)x=pow(*(double *)x,*(double *)y);
    return x;
}

void* str_cat(void *dest,void *src)
{
    int a=(int)strlen((char*)dest);
    int b=(int)strlen((char*)src);
    int i,j=0,k=a+b+1;
    for(i=a;i<k;i++)
    {
        char *d=(char*)dest,*s=(char*)src;
        d[i]=s[j];
        j+=1;
    }
    return (void *)dest;
}

void* swapFirstInversion(void *arr,void *n)
{
    int n1=*(int *)n-1;
    for(int i=0;i<n1;i++)
    {
        if(((double *)arr)[i]>((double *)arr)[i+1])                 //If arr[i]>arr[i+1]
        {
            double tmp=((double*)arr)[i];                           //Exchanging values of arr[i] and arr[i+1].
            ((double*)arr)[i]=((double*)arr)[i+1];
            ((double*)arr)[i+1]=tmp;
            break;
        }
    }
    return (void *)arr;
}

void iterateFunction(void* (*f)(void *,void *),int d,void *x,void *y)
{
    for(int i=0;i<d;i++)
    {
        x=(*f)(x,y);                                                //Output stored in x.
    }
}

int main()
{
    char sp;
    printf("Enter the question subpart(a or b): ");
    scanf("%c",&sp);
    if(sp=='a')
    {
        double x,y,d;
        printf("Testing the function on pow(x,y):\nEnter the value of x: ");
        scanf("%lf",&x);
        printf("Enter the value of y: ");
        scanf("%lf",&y);
        printf("Enter the value of d: ");
        scanf("%lf",&d);
        iterateFunction(my_pow,d,(void*)&x,(void*)&y);
        printf("The output is: %.2lf\n",x);
        char b[]={'H','O','O'};                                     //The given string to test on was YA and HOO.
        char a[30];
        a[0]='Y';
        a[1]='A';
        printf("Testing the function strcat: \n");
        iterateFunction(str_cat,3,(void*)a,(void*)b);
        printf("%s\n",a);
    }
    else if(sp=='b')
    {
        int arr_size,n,n1;
        printf("Enter the number of elements in the array: ");
        scanf("%d",&arr_size);
        void* arr = (double*)malloc(arr_size*sizeof(double));       //Allotting memory to array.
        for(int i=0;i<arr_size;i++)
        {
            printf("Enter element %d: ",i+1);
            scanf("%lf",&((double *)arr)[i]);                       //Storing the data.
        }
        printf("Enter the value of n: ");
        scanf("%d",&n);
        if(n>arr_size)
        {
            printf("Enter a valid n!\n");
            return 0;
        }
        n1=n+1;
        swapFirstInversion(&arr[0],(void *)&n1);                    
        for(int i=0;i<arr_size;i++)
        {
            printf("%.2lf ",((double *)arr)[i]);
        }
        printf("\n");
        iterateFunction(swapFirstInversion,((arr_size*(arr_size-1))/2),arr,(void*)&arr_size);
        for(int i=0;i<arr_size;i++)
        {
            printf("%.2lf ",((double *)arr)[i]);
        }
        printf("\n");
        free(arr);
    }
    else
        printf("Enter a valid subpart(a or b)!\n");
    return 0;
}
