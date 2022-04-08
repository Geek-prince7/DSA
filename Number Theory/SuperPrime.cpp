#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *prime=new int[n+1];
    for(int i=2;i<=n;i++)
    {
        prime[i]=0;
    }
    prime[0]=1;
    prime[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2*i;j<=n;j+=i)
            {
                prime[j]+=1;
            }
        }
    }
    int count=0;
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==2)
        {
            count++;
        }
    }
    cout<<count;
}
