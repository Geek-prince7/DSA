#include<iostream>
#include<queue>
#include"TreeNode.h"
using namespace std;
TreeNode<int>* takeinput_levelwise()
{
    queue<TreeNode<int> *> q;
    int data;
    cout<<"enter data :";
    cin>>data;
    TreeNode<int> *root=new TreeNode<int>(data);
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int> *node=q.front();
        q.pop();
        cout<<"enter no of childrens of "<<node->data<<" : ";
        int no;
        cin>>no;
        while(no--)
        {
            cout<<"enter data :";
            cin>>data;
            TreeNode<int> *child=new TreeNode<int>(data);
            node->children.push_back(child);
            q.push(child);

        }


    }
    return root;

}
void print_level_wise(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int> *node=q.front();
        q.pop();
        int child_count=node->children.size();
        cout<<node->data<<" :";
        int i=0;
        while(i<child_count)
        {
            TreeNode<int> *temp=node->children[i];
            q.push(temp);
            cout<<node->children[i]->data;
            if(i<child_count-1)
            {
                cout<<",";
            }
            i++;
        }
        cout<<endl;
    }
}
int count_nodes(TreeNode<int> *root)
{
    //this is an edge case not a base case
    if(root==NULL)
    {
        return 0;
    }
    //int count=1;
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=count_nodes(root->children[i]);
    }
    return ans;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
    {
        return NULL;
    }
    TreeNode<int>*maxnode=root;

    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int> *ans=maxDataNode(root->children[i]);
        if(ans->data>maxnode->data)
        {
            maxnode=ans;
        }
    }
    return maxnode;

}
int main()
{
    /*
    TreeNode<int> *root=new TreeNode<int>(10);
    TreeNode<int> *node1=new TreeNode<int>(20);
    TreeNode<int> *node2=new TreeNode<int>(30);
    root->children.push_back(node1);
    root->children.push_back(node2);
    //cout<<root->children.at(1)->data;
    */
    TreeNode<int>* root=takeinput_levelwise();
    TreeNode<int>* maxnode=maxDataNode(root);
    cout<<"max node is : "<<maxnode->data;
}
