
#include<bits/stdc++.h>
using namespace std;
class edge{
public:
    int source;
    int destination;
    int weight;
    edge()
    {
        source=-1;
        destination=-1;
        weight=0;
    }
};

bool compareWeight(edge i1, edge i2)
{
    return (i1.weight < i2.weight);
}



int main()
{
    int n,e;  //n is no of vertex and e is edges
    cin>>n>>e;
    edge input[e];
    edge output[n-1];
    //take the input
    for(int i=0;i<e;i++)
    {
        cin>>input[i].source>>input[i].destination>>input[i].weight;
    }
    int parent[n];
    int count=0;
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    //sort the iput array by weight
    sort(input,input+e ,compareWeight);


    int k=0;
    cout<<"input in sorted"<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<input[i].source<<" "<<input[i].destination<<" "<<input[i].weight<<endl;
    }

    while(count<n-1)
    {
        int v1,v2,weight;
        v1=input[k].source;
        v2=input[k].destination;
        weight=input[k].weight;
        k++;
        int a,b;
        a=v1;
        b=v2;

        while(parent[a]!=a)
        {
            a=parent[a];
        }
        while(parent[b]!=b)
        {
            b=parent[b];
        }
        cout<<a<<" "<<b<<endl;

        if(a==b)
        {
            continue;
        }
        else
        {
            output[count].source=v1;
            output[count].destination=v2;
            output[count].weight=weight;
            count++;
            parent[b]=a;
        }
    }
    cout<<"output array"<<endl;
    for(int i=0;i<n-1;i++)
    {
        cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
    }




}



