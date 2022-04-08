#include<iostream>
#include<climits>
using namespace std;
class Node
{
public:

    int data;
    Node*next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }


};
class stackLL
{
    Node *head;
    int nextIndex;
public:
    stackLL()
    {
        head=NULL;
        nextIndex=0;
    }
    void PUSH(int data)
    {
        Node *newnode=new Node(data);
            newnode->next=head;
            head=newnode;
        nextIndex++;

    }
    int POP()
    {
        if(isEmpty())
        {
            return -1;
        }
        int a=head->data;
        head=head->next;
        nextIndex--;
        return a;
    }
    int TOP()
    {
        if(isEmpty())
        {
            return -1;
        }
        return head->data;
    }
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex==0;
    }
};
int main()
{
    stackLL s1;
    int choice=1;
    while(choice)
    {
        int n;
        cout<<"Enter data : ";
        cin>>n;
        cout<<endl;
        s1.PUSH(n);
        cout<<"Do u want to add more elements press 0 for no 1 for yes  : ";
        cin>>choice;

    }
    int k;
    cout<<"Press 1 for pop 2 for top 3 for size 4 to check empty";
    cin>>k;
    if(k==1)
    {
        cout<<"POPPED element is : "<<s1.POP()<<endl;

    }
    else if(k==2)
    {
        cout<<"TOP element is : "<<s1.TOP()<<endl;
    }
    else if(k==3)
    {
        cout<<"size of stack is : "<<s1.size()<<endl;

    }
    else if(k==4)
    {
        cout<<"whether empty or not : "<<s1.isEmpty()<<endl;
    }
    else{
        cout<<"Invalid";
    }

}
