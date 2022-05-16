#include <iostream>
#include "nodeClass.cpp"
using namespace std;

node *takeInput(node *head = NULL)
{
    node *tail = head;
    int data;
    cin >> data;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            while (tail->getNext() != NULL)
            {
                tail = tail->getNext();
            }
            tail->setNext(newNode);
        }
        cin >> data;
    }
    return head;
}

void printNode(node *head)
{
    node *pos = head;
    while (pos != NULL)
    {
        cout << pos->getData() << ' ';
        pos = pos->getNext();
    }
    cout << endl;
    return;
}

node* midPoint(node* head){
    if(head == NULL) return head;

    node* slow = head;
    node* fast = head -> getNext();

    while(fast != NULL && fast -> getNext() != NULL){
        slow = slow -> getNext();
        fast = fast -> getNext() -> getNext();
    }

    return slow;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        node *head = takeInput();
        head -> printNode();
        cout<<midPoint(head) -> getData()<<endl;
    }
    return 0;
}