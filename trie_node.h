#include <iostream>
using namespace std;

class TrieNode
{
    char data;

public:
    bool isTerminal;
    TrieNode **children;

    TrieNode(char data)
    {
        this->data = data;
        isTerminal = false;
        children = new TrieNode *[26];

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }

    void setIsTerminal()
    {
        this->isTerminal = true;
    }
};