#include<iostream>
#include"Trie.h"
using namespace std;
int main()
{
    Trie t;
    t.insertWord("not");
    t.insertWord("note");
    t.insertWord("dot");
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("ans");
    cout<<t.search("and")<<endl;
    cout<<t.search("art")<<endl;
    cout<<t.search("ans")<<endl;
    t.remove("ans");
    cout<<t.search("ans")<<endl;

}
