#include <stdio.h>

void print_board(char c[4][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%c ",c[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int pos[2]={2,1},x,y;
    char board[4][4],c;
    board[0][0]='6';
    board[0][1]='A';
    board[0][2]='2';
    board[0][3]='3';
    board[1][0]='9';
    board[1][1]='7';
    board[1][2]='D';
    board[1][3]='4';
    board[2][0]='E';
    board[2][1]='0';
    board[2][2]='5';
    board[2][3]='8';
    board[3][0]='B';
    board[3][1]='1';
    board[3][2]='F';
    board[3][3]='C';
    printf("The initial configuration of the board is: \n");
    print_board(board);
    for(int i=0;i<10000;i++)
    {
        printf("\nEnter your move (For exit enter X): ");
        c=getchar();
        if(c=='N'||c=='n')
        {
            if(pos[0]==0)
                printf("Invalid Move!\n");
            else
            {
                x=pos[0];
                y=pos[1];
                board[x][y]=board[x-1][y];
                board[x-1][y]='0';
                pos[0]-=1;
                print_board(board);
            }
        }
        else if(c=='E'||c=='e')
        {
            if(pos[1]==3)
                printf("Invalid Move!\n");
            else
            {
                x=pos[0];
                y=pos[1];
                board[x][y]=board[x][y+1];
                board[x][y+1]='0';
                pos[1]+=1;
                print_board(board);
            }
        }
        else if(c=='S'||c=='s')
        {
            if(pos[0]==3)
                printf("Invalid Move!\n");
            else
            {
                x=pos[0];
                y=pos[1];
                board[x][y]=board[x+1][y];
                board[x+1][y]='0';
                pos[0]+=1;
                print_board(board);
            }
        }
        else if(c=='W'||c=='w')
        {
            if(pos[1]==0)
                printf("Invalid Move!");
            else
            {
                x=pos[0];
                y=pos[1];
                board[x][y]=board[x][y-1];
                board[x][y-1]='0';
                pos[1]-=1;
                print_board(board);
            }
        }
        else if(c=='X')
            break;
        else
            ;
    }
    return 0;
}
