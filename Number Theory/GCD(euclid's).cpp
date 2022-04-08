//euclid's algorithm is
//if a>b
//    then
//    gcd(a,b)=gcd(b,a%b)

#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    if(b==0)
    {
        return a;
    }
    //cout<<b<<" "<<a%b<<endl;
    return gcd(b,a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}
