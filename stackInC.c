#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nxt;
};

struct Node *head = NULL;
int size = 0;

void push(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->nxt = head;

    head = newNode;
    size++;
    return;
}

int top()
{
    if (head == NULL)
        return 0;

    return head->data;
}

int pop()
{
    if (head == NULL)
        return 0;
    int ans = head->data;
    struct Node *oldHead = head;
    head = head->nxt;
    free(oldHead);
    size--;
    return ans;
}

int getSize()
{
    return size;
}

bool isEmpty()
{
    return !size;
}

int main()
{
    push(1);
    push(2);
    push(3);

    printf("%d\n", getSize());
    printf("%d\n", isEmpty());

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}