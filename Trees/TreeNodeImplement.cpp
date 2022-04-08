#include<iostream>
#include<queue>
#include"TreeNode.h"
using namespace std;


//for taking input level wise
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

//printing node level wise
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

//count total nodes in tree
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


//to find the height of tree
int heightTree(TreeNode<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int height=0;
    for(int i=0;i<root->children.size();i++)
    {
        int ans=heightTree(root->children[i]);
        if(height<ans)
        {
            height=ans;
        }
    }
    return 1+height;
}


//print node at depth k
void depthNode(TreeNode<int>* root,int k)
{
    if(k==0)
    {
        cout<<root->data<<",";
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        depthNode(root->children[i],k-1);
    }
}



//count total leaf nodes
int countLeafNodes(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return 0;
    }
    //int count=0;
    //int ans=0;
    int count=0;
    if(root->children.size()!=0)
    {
        for(int i=0;i<root->children.size();i++)
        {
            int ans=countLeafNodes(root->children[i]);
            count+=ans;
        }
    }
    else{
        return 1+count;
    }
    return count;
}


//main function

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
    print_level_wise(root);
    cout<<"Total nodes are : "<<count_nodes(root)<<endl;
    cout<<"height of tree is : "<<heightTree(root)<<endl;
    int k;
    cout<<"Enter depth : ";
    cin>>k;
    depthNode(root,k);
    cout<<"\n total leaf nodes are : "<<countLeafNodes(root)<<endl;


}
