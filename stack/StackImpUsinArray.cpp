#include<iostream>
#include<climits>
using namespace std;
class stackArray
{
    int*data;
    int capacity;
    int nextIndex;
public:
    stackArray(int cap)
    {
        capacity=cap;
        data=new int[capacity];
        nextIndex=0;

    }
    bool isFull()
    {
        return nextIndex==capacity;
    }
    bool isEmpty()
    {
        return nextIndex==0;
    }
    void PUSH(int d)
    {
        if(isFull())
        {
            cout<<"Overflow";
            return;
        }
        data[nextIndex]=d;
        nextIndex++;


    }
    int POP()
    {
        if(isEmpty())
        {
            cout<<"Underflow";
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int TOP()
    {
        if(isEmpty())
        {
            cout<<"Underflow";
            return INT_MIN;
        }
        return data[nextIndex-1];
    }
    int size()
    {
        return nextIndex;
    }

};


int main()
{
    stackArray s(5);
    s.PUSH(10);
    s.PUSH(20);
    s.PUSH(30);
    s.PUSH(40);
    s.PUSH(50);
    s.PUSH(60);
    cout<<"\n Popped element is :"<<s.POP()<<endl;
    cout<<"Size of stack is : "<<s.size()<<endl;
    cout<<"TOP element of stack is : "<<s.TOP();

}
