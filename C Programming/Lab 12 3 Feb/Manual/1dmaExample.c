#include<stdio.h>
#include<stdlib.h>

struct complex_t
{
    double real;
    double img;
};

typedef struct complex_t complex;

int main()
{
    int *p,*q,i;
    complex *w;
    p=malloc(5*sizeof(int));
    q=calloc(5,sizeof(int));
    w=malloc(sizeof(complex));

    for (i=0;i<7;i++)
        printf("\n %d %d",p[i],q[i]);

    w->real=1.5;
    w->img=2.5;
    printf("\n %lf %lf",w->real,w->img);

    free(p);
    free(w);
    return 0;
}
