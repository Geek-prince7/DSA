/*
Return subset of an array

Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :

Line 1 : Size of array

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


You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/


#include <iostream>
using namespace std;


int subset(int input[], int n, int output[][20])
{

    // Write your code here
    if(n==0)
    {
        output[0][0]=0;
        return 1;
    }
    int ans=subset(input+1,n-1,output);
    for(int i=0;i<ans;i++)
    {
        output[ans+i][0]=1+output[i][0];
    }
    for(int i=ans;i<2*ans;i++)
    {
        for(int j=1;j<=output[i][0];j++)
        {
            if(j==1)
            {
                output[i][1]=input[0];
            }
            else
            {
                output[i][j]=output[i-ans][j-1];

            }

        }
    }
    return 2*ans;
}


int main()
{
  int input[20],length, output[3500][20];
  cout<<"Enter length of array : ";
  cin >> length;

  for(int i=0; i < length; i++)
  {
    cout<<"Enter element "<<i+1<<" : ";
    cin >> input[i];

  }
  cout<<endl<<endl;

    //output[0][1]={};

  int size = subset(input, length, output);
  cout<<"The subsets of array :"<<endl;

  for( int i = 0; i < size; i++) {
	for( int j = 1; j <= output[i][0]; j++) {
		cout << output[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
