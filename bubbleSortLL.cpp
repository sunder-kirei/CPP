#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }

    node()
    {
        this->data = 0;
        next = NULL;
    }
};

void takeInput(node *head)
{
    int data;
    cin >> data;

    if (data == -1)
    {
        return;
    }
    else
    {
        head->data = data;
    }
    cin >> data;
    while (data != -1)
    {
        node *newNode = new node(data);
        head->next = newNode;
        head = newNode;

        cin >> data;
    }

    return;
}

void printNode(node *head)
{
    while (head != NULL)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
    return;
}

node *swapNode(node *head)
{
    node *newHead = head->next;
    node *temp = (head->next)->next;
    (head->next)->next = head;
    head->next = temp;
    return newHead;
}

int llLength(node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }

    return length;
}

node *bubbleSort(node *head)
{   
    if(head == NULL){
        return head;
    }
    node *newHead = NULL;
    
    node *temp = NULL;
    int length = llLength(head);

    while (length --)
    {   
        node *prevNode = head -> next;
        newHead = NULL;
        while ((head->next) != NULL)
        {
            if (head->data > (head->next->data))
            {   
                temp = swapNode(head);
                if (newHead == NULL)
                {
                    newHead = temp;
                }
                else
                {
                    prevNode -> next = temp;
                    prevNode = temp;
                }
            }
            else
            {   
                if(newHead == NULL){
                    newHead = head;
                    prevNode = head;
                }
                prevNode = head;
                head = head->next;
            }
        }
        head -> next = NULL;
        head = newHead;
    }

    return head;
}

int main()
{
    int t;
    cin >> t;
    while (t--){
        node *head = new node;
        takeInput(head);
    
        head = bubbleSort(head);
    
        printNode(head);
    }
    return 0;
}