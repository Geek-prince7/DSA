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




class custom
{
public:
    TreeNode<int>*maximum;
    TreeNode<int>*secondmax;
    custom()
    {
        this->maximum=NULL;
        this->secondmax=NULL;
    }
};


custom* helper(TreeNode<int> *root)
{
    custom *nodes=new custom();
    nodes->maximum=root;
    nodes->secondmax=NULL;
    for(int i=0;i<root->children.size();i++)
    {
        custom *ans=helper(root->children[i]);
        TreeNode<int>*temp=ans->maximum;
        if((nodes->maximum->data)<(ans->maximum->data))
        {
            temp=nodes->maximum;
            nodes->maximum=ans->maximum;
        }

        if(nodes->secondmax==NULL)
        {
            if(ans->secondmax->data >temp->data)
            {
                nodes->secondmax=ans->secondmax;
            }
            else
            {
                nodes->secondmax=temp;
            }
        }

        else
        {


            if(temp->data==nodes->maximum->data)
            {
                if(ans->secondmax->data > nodes->secondmax->data)
                {
                    nodes->secondmax=ans->secondmax;
                }
            }
            else
            {
                if(!(ans->secondmax)) //ans==NULL
                {
                    if(temp->data >nodes->secondmax->data)
                    {
                        nodes->secondmax=temp;
                    }

                }
                else
                {
                    if(temp->data >ans->secondmax->data)
                    {
                        if(temp->data >nodes->secondmax->data)
                        {
                            nodes->secondmax=temp;
                        }
                    }
                    else
                    {
                        if(ans->secondmax->data >nodes->secondmax->data)
                        {
                            nodes->secondmax=ans->secondmax;
                        }

                    }
                }
            }
        }




    }
    return nodes;
}
//second largest node
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
    {
        return NULL;
    }
    queue<TreeNode<int>*>q1;
    TreeNode<int>*maximum=root;
    TreeNode<int>*secmax=NULL;
    q1.push(root);
    while(!q1.empty())
    {
        TreeNode<int>*current=q1.front();
        q1.pop();
        if(maximum->data <current->data)
        {
            secmax=maximum;
            maximum=current;
        }
        if(secmax!=NULL &&secmax->data <current->data && maximum->data>current->data)
        {
            secmax=current;
        }
        else if(secmax==NULL && current->data <maximum->data)
        {
            secmax=current;
        }
        for(int i=0;i<current->children.size();i++)
        {
            q1.push(current->children[i]);
        }
    }
    return secmax;
}




int main()
{

    TreeNode<int>* root=takeinput_levelwise();
    print_level_wise(root);
    TreeNode<int> *secondlargest=getSecondLargestNode(root);
    cout<<"second largest node is :"<<secondlargest->data;


}

