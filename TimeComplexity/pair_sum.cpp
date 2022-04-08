#include <iostream>
#include <algorithm>
using namespace std;
int pairSum(int *arr, int n, int num)
{
	//Write your code here
    sort(arr,arr+n);
    int i=0,j=n-1,count=0;
    while(i<j)
    {
        if(arr[i]+arr[j]<num)
        {
            i++;
        }
        else if(arr[i]+arr[j]>num)
        {
            j--;
        }
        else
        {
           // count++;
            int icount=0,jcount=0,x=arr[i],y=arr[j];
             if(arr[i] + arr[j] == num && arr[i] == arr[j])
             {
                 return ((j+1-i)*(j-i))/2;
            }
            else if(arr[i]==arr[i+1] && arr[j]==arr[j-1])
            {
                for(int a=i;a<n;a++)
                {
                    if(arr[a]==x)
                    {
                        icount++;
                    }
                }
                 for(int a=j;a>0;a--)
                {
                    if(arr[a]==y)
                    {
                        jcount++;
                    }
                }
                count+=icount*jcount;
                i+=icount;
                j-=jcount;

            }
            else if(arr[i]==arr[i+1])
            {
                i++;
                count++;
            }
            else if(arr[j]==arr[j-1])
            {
                j--;
                count++;
            }
            else
            {
                count++;
                i++;
                j--;
            }
        }
    }
    return count;

}
int main()
{
	int size;
		int x;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;


	return 0;
}
