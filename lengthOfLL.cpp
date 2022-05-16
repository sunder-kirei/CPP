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

int length(node* pos, int len){
    if(pos == NULL){
        return len;
    }
    pos = pos ->getNext();
    len++;
    return length(pos,len);
}

int main(){
    node* head = takeInput();
    cout<<length(head,0)<<endl;
    return 0;
}