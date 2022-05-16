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

void removeDuplicates(node* head){
    if (head -> getNext() == NULL || head == NULL){
        return;
    }
    if(head -> getData() == (head -> getNext()) -> getData()){
        node* temp = head -> getNext();
        head -> setNext((head -> getNext()) -> getNext());
        delete temp;
        return removeDuplicates(head);
    }
    else{
        return removeDuplicates(head -> getNext());
    }
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
        removeDuplicates(head);
        printNode(head);
    }
    return 0;
}