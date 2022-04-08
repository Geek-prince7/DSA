#include <iostream>
#include <vector>
#include<queue>
using namespace std;

//#include "solution.h"
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> q;
    priority_queue<int> pq;
    int count=0;
    for(int i=0;i<n;i++)
    {
        q.push(i);
        pq.push(arr[i]);
    }
    //cout<<"k is : "<<k<<endl;
    while(!q.empty())
    {
        if(arr[q.front()]==pq.top())
        {
            if(q.front()==k)
            {

                count++;
                //cout<<"we have found k"<<endl;
                return count;
            }
            else{
                count++;
                //cout<<pq.top()<<" popped count is :"<<count<<endl;
                pq.pop();
                q.pop();
            }
        }
        else
        {


        int l=q.front();
        //cout<<l<<"popped from queue and pushed at the end"<<endl;
        q.pop();
        q.push(l);
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}
