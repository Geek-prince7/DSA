#include <iostream>
using namespace std;
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
int findUnique(int *arr, int n)
{
    //Write your code here
   mergesort(arr,0,n-1);

    for(int i=0;i<n;i+=2)
    {
        if(arr[i]!=arr[i+1])
        {
            return arr[i];
        }
    }


}


int main()
{
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
     //mergesort(input,0,size-1);
     // for (int i = 0; i < size; ++i) {
     //       cout<< input[i]<<" ";
     //   }



    return 0;
}
