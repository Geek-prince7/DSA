#include<iostream>
using namespace std;
int maxProduct(int *arr,int n)
{
    int max_prod=1;
    int min_prod=1;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            max_prod*=arr[i];
        }
        else if(arr[i]<0)
        {
            min_prod*=arr[i];
        }
        else
        {
            min_prod=1;
            max_prod=1;
        }
        if(max_prod>maxi)
        {
            maxi=max_prod;
        }
        if(min_prod>maxi)
        {
            maxi=min_prod;
        }
    }
    return maxi;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<maxProduct(arr,n)<<endl;
    return 0;
}
