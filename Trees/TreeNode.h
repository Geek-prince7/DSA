#include<vector>
using namespace std;

template<typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode*> children;
    TreeNode(T data)
    {
        this->data=data;
    }
     static void print(TreeNode<T> *root)
    {

        if(root==NULL)
        {
            return;
        }

        cout<<root->data<<":";
        for(int i=0;i<root->children.size();i++)
        {
            cout<<root->children[i]->data<<", ";
        }
        cout<<endl;
        for(int i=0;i<root->children.size();i++)
        {

            print(root->children.at(i));
        }
        //cout<<root->data<<endl;
    }
};
