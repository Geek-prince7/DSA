#include<iostream>
using namespace std;
int arrayindex(int a[],int n,int x)
{
    /*
    if(n<=0)
    {
        return (-1);
    }
    if(a[n-1]==x)
    {
        return n-1;
    }
    return arrayindex(a,n-1,x);
    */
    if(n<=0)
    {
        return -1;
    }
    if(a[0]==x)
    {
        return 0;
    }
    return 1+arrayindex(a+1,n-1,x);

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
    int index=arrayindex(a,n,x);
    cout<<"index is : "<<index;
    return 0;
}
