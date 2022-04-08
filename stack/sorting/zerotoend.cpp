#include <iostream>
using namespace std;

void pushzerotoend(int *array,int n)
{
  for(int i=n-2;i>=0;i--)
  {
      int j;
      if(array[i]==0)
      {


           for(j=i+1;j<n;j++)
          {
            array[j-1]=array[j];
          }
          array[j-1]=0;
      }

  }

}
int main()
{
    int t;
    cout<<"enter t : ";
    cin>>t;
    while(t--)
    {
        int size;
        cout<<"\n enter size : ";
        cin>>size;
        int *array=new int[size];
        cout<<"enter array : ";
        for(int i=0;i<size;i++)
        {

            cin>>array[i];

        }
        pushzerotoend(array,size);
        for(int i=0;i<size;i++)
        {

            cout<<array[i];
        }
        delete[] array;
        cout<<endl;
    }
return 0;
}
