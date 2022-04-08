#include <iostream>
#include <queue>
#include<stack>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
//#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}


void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
    {
        return;
    }
    stack<BinaryTreeNode<int>*> s1,s2;
    s1.push(root);
    while(!s1.empty() ||!s2.empty())
    {
        while(!s1.empty())
        {
            BinaryTreeNode<int>*current=s1.top();
            s1.pop();
            cout<<current->data<<" ";
            if(current->left)
            {
                s2.push(current->left);
            }
            if(current->right)
            {
                s2.push(current->right);
            }
        }
        cout<<endl;
        while(!s2.empty())
        {
            BinaryTreeNode<int>*current=s2.top();
            s2.pop();
            cout<<current->data<<" ";

            if(current->right)
            {
                s1.push(current->right);
            }
            if(current->left)
            {
                s1.push(current->left);
            }
        }
        cout<<endl;
    }
}

/*
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> q1;
    q1.push(root);
    int alternate=0;
    int i=1;
    while(!q1.empty())
    {
        int k=i;
        i=0;
        if(alternate==0)
        {
            while(k--)
            {
                BinaryTreeNode<int>*current=q1.front();
                q1.pop();
                cout<<current->data<<" ";
                if(current->left!=NULL)
                {
                    q1.push(current->left);
                    i++;

                }
                if(current->right!=NULL)
                {
                    q1.push(current->right);
                    i++;
                }



            }
            cout<<endl;
            alternate=1;
        }
        else if(alternate==1)
        {
            stack<BinaryTreeNode<int>*>s;
            while(k--)
            {
                BinaryTreeNode<int>*current=q1.front();
                s.push(current);
                q1.pop();

                //cout<<current->data<<" ";
                if(current->left!=NULL)
                {
                    q1.push(current->left);
                    i++;

                }
                if(current->right!=NULL)
                {
                    q1.push(current->right);
                    i++;
                }



            }
            while(!s.empty())
            {
                cout<<s.top()->data<<" ";
                s.pop();
            }
            cout<<endl;
            alternate=0;
        }
    }
}
*/

int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}
