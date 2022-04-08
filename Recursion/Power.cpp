






#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll M=1000000000+7;
int power(int n,int m)
{
    if(m<=0)
    {
        return 1;
    }
    if(m==1)
    {
        return n;
    }
    return n*power(n,m-1);
}
int main(){

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cout<<power(n,m)<<endl;
    }
    return 0;
}


