#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double *v;
    unsigned int d;
} vt;

typedef struct
{
    void *v;
    unsigned int d;
} vt1;

void initializeVector(vt *vect,unsigned int d,double a)
{
    vect->v=(double *)malloc(d*sizeof(double));                  //Alloting space in the heap.
    for(unsigned int i=0;i<d;i++)
    {
        *(vect->v+i)=a;                                          //As directed in the question, all elements equal to a.
    }
}

void memoryAssign(vt1 *vect1,unsigned int d, int i)
{
    if(i==0)
    {
        vect1->v=(char *)malloc(d*sizeof(char));                //Assigning char type to v.
    }
    else if(i==1)
    {
        vect1->v=(int *)malloc(d*sizeof(int));                  //Assigning int type to v.
    }
    else if(i==2)
    {
        vect1->v=(float *)malloc(d*sizeof(float));              //Assigning float type to v.
    }
    else
    {
        vect1->v=(double *)malloc(d*sizeof(double));            //Assigning double type to v.
    }
}

int main()
{
    char sp;
    printf("Enter the question subpart(a or b or c): ");
    scanf("%c",&sp);
    if(sp=='a')
    {
        vt v1;
        double s=0;
        printf("Enter the dimensions of the vector: ");
        scanf("%u",&v1.d);
        v1.v=(double *)malloc(v1.d*sizeof(double));
        for(unsigned int i=0;i<v1.d;i++)
        {
            printf("Enter coordinate %u: ",i+1);
            scanf("%lf",(v1.v+i));
        }
        for(unsigned int i=0;i<v1.d;i++)                    //Just to confirm that the space has been allotted.
        {
            s+=*(v1.v+i);
        }
        printf("The sum of the coordinates are: %.2lf\n",s);
        free(v1.v);
    }
    else if(sp=='b')
    {
        vt v1;
        printf("Enter the dimensions of the vector: ");
        scanf("%u",&v1.d);
        double a;
        printf("Enter the value of a: ");
        scanf("%lf",&a);
        initializeVector(&v1,v1.d,a);
        printf("The values stored in the vecto are:\n");        //Just to confirm that the vector has been allotted memory successfully and the values are equal to a.
        for(unsigned int i=0;i<v1.d;i++)
        {
            printf("%.2lf ",*(v1.v+i));
        }
        printf("\n");
        free(v1.v);
    }
    else if(sp=='c')
    {
        vt1 vect1;
        printf("Enter the dimensions of the vector: ");
        scanf("%u",&vect1.d);
        enum BasicDataType{Char,Int,Float,Double};
        enum BasicDataType w;
        printf("Enter the BasicDataType(0-> Char, 1-> Int, 2-> Float, 3-> Double): ");
        scanf("%d",&w);
        if(w>3||w<0)
        {
            printf("Enter a valid BasicDataType!\n");
            return 0;
        }
        memoryAssign(&vect1, vect1.d, w);
        if(w==0)                                                                      //Confirming that the data type has been alotted.
            printf("Char data type was assigned to the vector.\n");
        else if(w==1)
            printf("Int data type was assigned to the vector.\n");
        else if(w==2)
            printf("Float data type was assigned to the vector.\n");
        else
            printf("Double data type was assigned to the vector.\n");
        free(vect1.v);
    }
    else
    {
        printf("Enter a valid subpart(a or b or c)");
    }
    return EXIT_SUCCESS;
}
