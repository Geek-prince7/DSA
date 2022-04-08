#include<iostream>
#include<climits>
#include"BinaryTree.h"
using namespace std;


class BST
{
    BinaryTreeNode<int>*root;
public:
    BST()
    {
        root=NULL;
    }
private:
    bool Searchhelper(int data,BinaryTreeNode<int>*node)
    {
        if(node==NULL)
        {
            return false;
        }
        if(node->data==data)
        {
            return true;
        }
        else if(node->data>data)
        {
            return Searchhelper(data,node->left);
        }
        else
        {
            return Searchhelper(data,node->right);
        }
    }
    BinaryTreeNode<int>* InsertHelper(BinaryTreeNode<int>* node,int data)
    {
        if(node==NULL)
        {
            BinaryTreeNode<int>* newnode=new BinaryTreeNode<int>(data);
            //node=newnode;
            newnode->left=NULL;
            newnode->right=NULL;
            //cout<<"datainserted"<<data<<endl;
            return newnode;
        }
        else if((node->data) >= data)
        {
            //cout<<"left recursion called for"<<data<<endl;
            node->left=InsertHelper(node->left,data);

        }
        else if(node->data < data)
        {
            //cout<<"right recursion called for"<<data<<endl;
            node->right=InsertHelper(node->right,data);
        }
        return node;

    }

    int maximum(BinaryTreeNode<int>* node)
    {
        if(node==NULL)
        {
            return INT_MIN;
        }
        return max(node->data,max(maximum(node->left),maximum(node->right)));

    }

    BinaryTreeNode<int>* DeleteHelper(BinaryTreeNode<int>*node,int data)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(data<node->data)
        {
            node->left=DeleteHelper(node->left,data);
        }
        else if(data>node->data)
        {
            node->right=DeleteHelper(node->right,data);
        }
        else if(node->data==data)
        {
            //cout<<"entered in condition 1"<<endl;
            if(!node->left && !node->right)
            {
                return NULL;
            }
            else if(!node->left || !node->right)
            {
                if(node->left)
                {
                    return node->left;
                }
                else
                {
                    return node->right;
                }
            }
            else if(node->right && node->left)
            {
                //cout<<"entered in nested condition"<<endl;
                int maxdat=maximum(node->left);
                node->data=maxdat;
                //cout<<maxdat<<endl;
                node->left=DeleteHelper(node->left,maxdat);
            }
        }
        return node;
    }
public:

    //BinaryTreeNode<int>*
    void Insert(int data)
    {
        root=InsertHelper(this->root,data);
        //cout<<endl;
        return ;//root;
    }
    void print()//BinaryTreeNode<int>* node)
    {
        BinaryTreeNode<int>::print_levelwise(root);
    }
    void Delete(int data)
    {
        root=DeleteHelper(root,data);
        return;

    }

    bool Search(int data)
    {
        return Searchhelper(data,root);

    }
};
