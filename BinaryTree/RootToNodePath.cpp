#include<iostream>
#include<vector>
#include"BinaryTree.h"
using namespace std;
vector<int>* path(BinaryTreeNode<int>*root,int k)
{
    //vector<int>*v=NULL;
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==k)
    {
        vector<int>*v=new vector<int>();
        v->push_back(root->data);
        return v;
    }
    vector<int>* leftv=path(root->left,k);
    if(leftv!=NULL)
    {
        leftv->push_back(root->data);
        return leftv;

    }
    vector<int>* rightv=path(root->right,k);
    if(rightv)
    {
        rightv->push_back(root->data);
        return rightv;

    }
    return NULL;


}
int main()
{
    BinaryTreeNode<int>*root=BinaryTreeNode<int>::takeinput_levelwise();
    int k;
    cout<<"enter val u wanna find : ";
    cin>>k;
    vector<int>* ans=path(root,k);
    //cout<<ans->size();
    for(int i=0;i<ans->size();i++)
    {
        cout<<ans->at(i)<<" ";
    }
    delete ans;



}
