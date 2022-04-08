#include<unordered_map>
#include <iostream>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int> mymap;
    int maxcount=0;
    int count=0;
    //unordered_map<int,int>::iterator it;
    mymap[arr[0]]=0;
    int sumUpto=arr[0];
    for(int i=1;i<n;i++)
    {
       // it=mymap.begin();
        sumUpto+=arr[i];
        //while(it!=mymap.end())
        //{
            if(sumUpto==0)
            {
                count=i+1;
            }

            else if(mymap.count(sumUpto))
            {
                count=i-mymap[sumUpto];
            }
          //  it++;

        //}
        if(count>maxcount)
        {
            maxcount=count;
        }
        if(count==0)
        {
            mymap[sumUpto]=i;
        }
        count=0;


    }
    return maxcount;
}


int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}
