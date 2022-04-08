#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int>* getPathBFS(int **edges,int n,int v1,int v2)
{
    vector<int> *out=new vector<int>();
    unordered_map<int,int> mymap;
    queue<int> q1;
    bool check=false;
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    q1.push(v1);
    mymap[v1]=-1;
    visited[v1]=true;
    while(!q1.empty())
    {
        int current=q1.front();
        q1.pop();

        for(int i=0;i<n;i++)
        {
            if(edges[current][i]==1 && !visited[i])
            {
                q1.push(i);
                mymap[i]=current;
                visited[i]=true;
                if(v2==i)
                {
                    check=true;
                    break;
                }

            }
        }
        if(check)
        {
            int i=v2;
            while(mymap[i]!=-1)
            {
                out->push_back(i);
                i=mymap[i];
            }
            out->push_back(i);
            return out;
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


    vector<int>* out=getPathBFS(edges,n,v1,v2);
    if(out)
    {
        for(int i=0;i<out->size();i++)
        {
            cout<<out->at(i)<<" ";
        }
    }
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    //delete[] visited;
}
