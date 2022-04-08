#include"TrieNode.h"
#include<string>
using namespace std;
class Trie
{
//public:

    TrieNode *root;
public:

    Trie()
    {
        root=new TrieNode('\0');
    }
    void insertWord(string word)
    {
        insertWordHelper(word,root);
        return;
    }
    bool search(string word) {
        // Write your code here
        return Helper(root,word);
    }
    void remove(string word)
    {
        removeHelper(root,word);
    }
private:
    void insertWordHelper(string word,TrieNode *root)
    {
        if(word.length()==0)
        {
            root->isTerminal=true;
            return;
        }
        char firstchar=word[0];
        int index=firstchar-'a';
        //word=word.substr(1);
        if(root->children[index]==NULL)
        {
            TrieNode *newnode=new TrieNode(firstchar);
            root->children[index]=newnode;
        }
        insertWordHelper(word.substr(1),root->children[index]);

        return;
    }

    bool Helper(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            if(root->isTerminal)
            {
                return true;
            }
            return false;
        }
        int c=word[0];
        int index=c-'a';
        if(root->children[index]==NULL)
        {
            return false;
        }
        bool ans=Helper(root->children[index],word.substr(1));
        return ans;

    }
    void removeHelper(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=false;
            return;
        }
        int ch=word[0];
        int index=ch-'a';
        if(root->children[index]==NULL)
        {
            return;
        }
        removeHelper(root->children[index],word.substr(1));
        bool hasChild=false;
        for(int i=0;i<26;i++)
        {
            if(root->children[index]->children[i]!=NULL)
            {
                hasChild=true;
                break;
            }
        }
        bool ans=hasChild || root->children[index]->isTerminal;
        if(!ans)
        {
            TrieNode *temp=root->children[index];
            root->children[index]=NULL;
            delete temp;
        }

        return;

    }

};
