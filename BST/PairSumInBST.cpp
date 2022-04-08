#include<iostream>
#include"BinaryTree.h"
#include<stack>
using namespace std;

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    stack<BinaryTreeNode<int>*> in,rev_in;
    BinaryTreeNode<int>* current=root;
    while(current)
    {
        in.push(current);
        //cout<<current->data<<" ";
        current=current->left;
    }
    cout<<endl;
    current=root;
    while(current)
    {
        rev_in.push(current);
        //cout<<current->data<<" ";
        current=current->right;
    }
    int i=0;
    int n=BinaryTreeNode<int>::count_nodes(root);

    while(i<n)
    {
        BinaryTreeNode<int>* temp1=in.top();
        BinaryTreeNode<int>* temp2=rev_in.top();


        if(temp1->data+temp2->data>s)
        {

            i++;
            rev_in.pop();
            if(temp2->left)
            {
                BinaryTreeNode<int>* ptr=temp2->left;
                while(ptr)
                {

                    rev_in.push(ptr);
                    //cout<<"stack2 push :"<<ptr->data<<endl;
                    ptr=ptr->right;
                }
            }
        }



        else if(temp1->data+temp2->data<s)
        {

            i++;
            in.pop();
            if(temp1->right)
            {
                BinaryTreeNode<int>* ptr=temp1->right;
                while(ptr)
                {
                    in.push(ptr);
                    //cout<<"stack1 push :"<<ptr->data<<endl;
                    ptr=ptr->left;
                }
            }
        }
        else
        {
            i+=2;
            if(i<=n)
            {
                cout<<temp1->data<<" "<<temp2->data<<endl;
            }
            in.pop();
            if(temp1->right)
            {
                BinaryTreeNode<int>* ptr=temp1->right;
                while(ptr)
                {
                    in.push(ptr);
                    //cout<<"stack1 push in eq :"<<ptr->data<<endl;
                    ptr=ptr->left;
                }
            }
            rev_in.pop();
            if(temp2->left)
            {
                BinaryTreeNode<int>* ptr=temp2->left;
                while(ptr)
                {
                    rev_in.push(ptr);
                    //cout<<"stack2 push in eq :"<<ptr->data<<endl;
                    ptr=ptr->right;
                }
            }

        }

    }

}
int main()
{
    BinaryTreeNode<int>* root=BinaryTreeNode<int>::takeinput_levelwise();
    int sum;
    cout<<"enter sum : ";
    cin>>sum;
    printNodesSumToS(root,sum);
}
