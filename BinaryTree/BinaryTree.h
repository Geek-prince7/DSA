#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    static BinaryTreeNode<int>* takeinput_levelwise()
    {
        queue<BinaryTreeNode<int>*>q1;
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

    //take input recursive
    static BinaryTreeNode<int>* takeinput()
    {
        int data;
        cout<<"enter data :";
        cin>>data;
        if(data==-1)
        {
            return NULL;
        }
        BinaryTreeNode<int>*root=new BinaryTreeNode<int>(data);
        BinaryTreeNode<int>*left_child=takeinput();
        BinaryTreeNode<int>*right_child=takeinput();
        root->left=left_child;
        root->right=right_child;
        return root;
    }

    //print level wise
    static void print_levelwise(BinaryTreeNode<int> *root)
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
            cout<<endl;

        }
    }

    //print recursively
    static void print(BinaryTreeNode<int>* root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->data<<": ";
        if(root->left!=NULL)
        {
            cout<<"L - "<<root->left->data;
        }
        if(root->right!=NULL)
        {
            if(root->left!=NULL)
            {
                cout<<",";
            }
            cout<<"R - "<<root->right->data;
        }
        cout<<endl;
        print(root->left);
        print(root->right);


    }


    //nodes count
    static int count_nodes(BinaryTreeNode<int>*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left_count=count_nodes(root->left);
        int right_count=count_nodes(root->right);
        return 1+left_count+right_count;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
