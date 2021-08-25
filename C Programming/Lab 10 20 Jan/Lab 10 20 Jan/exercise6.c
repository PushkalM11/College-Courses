#include <stdio.h>
#define MAX_NUM 100

int board[MAX_NUM][MAX_NUM];

void reset_board(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]=2;
        }
    }
}

void place_queen(int n,int i,int j)
{
	int x,y;
	for(x=0;x<n;x++)
		board[x][j]=0;
	for(y=0;y<n;y++)
		board[i][y]=0;
	for(x=0;x<n;x++)
	{
		int y1=x+j-i;
		int y2=i+j-x;
		board[x][y1]=0;
		board[x][y2]=0;
	}
	board[i][j]=1;
}

void remove_queen(int n,int i,int j)
{
    int x,y;
    for(x=0;x<n;x++)
        board[x][j]=2;
    for(y=0;y<n;y++)
        board[i][y]=2;
    for(x=0;x<n;x++)
    {
        int y1=x+j-i;
        int y2=i+j-x;
        board[x][y1]=2;
        board[x][y2]=2;
    }
}

int get_pos(int *pos,int n,int i)
{
    int x=0;
    for(int j=0;j<n;j++)
    {
        *(pos+j)=board[i][j];
        if(*(pos+j)==2)
            x+=1;
    }
    return x;
}

void det_pos(int *pos,int n,int i,int j,int x,int tot)
{
    for(int jm=0;jm<n;jm++)
    {
        if(*(pos+jm)==2)
        {
            j=jm;
            
        }
    }
}

int main()
{
	int n,test;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	int x=0,pos[n];
	for(int z=0;z<n;z++)
	{
        x=0;
        reset_board(n);
		place_queen(n,0,z);
		test=1;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]==2)
				{
                    place_queen(n,i,j);
					x+=1;
                    test+=1;
                    break;
				}
			}
			if(x==0)
				break;
		}        
		if(test==n)
			break;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==0)
				printf("0 ");
			else
				printf("Q ");
		}
		printf("\n");
	}
	return 0;
}
