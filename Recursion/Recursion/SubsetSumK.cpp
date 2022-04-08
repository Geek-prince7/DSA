/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

#include <iostream>
using namespace std;
/*
int subset(int input[], int n, int output[][50])
{
    // Write your code here
    if(n<=0)
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
                output[i][j]=input[0];
            }
            else
            {
                output[i][j]=output[i-ans][j-1];
            }
        }

    }
     return 2*ans;


}
int subsetk(int output[][50],int k,int index)
{
    int help[30],s=0;
    for(int i=0;i<index;i++)
    {
        int sum=0;
        for(int j=1;j<output[i][0];j++)
        {
            sum+=output[i][j];
        }
        if(sum==k)
        {
           help[s]=i;
           s++;
        }
    }

    int out[s][50];
    int a=0;
    for(int i=0;i<index;i++)
    {
        if(i==help[a])
        {
            for(int j=0;j<output[i][0];j++)
            {
                out[a][j]=output[i][j];


            }
            a++;
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<out[i][0];j++)
        {
            output[i][j]=out[i][j];
        }
    }
    return a;
}
int subsetk(int input[],int n,int output[][50],int k)
{
    if(n<=0)
    {
        if(k==0)
        {
          output[0][0]=0;
          return 1;
        }

        return 0;
    }
    int s1=subsetk(input+1,n-1,output,k-input[0]);

    int s2=subsetk(input+1,n-1,output,k);
    for(int i=0;i<s1;i++)
    {
        output[i][0];
    }

}
*/
int subsetSumToK(int input[], int n, int output[][50], int k)
{
    // Write your code here
    if(n==0)
    {
        if(k==0)
        {
            output[0][0]=0;
            return 1;
        }
        else{
            return 0;
        }

    }
    int output1[1000][50],output2[1000][50];
    int s1=subsetSumToK(input+1,n-1,output1,k-input[0]);
    int s2=subsetSumToK(input+1,n-1,output2,k);
    for(int i=0;i<s1;i++)
    {
        for(int j=output1[i][0];j>=1;j--)
        {
            output1[i][j+1]=output1[i][j];
        }
        output1[i][1]=input[0];
        output1[i][0]++;
    }
    for(int i=0;i<s1;i++)
    {
        for(int j=0;j<=output1[i][0];j++)
        {
            output[i][j]=output1[i][j];
        }
    }

    for(int i=0;i<s2;i++)
    {
        for(int j=0;j<=output2[i][0];j++)
        {
            output[s1+i][j]=output2[i][j];
        }
    }
    return s1+s2;

}
int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;

  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) {
	for( int j = 1; j <= output[i][0]; j++) {
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
