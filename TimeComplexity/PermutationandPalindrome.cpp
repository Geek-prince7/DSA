#include<bits/stdc++.h>
using namespace std;
void PemutAndPalin(string s)
{
    unordered_map<char,vector<int>> mymap;
    for(int i=0;i<s.size();i++)
    {
        mymap[s[i]].push_back(i);

    }
    //checking if more than one element have odd frequency;
    int odd=0;
    int start=0;
    int end=s.size()-1;
    int arr[s.size()];
    for(int i=0;i<26;i++)
    {
        char c=(char)(i+97);
        if((mymap[c].size())%2 !=0)
        {
            odd++;
        }
        if(odd>1)
        {
            cout<<-1<<endl;
            break;
        }
        for(int j=0;j<mymap[c].size();j+=2)
        {

            if(j+1==mymap[c].size())
            {
                arr[s.size()/2]=mymap[c][j]+1;
                continue;
            }
            arr[start]=mymap[c][j]+1;;
            arr[end]=mymap[c][j+1]+1;;
            start++;
            end--;
        }

    }
    for(int i=0;i<s.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return;



}
int main()
{
    string s;
    cin>>s;
    PemutAndPalin(s);
    return 0;

}
