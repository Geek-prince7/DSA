#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    cout<<s<<endl;
    unordered_map<string,int> freq;
    string name="";
    for(int i=0;i<s.size();i++)
    {

        if(s[i]==' ')
        {
            ++freq[name];
            cout<<name<<endl;
            name="";
            continue;
        }
        name=name+s[i];
        //cout<<name<<endl;
    }
    //for last name
    ++freq[name];
    unordered_map<string,int>:: iterator it=freq.begin();
    int count=0;
    while(it!=freq.end())
    {
        if(it->second > 1)
        {
            cout<<it->first<<" "<<it->second<<endl;
            count++;
        }
        it++;
    }
    if(count==0)
    {
        cout<<-1<<endl;
    }

    return 0;
}
