#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
//#include "Solution.h"

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int helper(Node *head)
{
    if(head==NULL)
    {
        return 0;
    }
    int c=helper(head->next);
    if(c==1)
    {
       head->data+=1;
       c--;
    }
    if(head->next==NULL)
    {
        head->data+=1;

    }
    if(head->data==10)
    {
        head->data=0;
        c++;
    }

    return c;

}
Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
     int carry=helper(head);
     if(carry!=0)
     {
         Node *newnode =new Node(carry);
         newnode->next=head;
         head=newnode;
     }
     return head;

}




int main() {
    Node *head = takeinput();

    head = NextLargeNumber(head);
    print(head);
    return 0;
}



