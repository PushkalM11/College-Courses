#include <stdio.h>
#include <math.h>

struct point
{
    double x;
    double y;
};

typedef struct point pt_t;

void distance(void *result,const void *in)
{
    double x=((pt_t *)in)->x;                           //Storing the x coordinate
    double y=((pt_t *)in)->y;                           //Storing the y coordinate
    *(double *)result = pow((pow(x,2)+pow(y,2)),0.5);   //Computing distance and storing in result
}

void map(void* output_arr, void* input_arr,size_t arr_size,size_t elem_size,void (*fun)(void*, const void*))
{
    for(int i=0;i<arr_size;i++)
    {
        //Advancing the input array by 2*sizeof(double) since the struct containes two double variables
        void *p_in=(void*)(((char *)input_arr)+(i*2*elem_size));
        //Advancing the output array by sizeof(double)
        void *p_out=(void*)(((char *)output_arr)+(i*elem_size));
        fun(p_out,p_in);
    }
}

int main()
{
    char q;
    printf("Please enter subquestion(a or b): ");
    scanf("%c",&q);
    if(q=='a'||q=='A')
    {
        pt_t p;
        printf("Enter the x-coordinate of the point: ");
        scanf("%lf",&p.x);
        printf("Enter the y-coordinate of the point: ");
        scanf("%lf",&p.y);
        double result;
        distance(&result,&p);
        printf("The distance between the origin and (%.4lf,%.4lf) is: %.4lf\n",p.x,p.y,result);
    }
    else if(q=='b'||q=='B')
    {
        int n;
        printf("Enter the number of points: ");
        scanf("%d",&n);
        pt_t p[n];
        for(int i=0;i<n;i++)
        {
            printf("\n");
            printf("Enter the x-coordinate of point %d: ",i+1);
            scanf("%lf",&p[i].x);
            printf("Enter the y-coordinate of point %d: ",i+1);
            scanf("%lf",&p[i].y);
            printf("\n");
        }
        double dist[n];
        for(int i=0;i<n;i++)
        {
            map(dist,p,n,sizeof(double),distance);
            printf("The distance between origin and (%.4lf,%.4lf) is: %.4lf\n",p[i].x,p[i].y,dist[i]);
        }
    }
    else
    {
        printf("Please enter a valid subquestion!\n");
    }
    return 0;
}
