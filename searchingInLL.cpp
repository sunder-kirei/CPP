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

int searchLL(node* head, int x){
    node* tail = head;
    int pos = 1;
    while(tail != NULL){
        if(tail -> getData() == x){
            return pos-1;
        }
        tail = tail -> getNext();
        pos++;
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        node* head = takeInput();
        int x;
        cin>>x;
        cout<<searchLL(head,x)<<endl;
        node :: setSize(0);
    }
    return 0;
}