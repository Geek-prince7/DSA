#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
//#include "solution.h"

BinaryTreeNode<int> *takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


/*
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here

    vector<Node<int>*> v;
    if(root==NULL)
    {
        return v;
    }
    queue<BinaryTreeNode<int>*> q1;
    q1.push(root);
    q1.push(NULL);
    Node<int> *head=NULL;
    Node<int> *tail=NULL;
    while(!q1.empty())
    {
        BinaryTreeNode<int>*current=q1.front();
        q1.pop();
        if(current)
        {
            cout<<current->data<<" ";
            if(current->left)
            {
                q1.push(current->left);
            }
            if(current->right)
            {
                q1.push(current->right);
            }
            Node<int>*currentnode=new Node<int>(current->data);
            if(!head)
            {
                head=tail=currentnode;
            }
            else
            {
                tail->next=currentnode;
                tail=currentnode;
            }


        }
        else
        {
            if(q1.empty())
            {
                break;
            }
            else
            {
                v.push_back(head);
                head=NULL;
                tail=NULL;
                q1.push(NULL);
                cout<<endl;
            }
        }
    }
    return v;
}

*/










vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here

    vector<Node<int>*> v;
    if(root==NULL)
    {
        return v;
    }
    queue<BinaryTreeNode<int>*> q1;
    q1.push(root);
    //q1.push(NULL);
    Node<int> *head=NULL;
    Node<int> *tail=NULL;
    while(!q1.empty())
    {
        int sizeofq=q1.size();
        while(sizeofq--)
        {
            BinaryTreeNode<int>*current=q1.front();
            q1.pop();

                //cout<<current->data<<" ";
                if(current->left)
                {
                    q1.push(current->left);
                }
                if(current->right)
                {
                    q1.push(current->right);
                }
                Node<int>*currentnode=new Node<int>(current->data);
                if(!head)
                {
                    head=tail=currentnode;
                }
                else
                {
                    tail->next=currentnode;
                    tail=currentnode;
                }










        }
        v.push_back(head);
        head=NULL;
        tail=NULL;
    }
    return v;
}









/*
//aproach 2
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here

    vector<Node<int>*> v;
    if(root==NULL)
    {
        return v;
    }
    queue<BinaryTreeNode<int>*> q1;
    q1.push(root);
    int i=1;

    Node<int> *ll1=new Node<int>(root->data);
    v.push_back(ll1);
    while(!q1.empty())
    {
        int k=i;
        i=0;
        Node<int>*head=NULL;
        Node<int>*tail=NULL;
        while(k--)
        {
            BinaryTreeNode<int>*current=q1.front();
            q1.pop();
            if(current->left!=NULL)
            {

                i++;
                q1.push(current->left);
                Node<int> *node=new Node<int>(current->left->data);
                if(head==NULL)
                {
                    head=tail=node;
                }
                else
                {
                    tail->next=node;
                    tail=node;
                }

            }
             if(current->right!=NULL)
            {

                i++;
                q1.push(current->right);
                Node<int> *node=new Node<int>(current->right->data);
                if(head==NULL)
                {
                    head=tail=node;
                }
                else
                {
                    tail->next=node;
                    tail=node;
                }

            }


        }
        v.push_back(head);
    }
    return v;
}




*/


int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}
