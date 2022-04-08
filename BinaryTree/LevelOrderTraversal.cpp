#include<iostream>
#include"BinaryTree.h"
#include<queue>
#include<algorithm>
using namespace std;
/*
void printLevelOrder(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> q1;
    q1.push(root);
    int i=1;
    while(!q1.empty())
    {
        int k=i;
        i=0;
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
    }

}
*/
void printLevelOrder(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int>*> q1;
    q1.push(root);
    q1.push(NULL);
    while(!q1.empty())
    {
        BinaryTreeNode<int>* current=q1.front();
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
        }
        else
        {
            if(q1.empty())
            {
                break;
            }
            else
            {
                cout<<endl;
                q1.push(NULL);
            }
        }
    }
}
int main()
{
    BinaryTreeNode<int>*root=BinaryTreeNode<int>::takeinput_levelwise();
    printLevelOrder(root);
}
