//bubble sort iterative
#include <iostream>
#include<cstdlib>
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
Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
	if(head==NULL ||abs(i-j)==0)
    {
        return head;
    }
    else if((i==0&&abs(i-j)==1)||(j==0 &&abs(i-j)==1))
    {
        Node *temp=head->next;
        head->next=temp->next;
        temp->next=head;
        return temp;
    }
    else if(abs(i==0||j==0))
    {
        if(i==0)
        {
            Node *temp=head;
            while(--j &&temp!=NULL)
            {
                temp=temp->next;
            }
            Node *current=temp->next;
            temp->next=current->next;
            current->next=head->next;
            head->next=temp->next;
            temp->next=head;
            return current;

        }
        else if(j==0)
        {
            Node *temp=head;
            while(--i &&temp!=NULL)
            {
                temp=temp->next;
            }
            Node *current=temp->next;
            temp->next=current->next;
            current->next=head->next;
            head->next=temp->next;
            temp->next=head;
            return current;

        }

    }
    else if(abs(i-j)==1)
    {
        if(i-j==1)
        {
            Node *temp=head;
            while(--j &&temp!=NULL)
            {
                temp=temp->next;
            }
            Node *c1=temp->next;
            Node*c2=c1->next;
            temp->next=c2;
            c1->next=c2->next;
            c2->next=c1;
            return head;
        }
        else if(j-i==1)
        {
            Node *temp=head;
            while(--i &&temp!=NULL)
            {
                temp=temp->next;
            }
            Node *c1=temp->next;
            Node*c2=c1->next;
            temp->next=c2;
            c1->next=c2->next;
            c2->next=c1;
            return head;
        }

    }
    else
    {
        //Node *temp=head;
        Node *p1=head;
        Node *p2=head;
        Node *c1=head;
        Node *c2=head;
        while(--i && p1!=NULL)
        {
            p1=p1->next;
        }
        c1=p1->next;
        while(--j && p2!=NULL)
        {
            p2=p2->next;
        }
        c2=p2->next;
        p2->next=c2->next;
        c2->next=c1->next;
        p1->next=c2;
        c1->next=p2->next;
        p2->next=c1;
        return head;



    }
}
Node *bubbleSort(Node *head)
{
	// Write your code here
	if(head==NULL ||head->next==NULL)
    {
        return head;
    }
    Node *temp=head;
    int length=0;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    temp=head;
    for(int i=0;i<length-1;i++)
    {
        int j=0;
        Node *temp2=head;
        for(;j<length-i-1;j++)
        {
            if(temp2->data>temp2->next->data)
            {
                head=swapNodes(head,j,j+1);
                continue;
            }
            temp2=temp2->next;
        }
    }
    return head;

}
int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}
