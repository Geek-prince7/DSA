#include<iostream>
#include<climits>
using namespace std;
int find_minvertex(int *distance,int n,bool * visited)
{
    int minv=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minv==-1 || distance[minv]>distance[i]))
        {
            minv=i;
        }
    }
    return minv;
}
void dijkstra(int **edges,int n)
{
    int *distance =new int[n];
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int source_vertex=find_minvertex(distance,n,visited);
        visited[source_vertex]=true;
        //find neighbours which are unvisited
        for(int j=0;j<n;j++)
        {
            if(!visited[j] && edges[source_vertex][j]!=0)
            {
                if(distance[source_vertex]+edges[source_vertex][j]<distance[j])
                {
                    distance[j]=distance[source_vertex]+edges[source_vertex][j];
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        cout<<"shortest distance from 0 to "<<i<<" is :"<<distance[i]<<endl;
    }
    delete[] distance;
    delete[] visited;
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
    dijkstra(edges,n);
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}
