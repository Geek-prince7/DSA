#include <iostream>
#include<string.h>
//#include <sstream>
//#include "solution.h"
using namespace std;
/*
int helperbro(char c)
{
    int m=c-'0';
    return m;
}

char helperbhai(int m)
{
    char c='a'+m-1;
    return c;
}


int getCodes(string input, string output[10000])
{

    int size=input.length();

    if(size==0)
    return 1;

    if(size==1)
    {
        int n1=helperbro(input[0]);
        char c1=helperbhai(n1);
        output[0]=output[0]+c1;
        return 1;
    }

    string result1[10000],result2[10000];

    int n3=helperbro(input[0]);
    char c3=helperbhai(n3);
    int size1=getCodes(input.substr(1),result1);

    int size2=0;
    int n2,x;
    if(size>1)
    {

        n2=helperbro(input[1]);
        x=10*n3+n2;
        if(x>=10 && x<27)
        {
            size2=getCodes(input.substr(2),result2);
        }
    }

    char c2=helperbhai(x);

    for (int i=0;i<size1;i++)
    {
        output[i]=c3+result1[i];
    }

    for(int i=0;i<size2;i++)
    {
        output[i+size1]=c2+result2[i];
    }

    return size1+size2;
}
*/




/*
int getCodes(string input, string output[10000]) {

     if(input.empty())
    {
        output[0]="";
        return 1;
    }
    string no[]={"","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    int ans1=getCodes(input.substr(1),output);
    string check=""+input[0]+input[1];
    stringstream conv(check);
    int x=0;
    conv>>x;
    int ans2=0;
    if(x>=10 && x<=26)
    {
        ans2=getCodes(input.substr(2),output);
    }
    for(int i=0;i<ans1;i++)
    {
       output[i]=no[input[0]]+output[i];
    }
    for(int i=0;i<ans2;i++)
    {
        output[ans1+i]=""+no[x]+output[i];
    }
    return ans1+ans2;


}
*/
 int getCodes(string input, string output[])
 {
     if(input[0] == '\0')
 {
     output[0] = ""; return 1;
 }
  int first = input[0] - 48;
  char firstChar = first + 'a' - 1;
  char secondChar = '\0';
  string smallOutput1[500];
  string smallOutput2[500];
  int size1 = getCodes(input.substr(1), smallOutput1);
  int size2 = 0;
  if(input[1] != '\0')
 {
     int second = first * 10 + input[1] - 48;
  if(second >= 10 && second <= 26)
 {
     secondChar = second + 'a' - 1;
  size2 = getCodes(input.substr(2), smallOutput2);
 }
 }
 int k = 0;
  for(int i = 0; i < size1; i++)
 {
     output[k] = firstChar + smallOutput1[i];
  k++;
 }
  for(int i = 0; i < size2; i++)
 {
     output[k] = secondChar + smallOutput2[i];
  k++;
 }
 return k;
 }

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
