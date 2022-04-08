#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
class triplet
{
public:
    ll x;
    ll y;
    ll gcd;
};
ll gcd(ll a,ll b)
{
    if(b==0)
    {
        return a;
    }
    if(a<b)
    {
        gcd(b,a);
    }
    return gcd(b,a%b);
}
triplet extendedeuclid(ll a,ll b)
{
    if(b==0)
    {
        triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    triplet smallans=extendedeuclid(b,a%b);
    triplet ans;
    ans.gcd=smallans.gcd;
    ans.x=smallans.y;
    ans.y=smallans.x-(a/b)*smallans.y;
    return ans;
}
ll ways(ll a,ll b,ll d)
{
    ll t=extendedeuclid(b,a).x;
    t=(t%a+a)%a;
    ll y1=(d%a)*t;
    if(d<y1*b)
    {
        return 0;
    }
    ll n=((d/b)-y1)/a;
    return n+1;
}
int main(){

    // write your code here

    ll t;
    cin>>t;
    while(t--)
    {
    	ll a,b,d;
        cin>>a>>b>>d;
        ll g=gcd(a,b);
        if(d%g)
        {
            cout<<0<<endl;
            continue;
        }
        if(d==0)
        {
            cout<<1<<endl;
            continue;
        }
        a/=g;
        b/=g;
        d/=g;
        ll ans=ways(a,b,d);
		cout<<ans<<endl;

    }
    return 0;
}

