#include<iostream>
#include"BinaryTree.h"
#include<climits>
using namespace std;

/*
int maximum(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    int left_ans=maximum(root->left);
    int right_ans=maximum(root->right);
    return max(root->data,max(left_ans,right_ans));
}

int minimum(BinaryTreeNode<int>*root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    int left_ans=minimum(root->left);
    int right_ans=minimum(root->right);
    return min(root->data,min(left_ans,right_ans));
}

*/

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	pair<int, int> p1;
	if(root==NULL)
    {
        p1.first=INT_MAX;
        p1.second=INT_MIN;
        return p1;
    }
    p1.first=root->data;
    p1.second=root->data;
    pair<int,int>left_ans=getMinAndMax(root->left);
    pair<int,int>right_ans=getMinAndMax(root->right);
    int left_max=left_ans.second;
    int left_min=left_ans.first;
    int right_max=right_ans.second;
    int right_min=right_ans.first;

    int maxi=max(p1.second,max(left_max,right_max));
    int mini=min(p1.first,min(left_min,right_min));
    p1.first=mini;
    p1.second=maxi;
    return p1;


}
int main() {
    BinaryTreeNode<int>* root = BinaryTreeNode<int>::takeinput_levelwise();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
    //cout<<"maximum is : "<<maximum(root)<<endl;
    //cout<<"minimum is : "<<minimum(root)<<endl;

}
