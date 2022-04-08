#include <iostream>
#include <vector>
using namespace std;

//#include "solution.h"

#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int,int> mymap;
    for(int i=0;i<n;i++)
    {
        ++mymap[arr[i]];
    }
    int maxcount=0;
    int count=0;
    int finalstart;
    int start=arr[0];

    for(int i=0;i<n;i++)
    {
        int k=arr[i];
        cout<<i<<"th iteration"<<endl<<endl;
        start=arr[i];
        while(mymap.count(k))
        {
            count++;
            //start=arr[i];
            cout<<k<<" found and count is :"<<count<<endl;
            k++;
        }
        //k=arr[i]-1;
        /*
        while(mymap.count(k))
        {
            count++;
            start=k;
            cout<<k<<" found and count is :"<<count<<endl;
            k--;
        }
        */
        if(maxcount<count)
        {
            cout<<"maxcount is :"<<maxcount<<" smaller than count :"<<count<<" so adding value in max count"<<endl;
            maxcount=count;
            finalstart=start;
            cout<<"final start is :"<<finalstart<<endl;
            //count=0;
        }
        count=0;




    }
    vector<int> out;
    cout<<"final si is : "<<finalstart<<endl;
    out.push_back(finalstart);
    if(maxcount>1)
    {
    	out.push_back(finalstart+maxcount-1);
    }
    return out;


}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
