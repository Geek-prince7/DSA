/*
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:
*/
#include<iostream>
using namespace std;
void removex(char input[])
{
    int size=0;
    for(int i=0;input[i]!='\0';i++)
    {
        size++;
    }
    if(size<=0)
    {
        return;
    }
    if(input[0]=='x')
    {
        int j=size;
        for(int i=0;i<j;i++)
        {
            input[i]=input[i+1];
        }
        removex(input);
    }
    removex(input+1);
    return;
}
int main()
{
    char str[100];
    cin>>str;
    removex(str);
    cout<<str;
    return 0;
}


