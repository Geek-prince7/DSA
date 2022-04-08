#include<iostream>
using namespace std;

int partition(int input[],int si,int ei)
{
    int count=si;
    int x=input[si];
    for(int i=si+1;i<=ei;i++)
    {
        if(input[i]<x)
        {
            count++;
        }
    }
    input[si]=input[count];
    input[count]=x;
    int i=si,j=ei;
    while(i<count && j>count)
    {
        if(input[i]<x)
        {
            i++;
        }
        else if(input[j]>=x)
        {
            j--;
        }
        else
        {
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;

        }
    }
   return count;

}


void quicksorthelper(int input[],int si,int ei)
{
    if(si>=ei)
    {
        return;
    }
  int PI=partition(input,si,ei);
    quicksorthelper(input,si,PI-1);
    quicksorthelper(input,PI+1,ei);
    return;
}
void quick_sort(int input[],int size)
{
    int si=0;
    int ei=size-1;
    quicksorthelper(input,si,ei);
    return;
}
int main()
{
     int n;
     cout<<"Enter length : ";
    cin >> n;
    cout<<endl;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quick_sort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

    return 0;
}
