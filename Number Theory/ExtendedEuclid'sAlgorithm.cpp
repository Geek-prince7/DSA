#include<iostream>
using namespace std;
class triplet
{
public:
    int x;
    int y;
    int gcd;
};

triplet extendedEuclid(int a,int b)
{
    //base case
    if(b==0)
    {
        triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }

    triplet smallans=extendedEuclid(b,a%b);
    triplet ans;
    ans.gcd=smallans.gcd;
    ans.x=smallans.y;
    ans.y=smallans.x-(a/b)*smallans.y;
    return ans;
}
int main()
{
    int a,b;
    cin>>a>>b;
    triplet ans=extendedEuclid(a,b);
    cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd<<endl;
}
