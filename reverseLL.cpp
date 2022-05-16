#include <iostream>
#include "nodeClass.cpp"
using namespace std;

node* takeInput(node* head = NULL){
    node* tail = head;
    int data;
    cin>>data;
    while(data != -1){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> setNext(newNode);
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

node* reverseLL(node* head){
    if(head == NULL) return NULL;
    if (head -> getNext() == NULL) return head;
    if((head -> getNext()) -> getNext() == NULL){
        head -> getNext() -> setNext(head);
        node* temp = head -> getNext();
        head -> setNext(NULL);
        return temp;
    }
    node* tail = reverseLL(head -> getNext());
    (head ->getNext()) -> setNext(head);
    head -> setNext(NULL);
    return tail;
}

void printNode(node* head){
    while(head != NULL){
        cout<<head -> getData()<<' ';
        head = head -> getNext();
    }
    cout<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        node* head = takeInput();
        head = reverseLL(head);
        printNode(head);
    }
    return 0;
}