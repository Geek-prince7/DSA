#include<iostream>
#include<map>
using namespace std;
void printCommon(int *list1,int *list2,int *list3,int a,int b,int c)
{
    map<int,int> frequency;

    for(int i=0;i<a;i++)
    {
        ++frequency[list1[i]];
        if(frequency.count(list1[i])>1)
        {
            cout<<list1[i]<<" ";
        }
    }
    for(int i=0;i<b;i++)
    {
        ++frequency[list2[i]];
        if(frequency.count(list2[i])>1)
        {
            cout<<list2[i]<<" ";
        }
    }
    for(int i=0;i<c;i++)
    {
        ++frequency[list3[i]];
        if(frequency.count(list3[i])>1)
        {
            cout<<list3[i]<<" ";
        }
    }
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int list1[a],list2[b],list3[c];
    for(int i=0;i<a;i++)
    {
        cin>>list1[i];
    }
    for(int i=0;i<b;i++)
    {
        cin>>list2[i];
    }
    for(int i=0;i<c;i++)
    {
        cin>>list3[i];
    }
    printCommon(list1,list2,list3,a,b,c);
}
