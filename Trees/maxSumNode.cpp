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


//maxSum node

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Edge case
    if(root==NULL)
    {
        return NULL;
    }
    TreeNode<int>*maxnode=root;
    int maxsum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        maxsum+=root->children[i]->data;
    }
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int> *ans=maxSumNode(root->children[i]);
        int ans_sum=ans->data;
        for(int j=0;j<ans->children.size();j++)
        {
            ans_sum+=ans->children[j]->data;
        }
        if(ans_sum>maxsum)
        {
            maxnode=ans;
        }
    }
    return maxnode;
}



int main()
{

    TreeNode<int>* root=takeinput_levelwise();
    print_level_wise(root);
    TreeNode<int> *maxNode=maxSumNode(root);
    cout<<"max data node incl children is :"<<maxNode->data;


}
