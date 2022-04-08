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
Node *skipMdeleteN(Node *head, int M, int N)
{
    if(head==NULL || N==0)
    {
        return head;
    }
    if(M==0)
    {
        return NULL;
    }
    int i=M-1;
    int j=N;
    Node *temp=head;
    while(i-- && temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node *ptr=temp;
    while(j-- && temp!=NULL)
    {
        temp=temp->next;
    }

    Node *free;
          if(temp!=NULL)
          {
            free=ptr->next;
           // ptr->next=NULL;
            while(free!=temp->next)
            {
                Node *temp1=free->next;
                delete free;
                free=temp1;
            }
            ptr->next=temp->next;

          }
          else{
            ptr->next=NULL;
            return NULL;
          }



          temp->next=skipMdeleteN(temp->next,M,N);
          return head;





}
/*
Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
	if(head==NULL||N==0)
    {
        return head;
    }
    if(M==0)
    {
        return NULL;
    }
    Node *temp=head;
    int k=M--;
    int j=N;
    Node *ptr=NULL;
    while(temp!=NULL)
    {
        while(M-- &&temp->next!=NULL)
         {
             temp=temp->next;

          }
          ptr=temp;
          while(N-- &&temp!=NULL)
          {
              temp=temp->next;
          }


          Node *free;
          if(temp!=NULL)
          {
            free=ptr->next;
           // ptr->next=NULL;
            while(free!=temp->next)
            {
                Node *temp1=free->next;
                delete free;
                free=temp1;
            }
            ptr->next=temp->next;

          }
          else{
            ptr->next=NULL;
          }


          M=k;
          N=j;
          //temp=temp->next;

    }
    return head;

}
*/

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
