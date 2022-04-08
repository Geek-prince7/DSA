/*
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/
#include<iostream>
using namespace std;
void pairStar(char input[])
{
    int size=0;
    for(int i=0;input[i]!='\0';i++)
    {
        size++;
    }
    if(size<=1)
    {
        return;
    }
    if(input[0]==input[1])
    {
        for(int i=size;i>=0;i--)        ///i>=0 or 1 because in both case the char repeat itself
        {
            input[i+1]=input[i];
        }
        input[1]='*';
    }
    pairStar(input+1);
    return;

}
int main()
{
     char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
