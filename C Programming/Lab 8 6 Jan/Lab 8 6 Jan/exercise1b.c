#include <stdio.h>
#include "exercise1_functions.h"

int main()
{
    srecord s[1000];
    int i_max[100];
    int i_min[100];
    int max_ht=0,min_ht=3000,n1=0,n2=0;    //Obviously no one's height is more than 3000 cm and less than 0 cm.
    for(int i=0;i<1000;i++)
    {
        scanf("%s %s %d %d %d %d %d",s[i].fname,s[i].lname,&s[i].btype,&s[i].branch,&s[i].yr,&s[i].ht,&s[i].wt);
        if(s[i].ht>max_ht)
        {
            max_ht=s[i].ht;
        }
        if(s[i].ht<min_ht)
        {
            min_ht=s[i].ht;
        }
    }
    for(int i=0;i<1000;i++)
    {
        if(s[i].ht==max_ht)
        {
            i_max[n1]=i;
            n1+=1;
        }
        if(s[i].ht==min_ht)
        {
            i_min[n2]=i;
            n2+=1;
        }
    }
    printf("\nThe tallest people in the given records are:\n\n");
    for(int j=0;j<n1;j++)
    {
        int x=i_max[j];
        print_record(s[x].fname,s[x].lname,s[x].btype,s[x].branch,s[x].yr,s[x].ht,s[x].wt);
    }
    printf("\nThe shortest people in the given records are:\n\n");
    for(int k=0;k<n2;k++)
    {
        int y=i_min[k];
        print_record(s[y].fname,s[y].lname,s[y].btype,s[y].branch,s[y].yr,s[y].ht,s[y].wt);
    }
    return 0;
}
