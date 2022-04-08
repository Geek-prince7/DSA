#include<iostream>
#include"BinaryTree.h"
using namespace std;
class pairs{
public:
    int height;
    bool balance;
    pairs()
    {
        height=0;
        balance=true;
    }
};

pairs isBalanced(BinaryTreeNode<int>*root)
{
    pairs p1;
    if(root==NULL)
    {
        return p1;//value already initialized in default const
    }
    pairs ans_left=isBalanced(root->left);
    pairs ans_right=isBalanced(root->right);
    int heights=1+max(ans_left.height,ans_right.height);
    bool check;
    if(ans_left.balance==false ||ans_right.balance==false)
    {
        check=false;
    }
    else
    {
        if(abs(ans_left.height-ans_right.height)<=1)
        {
            check=true;
        }
        else
        {
            check=false;
        }
    }
    p1.height=heights;
    p1.balance=check;
    return p1;




}
bool isBalancedMain(BinaryTreeNode<int>*root)
{
    pairs p=isBalanced(root);
    return p.balance;
}


/*
int height(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
bool isBalanced(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return true;
    }
    bool ans_left=isBalanced(root->left);
    bool ans_right=isBalanced(root->right);
    int height_left=height(root->left);
    int height_right=height(root->right);
    if(abs(height_left-height_right)<=1)
    {
        return true;
    }
    return false;
}
*/

int main()
{
    BinaryTreeNode<int>*root=BinaryTreeNode<int>::takeinput_levelwise();
    cout<<"tree balance :"<<isBalancedMain(root);

}
