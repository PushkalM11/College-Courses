#include <stdio.h>
#include <math.h>
#include "factorial_header.h"

int main()
{
    double x,fact,ex_taylor_series=1,ex;
    printf("Enter a Real Number: ");
    scanf("%lf",&x);
    for(int i=1;i<=20;++i)                          //For e^x
    {
        fact=factorial(i);
        ex_taylor_series+=(pow(x,i)/fact);
    }
    ex=exp(x);
    printf("\nThe value of e^%lf from taylor series is: %lf\nAnd from In Built function is: %lf\n",x,ex_taylor_series,ex);
    
    
    double y=(x-1)/(x+1);
    long double logx_taylor_series=0,logx;             //For logx
    for(int i=1;i<=20;++i)
    {
       	logx_taylor_series+=pow(y,((2*i)-1))/((2*i)-1);
    }  
    logx=log(x);
    printf("\nThe value of log(%lf) from taylor series is: %Lf\nAnd from In Built function is: %Lf\n",x,2*logx_taylor_series,logx);
    
    
    double sinx_taylor_series=0,sinx;            //For Sin(x)
    for(int i=1;i<=20;++i)
    {
        fact=factorial((2*i)-1);
        sinx_taylor_series+=pow(-1,i+1)*pow(x,(2*i)-1)/fact;
    }
    sinx=sin(x);
    printf("\nThe value of sin(%lf) from taylor series is: %lf\nAnd from In Built function is: %lf\n",x,sinx_taylor_series,sinx);
    return 0;
}


