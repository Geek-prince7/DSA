#include <iostream>
using namespace std;

int main() {
    // Write your code
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
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }


    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(edges[i][j]==1)
            {
                for(int k=j;k<n;k++)
                {
                    if(edges[j][k]==1 && k!=i)
                    {
                        if(edges[k][i]==1)
                        {
                            //cout<<i<<" "<<j<<" "<<k<<endl;
                            count++;
                        }
                    }
                }
            }
        }
    }
    cout<<count;

}
