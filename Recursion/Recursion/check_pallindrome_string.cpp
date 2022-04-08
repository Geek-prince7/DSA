#include<iostream>
#include<cstring>
using namespace std;
bool checkPallindrome(char str[])
{
    int size=0;
    for(int i=0;str[i]!='\0';i++)
    {
        size++;
    }
    int i=0;
    int j=size-1;
    if(i>j)
    {
        return true;
    }
    if(str[i]!=str[j])
    {
       return false;
    }
    str[j]='\0';
    return checkPallindrome(str+1);

}
int main()
{
    int i;
    cout<<"Enter index : ";
    cin>>i;
    char input[i];


    cin>>input;

    cout<<endl;
    if(checkPallindrome(input))
    {
        cout<<"True"<<endl;
    }
    else{
        cout<<"False";
    }
    return 0;
}
