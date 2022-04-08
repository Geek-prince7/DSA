#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
Node *head;

void createLL()
{
    head=0;
    Node*temp=head;
    int choice=1;
    while(choice)
    {
        int data;
        cout<<"Enter data in LL : ";
        cin>>data;
        Node *newnode=new Node(data);
        if(head==0)
        {
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        cout<<"enter a choice : ";
        cin>>choice;
    }


}
void print(Node*head)
{
    if(head==NULL)
    {
        return;
    }
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


Node *Reverse(Node*head)
{
    if(head==0)
    {
        return 0;
    }
    else if(head->next==NULL)
    {
        return head;
    }
    Node* temp=head->next->next;
    Node*ptr=head->next;
    head->next=NULL;
    while(temp!=NULL)
    {
        ptr->next=head;
        head=ptr;
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=head;
    head=ptr;
    return head;


}

int main()
{
   // Node *temp=new Node(5);
    createLL();
    cout<<"printing the data : "<<endl;
    print(head);
    cout<<"Reversing LL : ";
    head=Reverse(head);
    print(head);
    return 0;
}
