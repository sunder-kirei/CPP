#include <iostream>
#include "nodeClass.cpp"
using namespace std;

node* reverseLL(node *head){
    node* previous = NULL;
    node* next;
    while(head != NULL){
        next = head -> getNext();
        head -> setNext(previous);
        previous = head;
        head = next;
    }
    return previous;
}

int main(){
    node* head = new node;
    head -> takeInput();

    head -> printNode();
    head = reverseLL(head);

    head -> printNode();
    return 0;
}