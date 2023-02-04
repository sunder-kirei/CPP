#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *nxt;

    node(int data)
    {
        this->data = data;
        this->nxt = NULL;
    }
};
class queue
{
    node *head;
    node *tail;
    int size;

public:
    queue()
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    void enqueue(int data)
    {
        node *newNode = new node(data);
        size++;
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->nxt = newNode;
        tail = newNode;
        return;
    }

    int dequeue()
    {
        if (head == NULL)
            return 0;

        if (head == tail)
            tail = NULL;
        node *oldHead = head;
        int ans = head->data;

        head = head->nxt;
        delete (oldHead);
        size--;
        return ans;
    }

    int front()
    {
        if (head == NULL)
            return 0;

        return head->data;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return !size;
    }
};