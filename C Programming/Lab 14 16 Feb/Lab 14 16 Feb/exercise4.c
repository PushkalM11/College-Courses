#include <stdio.h>
#include <stdlib.h>

double find_smallest(double *in,int *n)
{
    double tmp=*in;
    int index=0;
    for(int i=1;i<*n;i++)
    {
        if(*(in+i)<tmp)
        {
            tmp=*(in+i);
            index=i;
        }
    }
    *n=index;
    return tmp;
}

void update_arr(double *in,double val,int index,int n)
{
    n-=1;
    for(int i=index;i<n;i++)
    {
        *(in+i)=*(in+i+1);
    }
}

void selection_sort(double *in,int n,double *out)
{
    double tmp;
    int index;
    for(int i=0;i<n;i++)
    {
        index=n-i;
        tmp=find_smallest(in,&index);
        *(out+i)=tmp;
        update_arr(in,tmp,index,n);
    }
}

int main()
{
    printf("To sort the array in ascending order using selection sort method-\n");
    int n;
    printf("Enter the length of the array: ");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Enter a valid number!\n");
        return 1;
    }
    double *in=(double *)malloc(n*sizeof(double));
    double *out=(double *)malloc(n*sizeof(double));
    for(int i=0;i<n;i++)
    {
        printf("Enter the %dth element: ",i+1);
        scanf("%lf",in+i);
    }
    selection_sort(in,n,out);
    printf("The sorted array is: ");
    for(int i=0;i<n;i++)
    {
        printf("%.2lf ",*(out+i));
    }
    printf("\n");
    free(in);
    free(out);
    return 0;
}
