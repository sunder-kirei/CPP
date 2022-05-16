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

node* appendN(node* head, int n){
    int si = (node :: getSize()) - n;
    node* endNode = head;
    node* tail = head;
    while(tail -> getNext() != NULL){
        if(si == 1){
            head = tail -> getNext();
            tail -> setNext(NULL);
            tail = head -> getNext();
        }
        else{
            tail = tail -> getNext();
        }
        si--;
    }
    tail -> setNext(endNode);
    return head;
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
        int n;
        cin>>n;
        head = appendN(head,n);
        printNode(head);
        node :: setSize(0);
    }
    return 0;
}