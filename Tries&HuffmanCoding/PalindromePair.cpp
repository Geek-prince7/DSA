#include <bits/stdc++.h>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        for(int i=0;i<words.size();i++)
        {
            add(words[i]);
            //cout<<words[i]<<" added"<<endl;

        }
        for(int i=0;i<words.size();i++)
        {
            string rev=getReverse(words[i]);
            //cout<<"rev of word "<<words[i]<<" is :"<<rev<<endl;
            bool ans=search(root,rev);
            if(ans)
            {
                return true;
            }
        }
        return false;


    }
    string getReverse(string word)
    {
        int i=0;
        int j=word.size()-1;
        string out=word;
        while(i<j)
        {
            char c=out[i];
            out[i]=out[j];
            out[j]=c;
            i++;
            j--;
        }
        return out;
    }
    bool search(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            return true;
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL)
        {
            if(word.size()==1)
            {
                for(int i=0;i<26;i++)
                {
                    if(root->children[i]!=NULL)
                    {
                        return false;
                    }
                }
                return true;
            }
            //cout<<"root's no child"<<endl;
            return false;
        }
        return search(root->children[index],word.substr(1));
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}
