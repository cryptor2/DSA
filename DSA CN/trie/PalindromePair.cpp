#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    string add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return "" + root->data;
            }
            else
            {
                return "";
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1)) + word[0];
    }

    void add(string word, vector<string> palindrome)
    {
        string ans = add(root, word);
        palindrome.push_back(ans);
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
    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words)
    {
        // Write your code here
        vector<string> palindrome;
        for (int i = 0; i < palindrome.size(); i++)
        {
            add(words[i], palindrome);
         
        }

        for (int i = 0; i < palindrome.size(); i++)
        {
            cout << palindrome[i];
        }
        
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}