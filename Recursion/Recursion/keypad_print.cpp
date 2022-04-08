#include<iostream>
using namespace std;
/*
void printkey(int num,string output)
{
    if(num<=0)
    {
        cout<<output<<endl;
        return;
    }
    string key[]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int current=num%10;
    int currentsize=key[current-1].size();
    for(int i=0;i<currentsize;i++)
    {
        printkey(num/10,key[current-1][i]+output);
    }


}
*/

void printkeypad(int num,string output)
{
    if(num<=0)
    {
        cout<<output<<endl;
        return;
    }
    string keycode[]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int current=num%10;
    int currentsize=keycode[current-1].size();
    for(int i=0;i<currentsize;i++)
    {
        printkeypad(num/10,output+keycode[current-1][i]);
    }
}
void printkey(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    int rev=0;
    while(num>0)
    {
        rev=rev*10+num%10;
        num=num/10;
    }
    printkeypad(rev,"");
}
int main()
{
    int num;
    cout<<"Enter number : ";
    cin>>num;
    string output="";
    printkey(num);
    return 0;
}
