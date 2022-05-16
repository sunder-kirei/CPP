#include <iostream>
#include "nodeClass.cpp"
using namespace std;

node* deleteNode(node* head, int idx){
    if(idx == 0){
        node* temp = head;
        head = head -> getNext();
        delete temp;
        return head;
    }
    node* temp = deleteNode(head -> getNext(), idx-1);
    head ->setNext(temp);
    return head;
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

int main(){
    int t;
    cin>>t;
    while (t--){
        node *head = takeInput();
        int idx;
        cin >> idx;
        head = deleteNode(head, idx);
        printNode(head);
    }
    return 0;
}