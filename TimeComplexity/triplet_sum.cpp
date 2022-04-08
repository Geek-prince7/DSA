#include <iostream>
#include <algorithm>
using namespace std;

int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    sort(arr,arr+n);
    int j,k;
    int count=0;
    for(int i=0;i<n-2;i++)
    {
        j=i+1;
        k=n-1;
        while(j<k)
        {
            if(arr[i]+arr[j]+arr[k]>num)
            {

                k--;
            }
            else if(arr[i]+arr[j]+arr[k]<num)
            {
                j++;
            }
            else
            {
                 int countj=0,countk=0;
                 if(arr[j]==arr[k])
                 {
                     return (k+1-j)*(k-2-j);
                 }

                else if(arr[j]==arr[j+1] && arr[k]==arr[k-1])
                {

                    for(int a=j;a<k;a++)
                    {
                        if(arr[a]==arr[j])
                        {
                            countj++;
                        }
                    }
                     for(int a=k;a>j;a--)
                    {
                        if(arr[a]==arr[k])
                        {
                            countk++;
                        }
                    }
                    count+=(countj*countk);
                    j+=countj;
                    k-=countk;
                }
                else if(arr[j]==arr[j+1])
                {
                    for(int a=j;a<k;a++)
                    {
                        if(arr[a]==arr[j])
                        {
                            countj++;
                        }
                    }
                    count+=countj;
                    j+=countj;
                }
                else if(arr[k]==arr[k-1])
                {
                     for(int a=k;a>j;a--)
                    {
                        if(arr[a]==arr[k])
                        {
                            countk++;
                        }
                    }
                    count+=countk;
                    k-=countk;
                }
                else
                {
                   count++;
                   k--;
                   j++;
                }
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
		cout<<"enter the no :";
		cin >> x;

		cout <<"total count : "<<tripletSum(input, size, x) << endl;

		delete[] input;


	return 0;
}
