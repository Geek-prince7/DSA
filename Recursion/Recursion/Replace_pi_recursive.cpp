/*Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
*/



#include<iostream>
using namespace std;
void replacepi(char str[])
{
    int size=0;
    for(int i=0;str[i]!='\0';i++)
    {
        size++;
    }
    int j=size;
    if(size<=1)
    {
        return;
    }


    if(str[0]=='p' && str[1]=='i')
    {

        for(int i=j;i>=0;i--)
        {
            str[i+2]=str[i];
        }
        str[0]='3';
        str[1]='.';
        str[2]='1';
        str[3]='4';


    }
    replacepi(str+1);
    return;
}

int main()
{
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    char a[n];
    cin>>a;
    replacepi(a);
    cout<<a;
    return 0;
}
