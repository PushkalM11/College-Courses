#include <stdio.h>

int main()
{
    int n,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int input[n],g_test=0;
    printf("Enter the permutation(Like for 1,2,3..n enter 1 2 3....n): ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
        if(input[i]>n)
        {
            g_test=1;
        }
    }
    if(g_test==1)
    {
        printf("Please enter %d numbers from 1 to %d only!!!\n",n,n);
    }
    else
    {
        int z,a=0,test=0,tmp,y=0;
        for(i=n-1;i>0;i--)              //As the final sequence is in descending order, from backwards it should be in ascending
        {
            if(input[i-1]<input[i])     //Detecting if not ascending from backwards.
                break;
        }
        int const index=i;
        //To find the next sequence.
        if(i==(n-1))                    //If last two, swap the numbers.
        {
            int tmp=input[i];
            input[i]=input[i-1];
            input[i-1]=tmp;
        }
        else if(i==0)                   //The given sequence is descending.
            printf("The same sequence/");
        else
        {
            int x=input[index-1];
            //Searching for the next higher number of input[index-1] from i=index to n-1.
            for(z=x+1;z<=n;z++)         //Taking a higher number.
            {
                for(a=index;a<n;a++)    //Searching in the array.
                {
                    if(input[a]==z)     //If found.
                    {
                        test=1;
                        break;
                    }
                }
                if(test==1)             //Detection of finding.
                    break;
            }
            //Swapping the numbers.
            input[index-1]=z;
            input[a]=x;
            //Arranging the left out numbers in ascending order.
            tmp=n-1-index;
            if(tmp%2==0)
            {
                tmp=index+(tmp/2);
                for(i=index;i<tmp;i++)
                {
                    int tmp2=input[i];
                    input[i]=input[n-1-y];
                    input[n-1-y]=tmp2;
                    y+=1;
                }
            }
            else
            {
                tmp=index+((tmp+1)/2);
                for(i=index;i<tmp;i++)
                {
                    int tmp2=input[i];
                    input[i]=input[n-1-y];
                    input[n-1-y]=tmp2;
                    y+=1;
                }
            }
        }
        printf("The next sequence is: ");
        for(i=0;i<n;i++)
        {
            printf("%d ",input[i]);
        }
        printf("\n");
    }
    return 0;
}
