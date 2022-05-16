#include <iostream>
#include "nodeClass.cpp"
using namespace std;

class headTail{
    node* head;
    node* tail;

    public:
        node* getHead(){
            return head;
        }

        node* getTail(){
            return tail;
        }
};

node* reverseLL(node* head){
    if(head == NULL)
        return head;
    if((head -> getNext())== NULL){
        return head;
    }

    node* newHead = reverseLL(head -> getNext());
    (head -> getNext()) -> setNext(head);
    head -> setNext(NULL);
    return newHead;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        node* head = new node;
        head -> takeInput();
        head = reverseLL(head);
        head ->printNode();
    }
    return 0;
}