#include<stdio.h>

int main()
{

    enum month{Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
    enum month m,m_new;
    int n;

    n=16;

    printf("Enter the month today.");
    scanf("%d",&m);

    m_new=(m+n)%12;

    printf("\n %d months from now is %d",n,m_new);
    return 0;
}



