#include<iostream>
using namespace std;

template<typename T>
class dynamicQueue
{
    T*data;
    int firstIndex;
    int nextIndex;
    int capacity;
    int size;
public:
    dynamicQueue()
    {
        data=new T[5];
        capacity=5;
        size=0;
        firstIndex=-1;
        nextIndex=0;
    }
    int getsize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size==0;
    }
    T front()
    {
        if(isEmpty())
        {
            cout<<"Underflow !"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    void enqueue(T element)
    {
        if(size==capacity)
        {
            T * newdata=new T[2*capacity];
            int i=firstIndex+1;
            int j=0;
            newdata[j]=data[firstIndex];
            j++;
            while(i!=nextIndex)
            {
                newdata[j]=data[i];
                j++;
                i=(i+1)%capacity;
            }

            firstIndex=0;
            nextIndex=capacity;
            capacity*=2;
            delete[]data;
            data=newdata;
        }
        data[nextIndex]=element;
        //cout<<"added "<<element<<endl;
        nextIndex=(nextIndex+1)%capacity;
        if(firstIndex==-1)
        {
            firstIndex++;
        }
        size++;
    }
    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"Underflow !"<<endl;
            return 0;
        }
        T ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        if(size==0)
        {
            firstIndex=-1;
            nextIndex=0;
        }
        return ans;
    }
};

int main()
{
    dynamicQueue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    //q.enqueue(60);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getsize()<<endl;
    cout<<q.front()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.dequeue()<<endl;
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);
    cout<<q.dequeue()<<endl;
    cout<<q.front();

    return 0;
}


