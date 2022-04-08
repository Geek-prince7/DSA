#include<iostream>
#include<vector>
using namespace std;
vector<int>* getPath(int **edges,int n,int v1,bool* visited,int v2)
{
    if(v1==v2)
    {
        //cout<<v1<<" found"<<endl;
        vector<int> *out=new vector<int>();
        out->push_back(v2);
        return out;
    }
    visited[v1]=true;
    //cout<<v1<<endl;

    vector<int> *ans;
    for(int i=0;i<n;i++)
    {
        if(edges[v1][i]==1 && !visited[i])
        {
            ans=getPath(edges,n,i,visited,v2);
            if(ans)
            {
                ans->push_back(v1);
                return ans;
            }
        }
    }
    return NULL;
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
    int v1,v2;
    cin>>v1>>v2;

    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    vector<int> *ans=getPath(edges,n,v1,visited,v2);
    if(ans)
    {
        for(int i=0;i<ans->size();i++)
        {
            cout<<ans->at(i)<<" ";
        }
    }
    /*
    if(visited[v2])
    {

        printpath(edge,n,v2,v1,visited);
    }
    */
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}
