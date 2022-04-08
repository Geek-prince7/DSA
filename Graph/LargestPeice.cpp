#include <iostream>
#include <vector>
using namespace std;

//#include "solution.h"

int Helper(vector<vector<int>> &cake, int n,bool **visited,int i,int j)
{
    visited[i][j]=true;
    int max=0;
    if(i>0)
    {

        if(cake[i-1][j]==1 && !visited[i-1][j])
        {
            //visited[i-1][j]=true;
            int ans=Helper(cake,n,visited,i-1,j);

            	max+=ans;

        }
    }
    if(i<n-1)
    {
        if(cake[i+1][j]==1 && !visited[i+1][j])
        {
            //visited[i+1][j]=true;
            int ans=Helper(cake,n,visited,i+1,j);

                max+=ans;


        }

    }
    if(j>0)
    {
        if(cake[i][j-1]==1 && !visited[i][j-1])
        {
            //visited[i][j-1]=true;
            int ans=Helper(cake,n,visited,i,j-1);

                max+=ans;

        }
    }
    if(j<n-1)
    {
        if(cake[i][j+1]==1 && !visited[i][j+1])
        {
            //visited[i][j+1]=true;
            int ans=Helper(cake,n,visited,i,j+1);

                max+= ans;

        }
    }
    //visited[i][j]=false;
    return max+1;

}
int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[n];
        for(int j=0;j<n;j++)
        {
                visited[i][j]=false;
        }
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cake[i][j]==1 && !visited[i][j])
            {
                int ans=Helper(cake,n,visited,i,j);
                if(ans>max)
                {
                    max=ans;
                }

            }
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}
