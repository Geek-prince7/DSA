#include<iostream>
using namespace std;
void print(bool **visited,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visited[i][j])
            {
                cout<<1<<" ";
            }
            else
            {
                cout<<0<<" ";
            }
        }
    }
    cout<<endl;
}
void ratInMaze(int **maze,bool **visited,int n,int i,int j)
{
    if(i==n-1 && j==n-1 && !visited[n-1][n-1])
    {
        visited[n-1][n-1]=true;
        print(visited,n);
        visited[n-1][n-1]=false;
        return;
    }
    if(maze[i][j]==1 && !visited[i][j])
    {
        visited[i][j]=true;
        //explore all 4 directions
        if(j>0)
        {
            ratInMaze(maze,visited,n,i,j-1);
        }
        if(j<n-1)
        {
            ratInMaze(maze,visited,n,i,j+1);
        }
        if(i>0)
        {
            ratInMaze(maze,visited,n,i-1,j);
        }
        if(i<n-1)
        {
            ratInMaze(maze,visited,n,i+1,j);
        }
        visited[i][j]=false;



    }
    return;

}
int main()
{
    int n;
    cin>>n;
    int **maze=new int*[n];
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        maze[i]=new int[n];
        visited[i]=new bool[n];
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
            visited[i][j]=false;
        }
    }

    ratInMaze(maze,visited,n,0,0);
}
