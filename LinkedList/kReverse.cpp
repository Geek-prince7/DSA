#include <iostream>

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

using namespace std;
//#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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

Node *reverseKelements(Node *head, int k)
{
	//Write your code here
    if(head==NULL || k==1)
    {
        return head;
    }
    Node *temp=reverseKelements(head->next,--k);
    Node *ptr=head->next->next;
    head->next->next=head;
    head->next=ptr;
    return temp;

}

Node *reverseLL(Node *head)
{
    //Write your code here
    if(head==NULL ||head->next==NULL)
    {
        return head;
    }
    Node *temp=reverseLL(head->next);
     head->next->next=head;
     head->next=NULL;
     return temp;


}

Node *kReverse(Node *head, int k)
{
    if(head==NULL ||k==0)
    {
        return head;
    }
    int length=0;
    Node*temp=head;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    temp=head;
    if(k>length)
    {
         return reverseLL(temp);
         //return head;
        // cout<<"pointing at this node : "<<temp->data<<"count is : "<<length<<endl;
         //return temp;
    }
    int i=k;
    while(--i)
    {
        temp=temp->next;
    }
    Node *gethead=kReverse(temp->next,k);
    temp->next=gethead;

    Node *newhead=reverseKelements(head,k);
    return newhead;


}




int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}

	return 0;
}
