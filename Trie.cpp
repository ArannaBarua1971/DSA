#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertCh(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode *child;
        cout<<word[0]<<endl;

        // present char
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // absent char
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertCh(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertCh(root, word);
    }

    bool searchCh(TrieNode *root, string word)
    {

        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode *child;
        // present;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            return searchCh(child, word.substr(1));
        }
        else
        {
            // absent
            return false;
        }
    }

    void searchWord(string word)
    {
        bool status=searchCh(root,word);
        cout<<status<<endl;
    }
};

int main()
{
    Trie *t = new Trie();

    t->insertWord("ABCDE");
    t->searchWord("ABCD");


    return 0;
}
