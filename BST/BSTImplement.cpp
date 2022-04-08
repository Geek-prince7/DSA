#include<iostream>
#include"BST.h"
using namespace std;
int main()
{
    BST obj;
    //BinaryTreeNode<int>*root=NULL;
    /*
    root=obj.Insert(5);
    root=obj.Insert(3);
    root=obj.Insert(7);
    root=obj.Insert(4);
    root=obj.Insert(1);
    root=obj.Insert(2);
    root=obj.Insert(6);
    root=obj.Insert(8);
    cout<<obj.Search(8)<<endl;


    cout<<obj.Search(5)<<endl;
    cout<<obj.Search(8)<<endl;
    cout<<obj.Search(1)<<endl;
    cout<<obj.Search(2)<<endl;
    BinaryTreeNode<int>::print_levelwise(root);
    */


    int choice;
    cin>>choice; //-1,0 for break,1 for insert,2 for search,3 to print tree
    while(choice)
    {
        if(choice==1)
        {
            cout<<"enter tree data : ";
            int d;
            cin>>d;
            obj.Insert(d);
        }


        else if(choice==2)
        {
            cout<<"enter data to delete : ";
            int d;
            cin>>d;
            obj.Delete(d);
            obj.print();
        }
                else if(choice==3)
        {
            cout<<"enter data to search : ";
            int d;
            cin>>d;
            cout<<obj.Search(d)<<endl;
        }
        else
        {
            //BinaryTreeNode<int>::print_levelwise(root);
            cout<<"printing tree"<<endl;
            obj.print();
        }
        cin>>choice;
    }
    //obj.print(root);

}
