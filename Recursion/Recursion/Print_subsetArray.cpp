/*
Print Subsets of Array
Send Feedback
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12
20
20 12
15
15 12
15 20
15 20 12
*/
#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[],int size,int output[],int si=0)
{
	// Write your code here
	if(size<=0)
    {
        for(int i=0;i<si;i++)
        {
          cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printSubsetsOfArray(input+1,size-1,output,si);
    output[si]=input[0];
    printSubsetsOfArray(input+1,size-1,output,si+1);


    return;
}


int main()
{
  int input[1000],length;
  cout<<"Enter the length of array : ";
  cin >> length;
  input[length]={};

  for(int i=0; i < length; i++)
  {
      cout<<"Enter element "<<i+1<<" : ";
  	  cin >> input[i];
  }
  //int x=input[0];
  int output[100];
  //output[0]={};
  printSubsetsOfArray(input, length,output);
  return 0;
}
