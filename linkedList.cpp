#include <iostream>
using namespace std;
#include "nodeClass.cpp"

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
            // tail -> setNext(newNode);
            // tail = newNode;
            while(tail -> getNext() != NULL){
                tail = tail -> getNext();
            }
            tail -> setNext(newNode);
        }
        cin >> data;
    }
    return head;
}

void printNode(node *head){
    node *tail = head;
    while(tail != NULL){
        cout << tail->getData() << endl;
        tail = tail->getNext();
    }
    return;
}

void deleteNode(node *head){
    node *tail = head;
    while(tail != NULL){
        node* tail2 = tail ->getNext();
        delete tail;
        tail = tail2;
    }
    return;
}

int main(){
    node* head = takeInput();
    //takeInput(head);
    printNode(head);
    cout<<node :: getSize()<<endl;
    deleteNode(head);
    return 0;
}