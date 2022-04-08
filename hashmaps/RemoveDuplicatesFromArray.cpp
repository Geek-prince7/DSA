#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int *arr,int n)
{
    unordered_map<int,bool> mymap;
    vector<int> out;
    for(int i=0;i<n;i++)
    {
        if(mymap.count(arr[i]))
        {
            continue;
        }
        else
        {
            out.push_back(arr[i]);
            mymap[arr[i]]=true;
        }
    }
    return out;
}
int main()
{
    int size;
    cin>>size;
    int *arr=new int[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    vector<int>out= removeDuplicates(arr,size);
    for(int i=0;i<out.size();i++)
    {
        cout<<out[i]<<" ";
    }

}
