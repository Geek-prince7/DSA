#include<iostream>
using namespace std;
int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
int main()
{
    int n;
    cin>>n;
    int req = fibo(n);
    cout<<req;
    return 0;
}
