#include<iostream>
#include<string>
using namespace std;
bool isPalin(string s){
    int j=s.size()-1;
    int i=0;
    while(i<j)
    {
        if(s[i]!=s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;

}

/*
string longestPalindrome(string s)
{
    if(s.size()==1)
    {
        return s;
    }
    //cout<<s<<endl;

    if(isPalin(s))
    {
        return s;
    }

    string ans1=longestPalindrome(s.substr(1));
    string ans2=longestPalindrome(s.substr(0,s.size()-1));

    if(ans1.size()>ans2.size())
    {
        return ans1;
    }

    return ans2;
}
*/
int main()
{
    string s;
    cin>>s;
    cout<<" longest palindromic string is: "<<longestPalindrome(s);

}
