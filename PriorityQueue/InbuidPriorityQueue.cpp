#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(1);
    pq.push(100);
    pq.push(19);
    pq.push(17);
    pq.push(3);
    cout<<"size is :"<<pq.size()<<endl;
    cout<<"top is : "<<pq.top()<<endl;
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
