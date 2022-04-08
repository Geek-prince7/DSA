#include<iostream>
#include<queue>
using namespace std;
void ksortedArray(int arr[],int n,int k)
{
    priority_queue<int> pq;
    for(int i=0;i<k;i++)
    {
        pq.push(arr[i]);
    }
    int j=0;
    for(int i=k;i<n;i++)
    {
        arr[j]=pq.top();
        pq.pop();
        j++;
        pq.push(arr[i]);
    }
    while(!pq.empty())
    {
        arr[j]=pq.top();
        pq.pop();
        j++;
    }
}
int main()
{
    int arr[5]={10,12,15,6,9};

    int k=3;
    ksortedArray(arr,5,k);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }

}
