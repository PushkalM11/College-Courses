double factorial(int n)
{
    double factorial=1;
    for(int i=1;i<=n;++i)
    {
        factorial*=i;
    }
    return factorial;
}
