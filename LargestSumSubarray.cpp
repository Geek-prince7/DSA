#include<iostream>
using namespace std;
int kadanes(int *arr,int n)
{
    int maxi=0;
    int maxSum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            maxi=0;
            continue;
        }
        maxi+=arr[i];
        if(maxSum<maxi)
        {
            maxSum=maxi;
        }
    }
    return maxSum;

}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<kadanes(arr,n);
    return 0;
}
