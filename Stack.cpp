#include "Node.cpp"
template <typename T>

class Stack
{
    Node<T> *head;
    int size;

public:
    Stack()
    {
        this->head = NULL;
        this->size = 0;
    }

    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->nxtIdx = this->head;
        this->head = newNode;
        this->size++;
        return;
    }

    T pop()
    {
        if (!this->head)
            return 0;
        Node<T> *oldHead = this->head;
        this->head = this->head->nxtIdx;
        this->size--;
        T ans = oldHead->data;
        delete oldHead;
        return ans;
    }

    bool isEmpty()
    {
        return !this->size;
    }

    int getSize()
    {
        return this->size;
    }
    int top()
    {
        if (head == NULL)
            return 0;
        return head->data;
    }
};
