#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // small calc
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[index]);
        }
        insert(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insert(root, word);
    }

    bool searchWord(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {

            if (root->isTerminal)
                return true;
            else
                return false;
        }
        int index = word[0] - 'a';
        if (root->children[index] == NULL)
        {
            return false;
        }
        else
        {
            TrieNode *child = root->children[index];
            bool ans = searchWord(child, word.substr(1));
            return ans;
        }
    }
    bool search(string word)
    {
        // Write your code here
        return searchWord(root, word);
    }

    void remove(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // not found
            return;
        }
        remove(child, word.substr(1));

        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                    return;
            }
        }
        delete child;
        root->children[index] = NULL;
    }
};

int main()
{
    int choice;
    cin >> choice;
    Trie t;

    while (choice != -1)
    {
        string word;
        bool ans;
        switch (choice)
        {
        case 1: // insert
            cin >> word;
            t.insertWord(word);
            break;
        case 2: // search
            cin >> word;
            cout << (t.search(word) ? "true\n" : "false\n");
            break;
        default:
            return 0;
        }
        cin >> choice;
    }

    return 0;
}