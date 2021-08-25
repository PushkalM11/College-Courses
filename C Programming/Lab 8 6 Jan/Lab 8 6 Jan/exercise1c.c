#include <stdio.h>
#include "exercise1_functions.h"

int main()
{
    srecord s[1000];
    int tmpwt[5][11][2];                    //tmpwt[no. of years][branch][max weight, min weight].
    int i_max[5][11][20], i_min[5][11][20]; //Index for max. and min. weight.
    int count[5][11][2];                    //To count number of indices stored in the corresponding i_max and i_min.
    int tmp=0;
    for( int i=1;i<5;i++)
    {
        for(int j=0;j<11;j++)
        {                           //Same logic as in exercise 1b.
            tmpwt[i][j][0]=0;       //For max weight in ith year and jth branch.
            tmpwt[i][j][1]=200;     //For min weight in ith year and jth branch.
            count[i][j][0]=0;
            count[i][j][1]=0;
        }
    }
    for( int i=0;i<1000;i++)
    {
        scanf("%s %s %d %d %d %d %d",s[i].fname,s[i].lname,&s[i].btype,&s[i].branch,&s[i].yr,&s[i].ht,&s[i].wt);
        if(s[i].wt > tmpwt[s[i].yr][s[i].branch][0])            //Updating max. weight in corresponding array.
        {
            tmpwt[s[i].yr][s[i].branch][0]=s[i].wt;
        }
        if(s[i].wt < tmpwt[s[i].yr][s[i].branch][1])            //Updating max. weight in corresponding array.
        {
            tmpwt[s[i].yr][s[i].branch][1]=s[i].wt;
        }
    }
    for(int i=0;i<1000;i++)
    {
        if(s[i].wt==tmpwt[s[i].yr][s[i].branch][0])             //To detect people having max. weight.
        {
            tmp=count[s[i].yr][s[i].branch][0];
            i_max[s[i].yr][s[i].branch][tmp]=i;                 //Saving the index for that person.
            count[s[i].yr][s[i].branch][0]+=1;                  //Updating the count.
        }
        if(s[i].wt==tmpwt[s[i].yr][s[i].branch][1])             //To detect people having min. weight.
        {
            tmp=count[s[i].yr][s[i].branch][1];
            i_min[s[i].yr][s[i].branch][tmp]=i;                 //Saving the index for that person.
            count[s[i].yr][s[i].branch][1]+=1;                  //Updating the count.
        }
    }
    for(int i=1;i<5;i++)
    {
        printf("\nThe heaviest and lightest people from year %d are:\n",i);
        for(int j=0;j<11;j++)
        {
            printf("\nFor ");
            branch_determiner(j);
            printf("The heaviest person(/s) are: \n");
            for(int t=0;t<count[i][j][0];t++)
            {
                tmp=i_max[i][j][t];
                print_record(s[tmp].fname,s[tmp].lname,s[tmp].btype,s[tmp].branch,s[tmp].yr,s[tmp].ht,s[tmp].wt);
            }
            printf("\nThe lightest person(/s) are: \n");
            for(int t=0;t<count[i][j][1];t++)
            {
                tmp=i_min[i][j][t];
                print_record(s[tmp].fname,s[tmp].lname,s[tmp].btype,s[tmp].branch,s[tmp].yr,s[tmp].ht,s[tmp].wt);
            }
        }
    }
    return 0;
}
