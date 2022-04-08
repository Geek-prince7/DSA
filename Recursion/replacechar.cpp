#include<bits/stdc++.h>
using namespace std;
void replacechar(string s,char c1,char c2)
{
    if(s.size()==0)
    {
        return;
    }
    if(s[0]==c1)
    {
        s[0]=c2;
    }
    replacechar(s.substr(1),c1,c2);
    return;
}
int main(){

    // write your code here
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        char c1,c2;
        cin>>c1>>c2;
        replacechar(s,c1,c2);
        cout<<s<<endl;
    }
    return 0;
}
