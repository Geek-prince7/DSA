/*
Write a recursive function to convert a given string into the number it represents.
That is input will be a numeric string that contains only numbers,
you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/
#include<iostream>

using namespace std;
int helper(char input[], int size)
{
    if(size<=1)
    {
        return input[size-1]-48;
    }
    return (10*helper(input,size-1))+(input[size-1]-48);

}
int stringToNumber(char input[])
{
/*
    int size=0;
    for(int i=0;input[i]!='\0';i++)
    {
        size++;
    }
    if(size<=1)
    {
        return (input[0]-48);
    }
    input[0]=input[0]-48;
    int zeroindex=input[0];
    for(int i=1;i<size;i++)
    {
        zeroindex=zeroindex*10;
    }

    int ans=stringToNumber(input+1);
    //int aux=10*input[0];
    return zeroindex+ans;
*/
 int size=0;
    for(int i=0;input[i]!='\0';i++)
    {
        size++;
    }
    return helper(input,size);

}
int main()
{
    char a[100];
    cin>>a;
    int no=stringToNumber(a);
    cout<<no;
    return 0;
}
