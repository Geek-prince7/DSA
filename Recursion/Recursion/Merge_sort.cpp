#include <iostream>
using namespace std;
void helper(int input[],int si,int ei)
{
    if(si>=ei)
    {
        return;
    }
    int mid=(si+ei)/2;
    helper(input,si,mid);
    helper(input,mid+1,ei);
    int i=si;
    int j=mid+1;
    int newar[ei-si+1];
    int k=0;
    while(i<=mid && j<=ei)
    {
        if(input[i]>=input[j])
        {
            newar[k]=input[j];
            k++;
            j++;
        }
        else{
            newar[k]=input[i];
            k++;
            i++;
        }
    }
    while(i<=mid)
    {
        newar[k]=input[i];
        i++;
        k++;
    }
     while(j<=ei)
    {
        newar[k]=input[j];
        j++;
        k++;
    }
    k=0;
    for(int a=si;a<=ei;a++)
    {
        input[a]=newar[k];
        k++;
    }
    return;
}

void mergeSort(int input[], int size){
	// Write your code here
	int si=0;
	int ei=size-1;
	helper(input,si,ei);
	return;


}

int main() {
  int length;
  cout<<"Enter length of array : ";
  cin >> length;
  int* input = new int[length];
  cout<<"Enter array :"<<endl;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  cout<<endl;
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
