#include<iostream>
#include"ourmap.h"
using namespace std;
int main()
{
    ourmap<int> map;
    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key,value);
        cout<<map.getLoadFactor()<<endl;
    }
    cout<<"size is : "<<map.size()<<endl;
    cout<<"removed :"<<"abc2 : "<<map.remove("abc2")<<endl;
    cout<<"removed :"<<"abc8 : "<<map.remove("abc8")<<endl;
    //map.remove("abc8");


    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<<" : "<<map.getValue(key)<<endl;
    }
    cout<<"size is : "<<map.size()<<endl;
}
