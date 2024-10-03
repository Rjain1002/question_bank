#include <bits/stdc++.h>
using namespace std;

struct trienode
{
    struct trienode *child[26];
    bool isEnd;
};

trienode *getnode(void) // creation of the root node from where trie starts
{
    trienode *node = new trienode;
    for (int i = 0; i < 26; i++)
    {
        node->child[i] = NULL;
    }
    node->isEnd = false;
    return node;
}

void insertnode(trienode *root, string str)
{
    trienode *node = root;
    for (int i = 0; i < str.size(); i++)
    {
        int ch = str[i] - 'a';
        if (node->child[ch] == NULL)
        {
            node->child[ch] = getnode();
        }
        node = node->child[ch];
    }
    node->isEnd = true;
}

bool search(trienode *root, string str)
{
    trienode *node = root;
    for (int i = 0; i < str.size(); i++)
    {
        int ch = str[i] - 'a';
        if (node->child[ch] == NULL)
            return false;
        node = node->child[ch];
    }
    return (node->isEnd && node != NULL);
}
int main()
{
    trienode *root = getnode();
    insertnode(root, "abc");
    insertnode(root, "abcd");
    insertnode(root, "abce");
    insertnode(root, "abcf");
    // printing all words from trie using for loop
    cout << "success" << endl;
    cout << search(root, "abcf") << endl;
    cout << "success" << endl;
    cout << search(root, "hbb") << endl;
    cout << search(root, "abc") << endl;
    cout << search(root, "abce") << endl;
}
