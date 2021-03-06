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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head==NULL)
    {
        return NULL;
    }
    int prevdata=head->data;
    Node *temp=head->next;
    Node *ptr=head;
    while(temp!=NULL)
    {
        if(prevdata==temp->data)
        {
            ptr->next=temp->next;
            delete temp;
            temp=ptr->next;
        }
        else{
        prevdata=temp->data;
        temp=temp->next;
        ptr=ptr->next;
    }
    return head;

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}
