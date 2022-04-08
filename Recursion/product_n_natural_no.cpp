#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m=1000000000+7;
int prod(int n)
{
    if(n<1)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    //n=n%m;
    int ans=(int)((unsigned long long int)(prod(n-1))%m);
    return (n*ans);

}
int main(){

    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<prod(n)<<endl;;
    }
    return 0;
}
