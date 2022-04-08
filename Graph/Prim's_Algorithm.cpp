#include<iostream>
#include<climits>
using namespace std;
int findMinVertex(int *weight,bool *visited,int n)
{
    int minv=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] &&(minv==-1 || weight[i]<weight[minv]))
        {
            minv=i;
        }
    }
    return minv;
}
void prims(int **edges,int n)
{
    bool *visited=new bool[n];
    int *weight=new int[n];
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        weight[i]=INT_MAX;
    }

    int i=0;
    weight[0]=0;
    parent[0]=-1;
    while(i<n-1)
    {
        int source =findMinVertex(weight,visited,n);
        //parent[i]=-1;
        //weight[0]=0;
        visited[source]=true;
        for(int j=0;j<n;j++)
        {
            if(edges[source][j]!=0 && !visited[j])
            {
                if(weight[j]>edges[source][j])
                {
                    weight[j]=edges[source][j];
                    parent[j]=source;
                }
            }
        }
        i++;
    }
    cout<<endl;
    for(int i=1;i<n;i++)
    {
        cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
    }
    delete[] visited;
    delete[] weight;
    delete[] parent;
}
int main()
{
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
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
        int v1,v2,weight;
        cin>>v1>>v2>>weight;
        edges[v1][v2]=weight;
        edges[v2][v1]=weight;
    }
    prims(edges,n);
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}
