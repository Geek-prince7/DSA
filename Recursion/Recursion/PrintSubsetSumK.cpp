#include <iostream>
using namespace std;

void helper(int input[],int n,int output[],int m,int k)
{
    if(n==0)
    {
        if(k==0)
        {
            for(int i=0;i<m;i++)
            {
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }

            return;

    }
    int out[100];

    for(int i=0;i<m;i++)
    {
        out[i]=output[i];
    }
    out[m]=input[0];
    helper(input+1,n-1,out,m+1,k-input[0]);
     helper(input+1,n-1,output,m,k);
    return;
}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[500];
    helper(input,size,output,0,k);
    return;
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
