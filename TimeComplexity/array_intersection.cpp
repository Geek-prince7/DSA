#include <iostream>
#include <algorithm>
using namespace std;


//#include "solution.h"
void mergesort(int *arr,int si,int ei)
{
    if(si>=ei)
    {
        return;
    }
    int mid=(si+ei)/2;
    mergesort(arr,si,mid);
    mergesort(arr,mid+1,ei);
    int i=si,j=mid+1,k=0;
    int helper[ei-si+1];
    while(i<=mid &&j<=ei)
    {
        if(arr[i]<=arr[j])
        {
            helper[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            helper[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        helper[k]=arr[i];
        i++;
        k++;
    }
    while(j<=ei)
    {
        helper[k]=arr[j];
        j++;
        k++;
    }
    k=0;
    for(int a=si;a<=ei;a++)
    {
        arr[a]=helper[k];
        k++;
    }
}
void intersection(int *arr1, int *arr2, int n, int m)
{
    //Write your code here
    mergesort(arr1,0,n-1);
    mergesort(arr2,0,m-1);
    int i=0,j=0;
    while(i<n && j<m)
    {

        if(arr1[i]>arr2[j])
        {
            j++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            cout<<arr2[j];
            i++;
            j++;

        }
    }

}

int main()
{

		int size1, size2;

		cout<<"size 1 :";
		cin >> size1;
		int *input1 = new int[size1];
		cout<<"enter elements :";

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cout<<"size 2 :";
		cin >> size2;
		int *input2 = new int[size2];

		cout<<"enter elements :";
		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);

		delete[] input1;
		delete[] input2;

		cout << endl;


	return 0;
}
