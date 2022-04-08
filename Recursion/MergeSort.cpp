#include<bits/stdc++.h>
using namespace std;
void mergetwoSortedarray(int* arr,int si,int ei)
{
    int mid=(si+ei)/2;
    int *arr2=new int[ei-si+1];
    int k=0;
    int i=si,j=mid+1;
    while(i<=mid && j<=ei)
    {
        if(arr[i]>=arr[j])
        {
            arr2[k]=arr[j];
            j++;
            k++;
        }
        else if(arr[i]<arr[j])
        {
            arr2[k]=arr[i];
            i++;
            k++;
        }
    }
    while(i<=mid)
    {
        arr2[k]=arr[i];
        i++;
        k++;
    }
    while(j<=ei)
    {
        arr2[k]=arr[j];
        j++;
        k++;
    }
    k=0;
    for(int a=si;a<=ei;a++)
    {
        arr[a]=arr2[k];
        k++;
    }
}
void mergesort(int *arr,int si,int ei)
{
    if(si>=ei)
    {
        return;
    }
    int mid=(si+ei)/2;
    mergesort(arr,si,mid);
    mergesort(arr,mid+1,ei);
    mergetwoSortedarray(arr,si,ei);
    return;
}
int main(){

    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        mergesort(arr,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        delete[] arr;

    }
    return 0;

}
