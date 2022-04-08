#include<unordered_map>
#include<string>
#include <iostream>
#include <string>
using namespace std;


string uniqueChar(string str) {
	// Write your code here
    string st="";
    unordered_map<char,bool> mymap;
    for(int i=0;i<str.length();i++)
    {
        if(mymap.count(str[i]))
        {
            continue;
        }
        mymap[str[i]]=true;
        st=st+str[i];
    }
    return st;
}


int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
