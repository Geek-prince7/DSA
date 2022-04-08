#include<iostream>
#include<cstring>
using namespace std;
int allindex(int a[],int n,int x,int *output)
{
//just to return no of index at which x is present
    /*
    if(n<=0)
    {
        return 0;
    }
    int ans=allindex(a+1,n-1,x);
    if(a[0]==x)
    {
        return 1+ans;
    }
    return ans;
    */
    if(n<=0)
    {
        return 0;
    }
    int ans=allindex(a,n-1,x,output);
    if(a[n-1]==x)
    {
        output[ans]=n-1;
        return 1+ans;
    }
    return ans;

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
    int output[10];
    int total_rep=allindex(a,n,x,output);
    cout<<"no of times "<<x<< " occured in array is : "<<total_rep<<endl;
    for(int i=0;i<total_rep;i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;
}
