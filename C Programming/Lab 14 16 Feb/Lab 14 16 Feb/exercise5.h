long double my_sum(long double a,long double b)
{
    long double s;
    s=a+b;
    return s;
}

long double my_subtraction(long double a,long double b)
{
    long double s;
    s=a-b;
    return s;
}

long double my_product(long double a,long double b)
{
    long double s;
    s=a*b;
    return s;
}

void my_division(long double a,long double b)
{
    if(b==0)
    {
        printf("%Lf cannot be divided by %Lf\n",a,b);
    }
    else
    {
        printf("Their division is: %Lf\n",a/b);
    }
}
