#include<iostream>
#include"BinaryTree.h"
#include<queue>
using namespace std;
/*
BinaryTreeNode<int>* takeinput()
{
    int data;
    cout<<"enter data :";
    cin>>data;
    if(data==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(data);
    int i=0;
    while(i<2)
    {
        BinaryTreeNode<int>*node=takeinput();
        if(i==0)
        {
            root->left=node;
        }
        else
        {
            root->right=node;
        }
        //takeinput();
        i++;


    }
    return root;
}

void print(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<": ";
    if(root->left!=NULL)
    {
        cout<<root->left->data;
    }
    if(root->right!=NULL)
    {
        if(root->left!=NULL)
        {
            cout<<",";
        }
        cout<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);


}

BinaryTreeNode<int>* takeinput_levelwise()
    {
        queue<BinaryTreeNode<int>*> q1;
        int data;
        cout<<"Enter root data : ";
        cin>>data;
        if(data==-1)
        {
            return NULL;
        }
        BinaryTreeNode<int>*root=new BinaryTreeNode<int>(data);
        q1.push(root);
        while(!q1.empty())
        {
            BinaryTreeNode<int>* current=q1.front();
            q1.pop();
            cout<<"enter left node of "<<current->data<<" :";
            cin>>data;
            if(data==-1)
            {
                current->left=NULL;
            }
            else
            {
                BinaryTreeNode<int>*leftnode=new BinaryTreeNode<int>(data);
                current->left=leftnode;
                q1.push(leftnode);
            }

            cout<<"enter right node of "<<current->data<<" :";
            cin>>data;
            if(data==-1)
            {
                current->right=NULL;
            }
            else
            {
                BinaryTreeNode<int>*rightnode=new BinaryTreeNode<int>(data);
                current->right=rightnode;
                q1.push(rightnode);
            }
            //cout<<endl;
        }
        return root;
    }



    void print(BinaryTreeNode<int> *root)
    {
        if(root==NULL)
        {
            return;
        }
        queue<BinaryTreeNode<int>*> q1;
        q1.push(root);
        while(!q1.empty())
        {
            BinaryTreeNode<int>*current=q1.front();
            q1.pop();
            cout<<current->data<<" : ";
            if(current->left!=NULL)
            {
                cout<<"L - "<<current->left->data;
                q1.push(current->left);
            }
            if(current->right!=NULL)
            {
                if(current->left!=NULL)
                {
                    cout<<" ";
                }
                cout<<"R - "<<current->right->data;
                q1.push(current->right);
            }
            //cout<<endl;

        }
    }


int count_nodes(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left_count=count_nodes(root->left);
    int right_count=count_nodes(root->right);
    return 1+left_count+right_count;
}
*/

int main()
{
    BinaryTreeNode<int>*root=BinaryTreeNode<int>::takeinput_levelwise();
    BinaryTreeNode<int>::print_levelwise(root);
    cout<<endl<<"total nodes are :"<<BinaryTreeNode<int>::count_nodes(root);
}
