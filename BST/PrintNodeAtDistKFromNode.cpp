#include<iostream>
#include<vector>
#include"BinaryTree.h"
using namespace std;
/*
vector<vector<int>*>* path(BinaryTreeNode<int>* root,int node)
{
    if(root==NULL)
    {
        return NULL;
    }
    vector<vector<int>*>* out=new vector<vector<int>*>();
    if(root->data==node)
    {
        vector<int>* ans=new vector<int>();
        ans->push_back(root->data);
        out->push_back(ans);
        return out;
    }
    vector<vector<int>*>* leftans=path(root->left,node);
    vector<vector<int>*>* rightans=path(root->right,node);
    if(leftans)
    {
        vector<int>*leftout=new vector<int>();
        leftout->push_back(root->data);
        leftout->push_back(0);
        leftans->push_back(leftout);
        return leftans;
    }
    if(rightans)
    {

        vector<int>*rightout=new vector<int>();
        rightout->push_back(root->data);
        rightout->push_back(1);
        rightans->push_back(rightout);
        return rightans;
    }
    return NULL;
}

BinaryTreeNode<int>* returnNode(BinaryTreeNode<int>* root,int node)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==node)
    {
        return root;
    }
    BinaryTreeNode<int>* leftans=returnNode(root->left,node);
    BinaryTreeNode<int>* rightans=returnNode(root->right,node);
    if(leftans)
    {
        return leftans;
    }
    if(rightans)
    {
        return rightans;
    }
    return NULL;
}
void printNodeAtDepthK(BinaryTreeNode<int>* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<" ";
    }
    printNodeAtDepthK(root->left,k-1);
    printNodeAtDepthK(root->right,k-1);
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    if(root==NULL)
    {
        return;
    }
    vector<vector<int>*>*ans=path(root,node);
    //cout<<ans->size();
    //cout<<ans->at(1)->size();
    BinaryTreeNode<int>* current=returnNode(root,node);
    printNodeAtDepthK(current,k);

    for(int i=1;i<ans->size();i++)
    {
        int dist=k-i-1;
        BinaryTreeNode<int>* temp=returnNode(root,ans->at(i)->at(0));
        if(dist==-1)
        {
            cout<<ans->at(i)->at(0);
        }
        else if(ans->at(i)->at(1)==0)
        {
            printNodeAtDepthK(temp->right,dist);
        }
        else
        {
            printNodeAtDepthK(temp->left,dist);
        }
    }



}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void printNodeAtDepthK(BinaryTreeNode<int>* root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        cout<<root->data<<endl;
        return;
    }
    printNodeAtDepthK(root->left,k-1);
    printNodeAtDepthK(root->right,k-1);
}





int Helper(BinaryTreeNode<int>* root,int node,int k)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==node)
    {
        printNodeAtDepthK(root,k);
        return 0;
    }
    int leftans=Helper(root->left,node,k);
    if(leftans!=-1)
    {
        if(leftans+1==k)
        {
            cout<<root->data<<endl;
        }
        else if(k>leftans+1)
        {
            printNodeAtDepthK(root->right,(k-leftans-2));
        }
        return 1+leftans;
    }
    int rightans=Helper(root->right,node,k);
    if(rightans!=-1)
    {
        if(rightans+1==k)
        {
            cout<<root->data<<endl;
        }
        else if(k>rightans+1)
        {
            printNodeAtDepthK(root->left,(k-rightans-2));
        }
        return 1+rightans;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    int index=Helper(root,node,k);
    return;
}


int main()
{
    BinaryTreeNode<int>* root=BinaryTreeNode<int>::takeinput_levelwise();
    cout<<"Enter node u are searching : ";
    int data;
    cin>>data;
    cout<<"Enter dist : ";
    int dist;
    cin>>dist;
    nodesAtDistanceK(root,data,dist);
}
