#include<iostream>
using namespace std;
int main()
{
    unsigned int n;
    cin>>n;
    bool *prime=new bool[n+1];
    for(int i=0;i<=n;i++)
    {
        prime[i]=true;
    }
    prime[0]=false;
    prime[1]=false;

    int nonprime=0;
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i])
        {
            //mark the multiples as not prime or with 0
            int j=i*i;
    		while(j<=n)
    		{
        		if(prime[j])
        		{
            		nonprime++;
        		}
        		prime[j]=false;
        		j+=i;
    		}
        }
    }
    cout<<"prime numbers between 1 to "<<n<<" are: "<<n-nonprime-1;
}
