#include <iostream>
#include <queue>
#include<climits>
#include<algorithm>
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

/*
BinaryTreeNode<int>* pairpresent(BinaryTreeNode<int>*root,int sum)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data!=INT_MIN)
    {

        if(sum-(root->data)==0)
        {
            //root->data=INT_MIN;
            return root;
        }
    }
    BinaryTreeNode<int>* leftans=pairpresent(root->left,sum);
    BinaryTreeNode<int>* rightans=pairpresent(root->right,sum);
    if(leftans)
    {
        return leftans;
    }
    else
    {
        return rightans;
    }
}
void pairsumHelper(BinaryTreeNode<int>*current,int sum,BinaryTreeNode<int>* root)
{
    if(current==NULL)
    {
        return;
    }
    if(current->data!=INT_MIN)
    {
        BinaryTreeNode<int>* check=pairpresent(root,sum-current->data);
        if(check)
        {
            if(check!=current)
            {
                cout<<min(current->data,sum-current->data)<<" "<<max(current->data,sum-current->data)<<endl;
                check->data=INT_MIN;
            }
        }
    }

    pairsumHelper(current->left,sum,root);
    pairsumHelper(current->right,sum,root);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(root==NULL)
    {
        return;
    }
    pairsumHelper(root,sum,root);
}
*/
int convertarray(BinaryTreeNode<int>*root,int *input,int i)
{
    if(root==NULL)
    {
        return i;
    }
    int leftans=convertarray(root->left,input,i);
    input[leftans]=root->data;
    int rightans=convertarray(root->right,input,leftans+1);
    return rightans;

}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(root==NULL)
    {
        return;
    }
    int i=0;
    int *input=new int[100];
    int size=convertarray(root,input,i);
    sort(input,input+size);
    int j=size-1;
    while(i<j)
    {
        if(input[i]+input[j]<sum)
        {
            i++;
        }
        else if(input[i]+input[j]>sum)
        {
            j--;
        }
        else
        {
            cout<<input[i]<<" "<<input[j]<<endl;
            i++;
            j--;
        }
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}
