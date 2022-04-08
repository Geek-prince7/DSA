#include<iostream>
using namespace std;
template <typename T>
class Node
{
public:

    T data;
    Node *next;
    Node(T data)
    {
        this->data=data;
        this->next=NULL;
    }
};
template<typename T>
class QueueLL
{
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    QueueLL()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }
    bool isEmpty()
    {
        return size==0;
    }
    int getsize()
    {
        return size;
    }
    T front()
    {
        if(isEmpty())
        {
            cout<<"undeflow"<<endl;
            return 0;
        }
        return head->data;
    }

    void enqueue(T element)
    {
        Node<T> *newnode=new Node<T>(element);
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        size++;

    }
    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"Undeflow"<<endl;
            return 0;
        }
        Node<T> * temp=head;
        head=head->next;
        T ans=temp->data;
        delete temp;
        size--;
        return ans;
    }
};
int main()
{
    QueueLL<int> q;
    q.enqueue(10);
    q.enqueue(20);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.getsize()<<endl;
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<<q.getsize()<<endl;
    cout<<q.front()<<endl;
    cout<<q.isEmpty()<<endl;


}
