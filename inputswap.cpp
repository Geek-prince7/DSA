#include<iostream>
#include<string>
#include<cstring>
using namespace std;
void swapstringplaces(string input)
{
    int f=input.length();

        char k=input[input.length()-1];
        int j;
        for(j=f-1;j>=1;j--)
        {
            input[j]=input[j-1];
        }
        input[0]=k;
        cout<<input<<endl;

}
int main()
{
    string input;
    cout<<"Enter a string : ";
    cin>>input;
    swapstringplaces(input);
    return 0;
}
