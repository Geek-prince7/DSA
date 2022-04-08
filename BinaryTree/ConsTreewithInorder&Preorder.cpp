#include <iostream>
#include <queue>
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

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

BinaryTreeNode<int>* helper(int *preorder,int prestart,int preend,int* inorder,int instart,int inend)
{
    if(prestart>preend)
    {
        return NULL;
    }
    if(prestart-preend==0)
    {
        BinaryTreeNode<int>*root=new BinaryTreeNode<int>(preorder[prestart]);
        return root;

    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(preorder[prestart]);
    int count=0;
    for(int i=instart;i<=inend;i++)
    {
        if(inorder[i]==preorder[prestart])
        {
            break;
        }
        count++;
    }
    //count--;

    BinaryTreeNode<int>*leftchild=helper(preorder,prestart+1,prestart+count,inorder,instart,instart+count-1);
    BinaryTreeNode<int>*rightchild=helper(preorder,prestart+count+1,preend,inorder,instart+count+1,inend);
    root->left=leftchild;
    root->right=rightchild;

    //cout<<preorder[count+1]<<endl;
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    BinaryTreeNode<int>*root=helper(preorder,0,preLength-1,inorder,0,inLength-1);
    return root;
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}
