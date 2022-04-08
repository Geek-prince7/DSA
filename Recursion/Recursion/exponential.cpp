#include<iostream>
using namespace std;
long power(int x,int n)
{
    if(n==0)
    {
        return x;
    }
    power(x*x,n/2);
}

int main()
{
    int x;
    cin>>x;
    int n;
    cin>>n;
    long pow=power(x,n);
    return 0;
}
