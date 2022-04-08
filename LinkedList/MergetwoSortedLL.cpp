#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};




Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    Node *i=head1;
    Node *result=NULL;
    Node *temp=NULL;
    Node *j=head2;
    while(i!=NULL &&j!=NULL)
    {
        if(i->data>j->data)
        {
            Node *newnode=new Node(j->data);
            if(result==NULL)
            {
                result=temp=newnode;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
            j=j->next;

        }
        else if(i->data<=j->data)
        {
           Node *newnode=new Node(i->data);
            if(result==NULL)
            {
                result=temp=newnode;
            }
            else{
                temp->next=newnode;
                temp=newnode;
            }
            i=i->next;
        }
    }
    while(i!=NULL)
    {
        Node *newnode=new Node(i->data);
        temp->next=newnode;
        temp=newnode;
        i=i->next;
    }
    while(j!=NULL)
    {
        Node *newnode=new Node(j->data);
        temp->next=newnode;
        temp=newnode;
        j=j->next;
    }
    return result;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}
