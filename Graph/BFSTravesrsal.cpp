#include<iostream>
#include<queue>
using namespace std;
void print(int** edges,int n,int sv)
{
    queue<int> q1;
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    q1.push(sv);
    visited[sv]=true;
    while(!q1.empty())
    {
        int top=q1.front();
        q1.pop();
        cout<<top<<" ";
        //visited[top]=true;
        for(int i=0;i<n;i++)
        {
            if(edges[top][i]==1)
            {
                if(visited[i])
                {
                    continue;
                }
                q1.push(i);
                visited[i]=true;
            }
        }
    }
    delete[] visited;
}
int main()
{
    int n,e;//no of vertex and edges
    cin>>n>>e;
    int ** edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;

        }
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }


    print(edges,n,0);
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
//    delete[] visited;
}
