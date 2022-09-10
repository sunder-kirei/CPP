#include <iostream>
template <typename T>

class Node
{
public:
    T data;
    Node *nxtIdx;

    Node(T data)
    {
        this->data = data;
        this->nxtIdx = NULL;
    }
};