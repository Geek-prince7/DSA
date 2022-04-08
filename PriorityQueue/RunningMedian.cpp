#include <iostream>
#include<queue>
#include<vector>
using namespace std;

//#include "solution.h"
/*
//working code
//method 1
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
        priority_queue<int,vector<int>,greater<int>> pq2=pq;
        while(!pq2.empty())
        {
            int getsize=pq2.size();

            int val1=getsize/2;
            int val2=val1-1;
            //cout<<"median 1 and 2 is :"<<val2<<" , "<<val1<<endl;
            int i=0;
            int data1;
            int data2=0;
            while(i<=val1)
            {
                data1=data2;
                data2=pq2.top();
                //cout<<data2<<" popped from pq2 "<<endl;
                pq2.pop();
                i++;

            }
            if(getsize%2==0)
            {
                int result=(data1+data2)/2;
                cout<<result<<" ";
                break;
            }
            else
            {
                cout<<data2<<" ";
                break;
            }
        }
    }


}
*/


void findMedian(int *arr, int n)
{
    priority_queue<int,vector<int>,greater<int>> mini;
    priority_queue<int> maxi;
    for(int i=0;i<n;i++)
    {
        if(maxi.empty())
        {
            //cout<<arr[i]<<" maxi empty so pushed in maxi"<<endl;
            maxi.push(arr[i]);
        }
        else
        {
            if(maxi.top()< arr[i])
            {
                //cout<<arr[i]<<" maxi top is smaller so pushed in mini"<<endl;
                mini.push(arr[i]);
            }
            else
            {
                //cout<<arr[i]<<" maxi top is larger so pushed in maxi"<<endl;
                maxi.push(arr[i]);
            }
        }
        if(maxi.size()-mini.size()==0)
        {
            cout<<(maxi.top()+mini.top())/2<<" ";
        }
        else if(maxi.size()-mini.size()==1)
        {
            cout<<maxi.top()<<" ";
        }
        else if(mini.size()-maxi.size()==1)
        {
            cout<<mini.top()<<" ";
        }
        else if(maxi.size()-mini.size()==2)
        {
            //cout<<maxi.top()<<" maxi size is 2 larger so pushed in mini"<<endl;
            mini.push(maxi.top());
            maxi.pop();
            cout<<(maxi.top()+mini.top())/2<<" ";
        }
        else if(mini.size()-maxi.size()==2)
        {
            //cout<<maxi.top()<<" mini size is 2 larger so pushed in maxi"<<endl;
            maxi.push(mini.top());
            mini.pop();
            cout<<(maxi.top()+mini.top())/2<<" ";
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
