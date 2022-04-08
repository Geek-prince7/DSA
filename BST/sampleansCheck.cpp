#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public:
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<climits>
class BST {
    // Define the data members
    BinaryTreeNode<int>*root;
   public:
    BST() {
        // Implement the Constructor
        this->root=NULL;
    }
    private:
    //search helper
    bool searchHelper(BinaryTreeNode<int>*node,int data)
    {
        if(node==NULL)
        {
            return false;
        }
        if(node->data==data)
        {
            return true;
        }
        else if(node->data>data)
        {
            return searchHelper(node->left,data);
        }
        else
        {
            return searchHelper(node->right,data);
        }
    }

    //print helper
    void print_recursive(BinaryTreeNode<int>* node)
    {
        if(node==NULL)
        {
            return;
        }
        cout<<node->data<<":";
        if(node->left)
        {
            cout<<"L:"<<node->left->data<<",";
        }
        if(node->right)
        {
            cout<<"R:"<<node->right->data;
        }
        cout<<endl;
        print_recursive(node->left);
        print_recursive(node->right);
        return;
    }
    BinaryTreeNode<int>* insertHelper(BinaryTreeNode<int>* node,int data)
    {
        if(node==NULL)
        {
            BinaryTreeNode<int>* newnode=new BinaryTreeNode<int>(data);
            //node=newnode;
            newnode->left=NULL;
            newnode->right=NULL;
            //cout<<"datainserted"<<data<<endl;
            return newnode;
        }
        else if((node->data) >= data)
        {
            //cout<<"left recursion called for"<<data<<endl;
            node->left=insertHelper(node->left,data);

        }
        else if(node->data < data)
        {
            //cout<<"right recursion called for"<<data<<endl;
            node->right=insertHelper(node->right,data);
        }
        return node;

    }

    int minimum(BinaryTreeNode<int>* node)
    {
        if(node==NULL)
        {
            return INT_MAX;
        }
        return min(node->data,min(minimum(node->left),minimum(node->right)));
    }
    BinaryTreeNode<int>* removeHelper(BinaryTreeNode<int>*node,int data)
    {
        if(node==NULL)
        {
            return NULL;
        }
        if(node->data>data)
        {
            node->left=removeHelper(node->left,data);
        }
        else if(node->data<data)
        {
            node->right=removeHelper(node->right,data);
        }
        else
        {
            if(!node->left && !node->right)
            {
                return NULL;
            }
            else if(!node->left || !node->right)
            {
                if(node->left)
                {
                    return node->left;
                }
                else
                {
                    return node->right;
                }
            }
            else
            {
                int mindata=minimum(node->left);
                node->data=mindata;
                node->right=removeHelper(node->right,mindata);
            }
        }
        return node;
    }
    public:


	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) {
        // Implement the remove() function
        root=removeHelper(root,data);
    }

    void print() {
        // Implement the print() function
        print_recursive(root);
    }

    void insert(int data) {
        // Implement the insert() function
        root=insertHelper(root,data);
        return;
    }

    bool search(int data) {
		// Implement the search() function
        return searchHelper(root,data);
    }

};






//#include "solution.h"

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}
