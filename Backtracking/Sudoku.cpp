#include<iostream>
using namespace std;
#define n 9
bool find_empty_position(int **grid,int &row,int &col)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==0)
            {
                row=i;
                col=j;
                //cout<<"found at "<<row<<" "<<col<<endl;
                return true;
            }
        }
    }
    return false;
}
bool isSafe(int **grid,int row ,int col,int number)
{
    //search in row and column
    for(int i=0;i<n;i++)
    {
        if(grid[row][i]==number)
        {
            return false;
        }
        if(grid[i][col]==number)
        {
            return false;
        }
    }
    // search in smaller square
    int sr,sc;
    //sr=row-row%3 and sc=col-col%3;
    if(row>5)
    {
        sr=6;
    }
    else if(row>2)
    {
        sr=3;
    }
    else
    {
        sr=0;
    }
    if(col>5)
    {
        sc=6;
    }
    else if(col>2)
    {
        sc=3;
    }
    else{
        sc=0;
    }
    for(int i=sr;i<sr+3;i++)
    {
        for(int j=sc;j<sc+3;j++)
        {
            if(grid[i][j]==number)
            {
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int **grid)
{
    int row,col;
    if(!find_empty_position(grid,row,col))
    {
        return true;
    }
    for(int i=1;i<=n;i++)
    {
        if(isSafe(grid,row,col,i))
        {
            grid[row][col]=i;
            if(solveSudoku(grid))
            {
                return true;
            }
            grid[row][col]=0;
            //continue;

        }
    }
    return false;
}
int main()
{
    int **grid=new int *[n];
    for(int i=0;i<n;i++)
    {
        grid[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    solveSudoku(grid);
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<grid[i][j]<<" ";

        }
        cout<<endl;
    }


    return 0;

}
