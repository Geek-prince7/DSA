#include <iostream>
using namespace std;

int helper(int input[], int n, int output[][50], int k) {
    // Write your code here
    if(n<=0)
    {
        output[0][0]=0;
        return 0;
    }
    int ans=helper(input+1,n-1,output,k-input[0]);
    for(int i=0;i<ans;i++)
    {
        output[ans+i][0]=1+output[i][0];
    }

    for(int i=ans;i<ans+count;i++)
    {
        for(int j=1;j<output[i][0];j++)
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
int subsetSumToK(int input[], int n, int output[][50], int k) {
    int index=helper(input,n,output,k);
    int smallout[1000][50];
    int a=1,b=1;
    int count=0;
    for(int i=0;i<index;i++)
    {
        for(int j=1;j<output[i[0];j++)
        {
            if()
        }
    }

}



int main()
{
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
