#include <iostream>
using namespace std;



/*
Node* merge(Node *h1, Node *h2)
{

    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }

    Node *orghead = NULL;
    Node *orgtail = NULL;


    if (h1->data < h2->data)
    {
        orghead = h1;
        orgtail = h1;
        h1 = h1->next;
    }
    else
    {
        orghead = h2;
        orgtail = h2;
        h2 = h2->next;
    }

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            orgtail->next = h1;
            orgtail = h1;
            h1 = h1->next;
        }
        else
        {
            orgtail->next = h2;
            orgtail = h2;
            h2 = h2->next;
        }
    }

    if (h1 != NULL)
    {
        orgtail->next = h1;
    }
    if (h2 != NULL)
    {
        orgtail->next = h2;
    }

    return orghead;
}
Node* mergeSort(Node *head) {
    //write your code here
    if (head == NULL || head->next == NULL)
        return head;

    Node* fast = head->next;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* a = head, *b = slow->next;
    slow->next = NULL;

    Node* c = mergeSort(a);
    Node* d = mergeSort(b);
    Node *e = merge(c, d);

    return e;
}

*/

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
Node *findmid(Node*head)
{
    Node*mid=head;
    Node *fast=head->next;
    while(fast!=NULL  && fast->next!=NULL)
    {
        mid=mid->next;
        fast=fast->next->next;
    }
    return mid;
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

Node * helper(Node*head,Node *tail)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
  //  if(head==tail)
  //  {
  //      return head;
  //  }
    Node *mid=findmid(head);
    Node *start=mid->next;
    mid->next=NULL;

    Node *head1=helper(head,mid);
    Node* head2=helper(start,tail);
     return mergeTwoSortedLinkedLists(head1,head2);
}
Node *mergeSort(Node *head)
{
	//Write your code here
	Node* tail=head;
	while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    return helper(head,tail);

}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}
