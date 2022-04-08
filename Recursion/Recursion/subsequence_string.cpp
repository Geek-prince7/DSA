#include<iostream>
#include<math.h>
using namespace std;
int subsequence(string input,string output[])
{
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    string smallstr=input.substr(1);
    int ind=subsequence(smallstr,output);
    int k=0;
    int i;
    for(i=ind;i<2*ind;i++)                     //for(i=0;i<ind;i++)
    {
        output[i]=input[0]+output[k];          //output[i+ind]=input[0]+output[i];
        k++;
    }
    return 2*ind;

}

int main()
{
    string input;
    cout<<"Enter a string : ";
    cin>>input;
    cout<<endl;
    int index=pow(2,input.size());
    string* output=new string[index];
    int sub=subsequence(input,output);
    cout<<"subsequences are :"<<endl;
    for(int i=0;i<sub;i++)
    {
        cout<<output[i]<<"  ";
    }
    return 0;
}
