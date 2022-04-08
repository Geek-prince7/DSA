#include<iostream>
using namespace std;

int lastindex(int a[],int n,int x)
{
    if(n<=0)
    {
        return -1;
    }
    int ans=lastindex(a+1,n-1,x);
    if(ans>=0)
    {
        return 1+ans;
    }
    if(a[0]==x)
    {
        return 0;
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    int x;
    int a[n];
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl<<"Enter no to be searched : ";
    cin>>x;

    cout<<endl<<endl;
    int index=lastindex(a,n,x);
    cout<<"index is : "<<index;
    return 0;
}
