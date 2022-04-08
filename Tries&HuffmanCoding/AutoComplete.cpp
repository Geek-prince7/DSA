#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

   void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i=0;i<input.size();i++)
        {
            insertWord(input[i]);
        }
        string out="";
        //print(root,pattern,out);
        TrieNode *node=getNode(root,pattern);
        if(!node)
        {
            return;
        }
        printWord(node,pattern,out);
    }
    void printWord(TrieNode* root,string word,string out)
    {
        if(root->isTerminal)
        {
            cout<<(word+out)<<endl;
        }
        for(int i=0;i<26;i++)
        {
            if(root->children[i]!=NULL)
            {
                char c=i+'a';
                //out=out+c;
                printWord(root->children[i],word,out+c);
            }
        }
        return;

    }

    TrieNode* getNode(TrieNode* root,string word)
    {
        if(word.size()==0)
        {
            return root;
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL)
        {
            return NULL;
        }
        return getNode(root->children[index],word.substr(1));
    }

    /*
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i=0;i<input.size();i++)
        {
            insertWord(input[i]);
        }
        string out="";
        print(root,pattern,out);
    }
    void print(TrieNode *root,string word,string out)
    {
        if(word.size()==0)
        {
            //TrieNode *child=NULL;
            if(root->isTerminal)
            {
                cout<<out<<endl;
            }
            for(int i=0;i<26;i++)
            {
                if(root->children[i]!=NULL)
                {
                    char c=i+'a';
                    out=out+c;
                    print(root->children[i],word,out);
                }
            }

            return;

        }
        int index=word[0]-'a';
        if(root->children[index]==NULL)
        {
            return;
        }
        if(root->isTerminal)
        {
            cout<<out<<endl;
        }
        out=out+word[0];
        print(root->children[index],word.substr(1),out);
    }
    */
};


int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}
