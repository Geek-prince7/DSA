#include <iostream>
#include <vector>
using namespace std;
bool cyclecheck(vector<vector<char>> &board, int n, int m,bool **visited,int i ,int j,char current)
{
    if(i>0)
    {
        if(current==board[i-1][j] && visited[i-1][j])
        {
            return true;
        }
    }
    if(i<n-1)
    {
        if(current==board[i+1][j] && visited[i+1][j])
        {
            return true;
        }
    }
    if(j>0)
    {
        if(current==board[i][j-1] && visited[i][j-1])
        {
            return true;
        }
    }
    if(j<m-1)
    {
        if(current==board[i][j+1] && visited[i][j+1])
        {
            return true;
        }
    }
    if(i>0 && j>0)
    {
        if(current==board[i-1][j-1] && visited[i-1][j-1])
        {
            return true;
        }
    }
    if(i>0 && j<m-1)
    {
        if(current==board[i-1][j+1] && visited[i-1][j+1])
        {
            return true;
        }
    }
    if(i<n-1 && j>0)
    {
        if(current==board[i+1][j-1] && visited[i+1][j-1])
        {
            return true;
        }
    }
    if(i<n-1 && j<m-1)
    {
        if(current==board[i+1][j+1] && visited[i+1][j+1])
        {
            return true;
        }
    }
    return false;
}
bool Helper(vector<vector<char>> &board, int n, int m,bool **visited,int i ,int j,int len,char current)
{
    if(len>=4 && cyclecheck(board,n,m,visited,i,j,current))
    {
        return true;
    }


    visited[i][j]=true;
    if(i>0)
    {
        if(board[i-1][j]==board[i][j] && !visited[i-1][j])
        {
            //visited[i-1][j]=true;
            bool ans=Helper(board,n,m,visited,i-1,j,len+1,current);
            if(ans)
            {
                return ans;
            }
        }
    }
    if(i<n-1)
    {
        if(board[i+1][j]==board[i][j] && !visited[i+1][j])
        {
            //visited[i+1][j]=true;
            bool ans=Helper(board,n,m,visited,i+1,j,len+1,current);
            if(ans)
            {
                return ans;
            }
        }

    }
    if(j>0)
    {
        if(board[i][j-1]==board[i][j] && !visited[i][j-1])
        {
            //visited[i][j-1]=true;
            bool ans=Helper(board,n,m,visited,i,j-1,len+1,current);
            if(ans)
            {
                return ans;
            }
        }
    }
    if(j<m-1)
    {
        if(board[i][j+1]==board[i][j] && !visited[i][j+1])
        {
            //visited[i][j+1]=true;
            bool ans=Helper(board,n,m,visited,i,j+1,len+1,current);
            if(ans)
            {
                return ans;
            }
        }
    }

    if(i>0 &&j>0)
    {
        if(board[i-1][j-1]==visited[i][j] && !visited[i-1][j-1])
        {
            //visited[i-1][j-1]=true;
            bool ans=Helper(board,n,m,visited,i-1,j-1,len+1,current);
            if(ans)
            {
                return ans;
            }
        }
    }
    if(i<n-1 &&j>0)
    {
        if(board[i+1][j-1]==board[i][j] && !visited[i+1][j-1])
        {
            //visited[i+1][j-1]=true;
            bool ans=Helper(board,n,m,visited,i+1,j-1,len+1,current);
            if(ans)
            {
                return ans;
            }
        }
    }
    if(i>0 &&j<m-1)
    {
        if(board[i-1][j+1]==board[i][j] && !visited[i-1][j+1])
        {
            //visited[i-1][j+1]=true;
            bool ans=Helper(board,n,m,visited,i-1,j+1,len+1,current);
            if(ans)
            {
                return ans;
            }
        }
    }
    if(i<n-1 &&j<m-1)
    {
        if(board[i+1][j+1]==board[i][j] && !visited[i+1][j+1])
        {
            //visited[i+1][j+1]=true;
            bool ans=Helper(board,n,m,visited,i+1,j+1,len+1,current);
            if(ans)
            {
                return ans;
            }
        }
    }
    visited[i][j]=false;
    return false;

}
bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[m];
        for(int j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char current=board[i][j];
            //visited[i][j]=true;
            bool ans=Helper(board,n,m,visited,i,j,0,current);
            if(ans)
            {
                return true;
            }
            //visited[]
        }
    }
    return false;


}





int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}
