#include<iostream>
#include"BinaryTree.h"
using namespace std;
/*
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
    if(root==NULL)
    {
        return -1;
    }
    int ans=-1;
    if(root->data==a || root->data==b)
    {
        ans=root->data;
    }
    int leftans=getLCA(root->left,a,b);
    int rightans=getLCA(root->right,a,b);
    if(leftans==a || leftans==b)
    {
        if(rightans==a || rightans==b)
        {
            return root->data;
        }
        else if(rightans==-1)
        {
            if(ans==a || ans==b)
            {
                return root->data;
            }
            else
            {
                return leftans;
            }
        }
    }
    else if(rightans==a || rightans==b)
    {
        if(ans==a || ans==b)
        {
            return root->data;
        }
        else if (ans==-1)
        {
            return rightans;
        }

    }
    else if(leftans!=-1 &&leftans!=a &&leftans!=b)
    {
        return leftans;
    }
    if(rightans!=-1 && rightans!=a &&rightans!=b)
    {
        return rightans;
    }
    return ans;


}
*/
int getLCA(BinaryTreeNode <int>* root , int a, int b)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==a || root->data==b)
    {
        return root->data;
    }
    int leftans=getLCA(root->left,a,b);
    int rightans=getLCA(root->right,a,b);
    if(rightans!=-1 && leftans!=-1 )
    {
        return root->data;
    }
    else if (rightans!=-1)
    {
        return rightans;
    }
    else if( leftans!=-1)
    {
        return leftans;
    }
    return -1;
}
int main() {
    BinaryTreeNode<int>* root = BinaryTreeNode<int>::takeinput_levelwise();
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}
