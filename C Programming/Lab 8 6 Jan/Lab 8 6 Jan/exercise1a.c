#include <stdio.h>
#include "exercise1_functions.h"

int main()
{
    srecord s[1000];
    for(int i=0;i<1000;i++)
    {
        scanf("%s %s %d %d %d %d %d",s[i].fname,s[i].lname,&s[i].btype,&s[i].branch,&s[i].yr,&s[i].ht,&s[i].wt);
        print_record(s[i].fname, s[i].lname, s[i].btype, s[i].branch, s[i].yr, s[i].ht, s[i].wt);
    }
    return 0;
}
