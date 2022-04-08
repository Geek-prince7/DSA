#include<bits/stdc++.h>
using namespace std;
int main(){

    // write your code here
    int n;
    cin>>n;
    int notprime=0;
    int *prime=new int[n+1];
    prime[0]=0;
    prime[1]=0;
    for(int i=2;i<=n;i++)
    {
        prime[i]=1;
    }
    for(int i=1;i*i<=n;i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(prime[j]==1)
                {
                    notprime++;
                }
                prime[j]=0;
            }
        }
    }
    int sp=0;
    int primeCount=n-notprime-1;
   // cout<<primeCount<<endl;
    int p1=2;
    while(--primeCount)
    {
        int p2=p1+1;
        while(prime[p2]!=1)
        {
            p2++;
        }
        if(p1+p2+1<=n && prime[p1+p2+1]==1)
        {
            sp++;
        }
        p1=p2;
    }
    cout<<sp;
    return 0;
}
