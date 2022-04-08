#include<iostream>
#include"BinaryTree.h"
#include<vector>
using namespace std;

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
    {
        vector<int>* out=new vector<int>();
        out->push_back(root->data);
        return out;
    }
    vector<int> *leftans=longestPath(root->left);
    vector<int> *rightans=longestPath(root->right);
    if(leftans && rightans)
    {


        if(leftans->size()>=rightans->size())
        {
            leftans->push_back(root->data);
            return leftans;
        }
        else
        {
            rightans->push_back(root->data);
            return rightans;
        }
    }
    else if(leftans)
    {
        leftans->push_back(root->data);
            return leftans;

    }
    else if(rightans)
    {
        rightans->push_back(root->data);
        return rightans;
    }
    return NULL;

}
int main()
{
    BinaryTreeNode<int>* root=BinaryTreeNode<int>::takeinput_levelwise();
    vector<int>* ans=longestPath(root);
    for(int i=0;i<ans->size();i++)
    {
        cout<<ans->at(i)<<" ";
    }

}
