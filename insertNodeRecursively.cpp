#include <iostream>
#include "nodeClass.cpp"
using namespace std;

node* insertNodeBetter(node*head, int idx, int data){
    if(idx == 0){
        node* newNode = new node(data);
        newNode -> setNext(head);
        return newNode;
    }
    node* temp = insertNodeBetter(head -> getNext(),idx-1,data);
    head -> setNext(temp);
    return head;
}

node* insertNode(node* head, node* current, int idx, int data){
    if(idx <= 1){
        node* newNode = new node(data);
        if(current == head){
            newNode -> setNext(current);
            return newNode;
        }
        else{
            newNode -> setNext(current->getNext());
            current -> setNext(newNode);
            return head;
        }
    }
    current = current -> getNext();
    return insertNode(head,current,idx-1,data);
}

node* takeInput(node *head = NULL){
    node *tail = head;
    int data;
    cin>>data;
    while(data != -1){
        node* newNode = new node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            while(tail -> getNext() != NULL){
                tail = tail -> getNext();
            }
            tail -> setNext(newNode);
        }
        cin>>data;
    }
    return head;
}

void printNode(node* head){
    node* pos = head;
    while(pos != NULL){
        cout<<pos -> getData()<<' ';
        pos = pos -> getNext();
    }
    cout<<endl;
    return;
}

void deleteNode(node *head){
    node* pos = head;
    while(pos != NULL){
        node* temp = pos;
        pos = pos -> getNext();
        delete temp;
    }
    return;
}

int main(){
    node* head = takeInput();
    int idx, data;
    cin>>idx>>data;
    //head = insertNode(head,head,idx,data);
    head = insertNodeBetter(head,idx,data);
    printNode(head);
    deleteNode(head);
    return 0;
}