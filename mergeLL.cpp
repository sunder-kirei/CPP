#include <iostream>
#include "nodeClass.cpp"
using namespace std;

node* mergeLL(node* head, node* head2){
    node* finalHead;
    node* finalTail;
    if(head -> getData() <= head2 -> getData()){
        finalHead = head;
        finalTail = head;
        head = head -> getNext();
    }
    else{
        finalHead = head2;
        finalTail = head2;
        head2 = head2 -> getNext();
    }

    while(head != NULL && head2 != NULL){
        if(head -> getData() <= head2 -> getData()){
            finalTail -> setNext(head);
            finalTail = head;
            head = head -> getNext();
        }
        else{
            finalTail -> setNext(head2);
            finalTail = head2;
            head2 = head2 -> getNext();
        }
    }
    if(head2 == NULL){
        finalTail -> setNext(head);
    }
    else{
        finalTail -> setNext(head2);
    }
    return finalHead;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        node *head = new node;
        head->takeInput();
        node* head2 = new node;
        head2->takeInput();
        node* newHead = mergeLL(head,head2);
        newHead -> printNode();
    }
    return 0;
}