#include<iostream>
using namespace std;
void replace_char(char str[],char c1,char c2)
{
    if(str[0]=='\0')
    {
        return;
    }
    if(str[0]==c1)
    {
        str[0]=c2;
    }
    replace_char(str+1,c1,c2);
    return;

}
int main()
{
    char str[100];
    cout<<"Enter string : ";
    cin>>str;
    cout<<endl;
    char c1,c2;
    cout<<"Enter char to be replaced : ";
    cin>>c1;
    cout<<endl;
    cout<<"Enter new char : ";
    cin>>c2;
    cout<<endl;
    replace_char(str,c1,c2);
    cout<<"Updated string : "<<str<<endl;
    return 0;


}
