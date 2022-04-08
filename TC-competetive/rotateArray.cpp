#include <iostream>
using namespace std;

//using namespace std;
void rotate(int arr[], int d, int n)
{
    //SAVE first d elements in an array
    int arr2[d];
    for(int i=0;i<d;i++)
    {
        arr2[i]=arr[i];
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    for(int i=d;i<n;i++)
    {
        arr[i-d]=arr[i];
        cout<<arr[i-d]<<" ";
    }
    cout<<endl;
    int k=0;
    for(int i=n-d;i<n;i++)
    {
        arr[i]=arr2[k];
        cout<<arr[i]<<" ";
        k++;
    }
    cout<<endl;

}



int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}

	return 0;
}
