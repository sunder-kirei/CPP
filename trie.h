#include "trie_node.h"
#include <iostream>
#include <string>
using namespace std;

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        this->root = new TrieNode('\0');
    }

private:
    void insert(string data, TrieNode *root)
    {
        if (data.empty())
        {
            root->setIsTerminal();
            return;
        }
        const int childIndex = 'a' - data[0];
        if (root->children[childIndex] == NULL)
        {
            root->children[childIndex] = new TrieNode(data[0]);
        }

        return insert(data.substr(1), root->children[childIndex]);
    }

    bool search(string data, TrieNode *root)
    {
        if (data.empty())
        {
            return root->isTerminal;
        }

        TrieNode *child = root->children['a' - data[0]];
        if (child == NULL)
            return false;

        return search(data.substr(1), child);
    }

    void remove(string data, TrieNode *root)
    {
        if (data.empty())
        {
            root->isTerminal = false;
            return;
        }

        TrieNode *child = root->children['a' - data[0]];
        if (child == NULL)
            return;

        return remove(data.substr(1), child);
    }

public:
    void insert(string data)
    {
        return insert(data, this->root);
    }

    bool search(string data)
    {
        return search(data, this->root);
    }

    void remove(string data)
    {
        return remove(data, this->root);
    }
};