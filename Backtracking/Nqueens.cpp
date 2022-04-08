#include<bits/stdc++.h>
using namespace std;

//method 2
void print(int **board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<" ";
        }
        //cout<<endl;
    }
    cout<<endl;
}
bool isPossible(int **board,int row,int col,int n)
{
    //check vertically up
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][col]==1)
        {
            return false;
        }
    }
    int k=col-1;
    for(int i=row-1;i>=0;i--)
    {
        if(k>=0 && board[i][k]==1)
        {
            return false;
        }
        k--;
    }
    k=col+1;
    for(int i=row-1;i>=0;i--)
    {
        if(k<n && board[i][k]==1)
        {
            return false;
        }
        k++;
    }
    return true;
}
void backtrackNQueens(int **board,int n,int row)
{
    if(row>=n)
    {
        print(board,n);
        return;
    }
    //traversing over row
    for(int i=0;i<n;i++)
    {
        //if cell is in queens way.if not pace queen and call recursion
        if(isPossible(board,row,i,n))
        {
            board[row][i]=1;
            backtrackNQueens(board,n,row+1);
            board[row][i]=0;
        }
    }
}


/*
//method 1
void print(int **board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]!=1)
            {
                cout<<0<<" ";
            }
            else
            {
                cout<<board[i][j]<<" ";
            }
        }
        //cout<<endl;
    }
    cout<<endl;
}
void backtrackNQueens(int **board,int n,int row)
{
    if(row>=n)
    {
        print(board,n);
        return;
    }
    //update previous row's possible queens path
    int col;
    if(row>0)
    {
        //find the col of queens in previous row
        for(int i=0;i<n;i++)
        {
            if(board[row-1][i]==1)
            {
                col=i;
                break;
            }
        }
        //mark vertical down path
        for(int i=row;i<n;i++)
        {
            board[i][col]-=1;
        }
        //mark diagonal downward left
        int a=col-1;
        for(int i=row;i<n;i++)
        {
            if(a>=0)
            {
                board[i][a]-=1;
                a--;
            }
            else
            {
                break;
            }
        }

        // mark diagonal downward right
        a=col+1;
        for(int i=row;i<n;i++)
        {
            if(a<n)
            {
                board[i][a]-=1;
                a++;
            }
            else
            {
                break;
            }
        }
    }




    //traversing over row
    for(int i=0;i<n;i++)
    {
        //if cell is in queens way.if not pace queen and call recursion
        if(board[row][i]>=0)
        {
            board[row][i]=1;
            backtrackNQueens(board,n,row+1);
            board[row][i]=0;
        }
    }




    if(row>0)
    {

        //un mark vertical down path
        for(int i=row;i<n;i++)
        {
            board[i][col]+=1;
        }
        //un mark diagonal downward left
        int a=col-1;
        for(int i=row;i<n;i++)
        {
            if(a>=0)
            {
                board[i][a]+=1;
                a--;
            }
            else
            {
                break;
            }
        }

        // un mark diagonal downward right
        a=col+1;
        for(int i=row;i<n;i++)
        {
            if(a<n)
            {
                board[i][a]+=1;
                a++;
            }
            else
            {
                break;
            }
        }
    }
}
*/

void nQueens(int n)
{
    int **board=new int*[n];
    for(int i=0;i<n;i++)
    {
        board[i]=new int[n];

        for(int j=0;j<n;j++)
        {
            board[i][j]=0;
        }

    }
    backtrackNQueens(board,n,0);
}
int main(){
    // write your code here
    int n;
    cin>>n;
    nQueens(n);
    return 0;
}
