#include<stdio.h>
#include<stdlib.h>

void add_int(void* x,void* y)
{
    *(int*)x=*(int*)x+*(int*)y;
}

int main()
{
    int i,u=5,v=7;
    void *p,*q,*r;
    int *a;
    char b[]="Hello ";

    add_int(&u,&v);
    printf("\n %d",u);

    p=(float *)malloc(3*sizeof(double));
    a=calloc(4,sizeof(int));
    q=(int *)a;
    r=(char *)b;

    for (i=0;i<6;i++){
        printf("\n %0.2f %d %c",*((float*)p+i),*((int*)q+i),*((char*)r+i));
    }

    free(p);
    free(q);

    return 0;
}
