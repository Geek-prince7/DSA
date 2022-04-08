#include<iostream>
using namespace std;
int arraysum(int a[],int n)
{
    if(n<=0)
    {
        return 0;
    }
    return (a[n-1]+arraysum(a,n-1));

    //another approach
   /* if(n<=0)
    {
        return 0;
    }
    return a[0]+arraysum(a+1,n-1);
*/
}
int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    int a[n];
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<endl<<endl;
    int sum=arraysum(a,n);
    cout<<"sum is : "<<sum;
    return 0;
}
