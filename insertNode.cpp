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

node* deleteAtIdx(node* head, int idx){
    if(idx >= node ::getSize()){
        return head;
    }
    node* temp = head;
    if(idx == 0){
        head = head -> getNext();
        delete temp;
    }
    else{
        while(idx > 1){
            temp = temp -> getNext();
            idx--;
        }
        node* temp2 = temp -> getNext();
        temp -> setNext(temp2 -> getNext());
        delete temp2;
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

node* insertNode(node* head, int idx, int data){
    if(idx > node :: getSize()){
        return head;
    }
    node* pos = head;
    node*newNode = new node(data);
    if(idx == 0){
        head = newNode;
        head -> setNext(pos);
    }
    else{
        while(idx>1){
            pos = pos ->getNext();
            idx--;
        }
        newNode -> setNext(pos ->getNext());
        pos -> setNext(newNode);
    }
    return head;
}

int main(){
    int t;
    cin>>t;

    while (t--){
        node *head = takeInput();
        int idx;
        cin >> idx;
        // int idx, data;
        // cin>>idx>>data;
        // head = insertNode(head,idx,data);
        // printNode(head);
        head = deleteAtIdx(head, idx);
        printNode(head);
        node :: setSize(0);
        deleteNode(head);
    }
    return 0;
}