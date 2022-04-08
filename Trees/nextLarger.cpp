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


//nextlarger node
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x)
{
    TreeNode<int> *node=NULL;
    if(root->data >x)
    {
        node=root;
    }
    for(int i=0;i<root->children.size();i++)
    {
        TreeNode<int> *ans=getNextLargerElement(root->children[i],x);
        if(ans!=NULL)
        {
            if(node!=NULL)
            {
                if(ans->data<node->data)
                {
                    node=ans;
                }

            }
            else
            {
                node=ans;
            }
        }



    }
    return node;


    /*
    TreeNode<int> *ans=NULL;
    for(int i=0;i<root->children.size();i++)
    {
        ans=getNextLargerElement(root->children[i],x);

    }
    TreeNode<int>*node=NULL;
    if(root->data>x)
    {
        node=root;
    }
    return node;

    */

}




int main()
{

    TreeNode<int>* root=takeinput_levelwise();
    print_level_wise(root);
    int k;
    cout<<"enter no : ";
    cin>>k;
    TreeNode<int> *nextlarger=getNextLargerElement(root,k);
    cout<<"next larger node is :"<<nextlarger->data;


}

