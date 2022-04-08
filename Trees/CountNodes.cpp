#include<iostream>
#include"TreeNode.h"
using namespace std;


int count_nodes(TreeNode<int> *root)
{
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
int main()
{
    //make a tree give input
}
