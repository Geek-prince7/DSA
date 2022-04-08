#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n+2];
    arr[0]=0;
    arr[1]=0;
    for(int i=2;i<=n+1;i++)
    {
        arr[i]=INT_MIN;
    }
    for(int i=2;i*i<=n+1;i++)
    {
        if(arr[i]==INT_MIN)
        {
            for(int j=i*i;j<=n+1;j+=i)
            {
                arr[j]=1;
            }
        }
    }
    int count=0;
    for(int i=2;i<=n+1;i++)
    {
        if(arr[i]==1)
        {
            count++;
        }
    }
    if(count==0)
    {
        cout<<1<<endl;
        cout<<n;
    }
    else
    {
        cout<<2<<endl;
        cout<<2<<endl;
        if(n-count>count)
        {
            cout<<count<<" "<<n-count;
        }
        else
        {
            cout<<n-count<<" "<<count;
        }
    }
}
