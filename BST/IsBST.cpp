#include <iostream>
#include <queue>
#include<climits>

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

//aproach 3
class custom
{
public:

    int minimum;
    int  maximum;
    bool check;
    custom()
    {
        minimum=INT_MAX;
        maximum=INT_MIN;
        check=true;
    }
};

custom isBSThelper(BinaryTreeNode<int>* root)
{
    custom ans;
    if(root==NULL)
    {
        return ans;
    }
    custom ansleft=isBSThelper(root->left);
    custom ansright=isBSThelper(root->right);
    int maxi=max(root->data,max(ansleft.maximum,ansright.maximum));
    int mini=min(root->data,min(ansleft.minimum,ansright.minimum));
    bool bst_check=(root->data>ansleft.maximum)&&(root->data<=ansright.minimum)&&(ansleft.check) && (ansright.check);
    ans.maximum=maxi;
    ans.minimum=mini;
    ans.check=bst_check;
    return ans;

}


bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
	return isBSThelper(root).check;


}
*/


/*
//approach 2


int maximum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root)
{
   if(root==NULL)
   {
       return true;
   }
   //bool ansleft=isBST(root->left);
   //bool ansright=isBST(root->right);
   int maxleft=maximum(root->left);
   int minright=minimum(root->right);
   bool output=(root->data>maxleft) &&(root->data<=minright) && (isBST(root->left)) &&(isBST(root->right));
   return output;
}

*/


//approach 1
bool isBSTheleper(BinaryTreeNode<int>* root, int min, int max) {
	// Write your code here
    if(root==NULL)
    {
        return true;
    }
     int  newmin=root->data;
    int  newmax=root->data-1;
    bool leftans=isBSTheleper(root->left,min,newmax);
    bool rightans=isBSTheleper(root->right,newmin,max);
    return leftans && rightans && (root->data>=min) &&(root->data <= max);

}
bool isBST(BinaryTreeNode<int> *root)
{
   return  isBSTheleper(root,INT_MIN,INT_MAX);
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}
