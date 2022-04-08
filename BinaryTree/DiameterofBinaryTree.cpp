#include<iostream>
#include"BinaryTree.h"
using namespace std;

class pairs
{
public:
    int h;
    int d;
    pairs()
    {
        h=0;
        d=0;
    }
};

int height(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}


pairs * diameterHelper(BinaryTreeNode<int> *root)
{
    pairs *node=new pairs();
    if(root==NULL)
    {
        node->h=0;
        node->d=0;
        return node;
    }
    pairs *option1=diameterHelper(root->left);
    pairs *option2=diameterHelper(root->right);
    option1->h=height(root->left);
    option2->h=height(root->right);
    node->d=max((option1->h+option2->h),max(option1->d,option2->d));
    node->h=max(option1->h,option2->h);
    return node;
}

int diameter(BinaryTreeNode<int>* root)
{
    pairs* ans=diameterHelper(root);
    return ans->d;
}



int main()
{
    BinaryTreeNode<int>*root=BinaryTreeNode<int>::takeinput_levelwise();
    BinaryTreeNode<int>::print_levelwise(root);
    cout<<"diameter is  : "<<diameter(root);
    return 0;
}
