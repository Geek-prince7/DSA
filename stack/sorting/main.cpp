#include <iostream>
using namespace std;


void pushZeroesEnd(int *input, int size)
{
    //Write your code here
    for(int i=size-2;i>=0;i--)
    {
        if(input[i]==0)
        {
          int j;
          for(j=i+1;j<size;j++)
          {
             input[j-1]=input[j];
          }

          input[j-1]=0;
        }
    }

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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}
