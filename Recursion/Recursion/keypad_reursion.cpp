/*
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different line
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include<iostream>
using namespace std;
int keypad(int num,string output[])
{
    if(num==0)
    {
        output[0]="";
        return 1;
    }
    string key[]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int index=keypad(num/10,output);
    int current=num%10;
    int sizecurrent=key[current-1].size();
    for(int i=0;i<sizecurrent-1;i++)
    {
        for(int j=((i)*index);j<((i+1)*index);j++)
        {
            output[index+j]=output[j];
        }
    }
     for(int i=0;i<sizecurrent;i++)
    {
         for(int j=((i)*index);j<((i+1)*index);j++)
         {
             output[j]=output[j]+key[current-1][i];
         }

    }
    return sizecurrent*index;

}
int main()
{
    int num;
    cout<<"Enter no :";
    cin>>num;
    string output[1000];
    int ind=keypad(num,output);
    cout<<endl;
    for(int i=0;i<ind;i++)
    {
        cout<<output[i]<<endl;
    }
    return 0;
}
