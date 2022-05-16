#include <iostream>
#include "nodeClass.cpp"
using namespace std;

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

void deleteNode(node *head){
    node* pos = head;
    while(pos != NULL){
        node* temp = pos;
        pos = pos -> getNext();
        delete temp;
    }
    return;
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

int getNode(node*head, int idx){
    node* temp = head;
    while(idx--){
        temp = temp ->getNext();
    }
    return temp -> getData();
}

int main(){
    int t;
    cin>>t;
    while(t--){
        node* head = takeInput();
        int idx;
        cin>>idx;
        if(idx >= node ::getSize()){
            return 0;
        }
        else{
            cout<<getNode(head,idx)<<endl;
        }
    }
    return 0;
}