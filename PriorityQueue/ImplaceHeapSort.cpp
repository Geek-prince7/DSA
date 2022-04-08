#include <iostream>
//#include "solution.h"

using namespace std;

void heapSort(int arr[], int n) {
    // Write your code
    int si=1;
    for(si;si<n;si++)
    {
        int ci=si;
        while(ci>0)
        {
            int pi=(ci-1)/2;
            if(arr[pi]>arr[ci])
            {
                int temp=arr[pi];
                arr[pi]=arr[ci];
                arr[ci]=temp;
            }
            else
            {
                break;
            }
            ci=pi;

        }
    }

    while(n>0)
    {
        int li=n-1;
        int temp=arr[0];
        arr[0]=arr[li];
        arr[li]=temp;
        n--;
        int pi=0;
        int c1=1;
        int c2=2;

        while(c1<n-1)
        {
            int min=pi;
            if(arr[min]>arr[c1])
            {
                min=c1;
            }
            if(c2<n && arr[c2]<arr[min])
            {
                min=c2;
            }
            if(min==pi)
            {
                break;
            }
            int temp=arr[min];
            arr[min]=arr[pi];
            arr[pi]=temp;
            pi=min;
            c1=2*pi+1;
            c2=2*pi+2;
        }
    }

}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    }

    delete[] input;
}
