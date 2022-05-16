#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;

        node(int data){
            this -> data = data;
            next = NULL;
            prev = NULL;
        }

        node(){
            this -> data = 0;
            next = NULL;
            prev = NULL;
        }
};

node* takeInput(node* head){
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    else{
        head->data = data;
    }
    cin>>data;
    while(data != -1){
        node* newNode = new node(data);
        head -> next = newNode;
        newNode -> prev = head;
        head = newNode;
        cin>>data;
    }
    return head;
}

void printNodeHead(node* head){
    while(head != NULL){
        cout<<head->data<<' ';
        head = head -> next;
    }
    cout<<endl;
    return;
}

void printNodeTail(node *tail){
    while(tail != NULL){
        cout<<tail->data<<' ';
        tail = tail -> prev;
    }
    cout<<endl;
    return;
}

int main(){
    node* head = new node;
    node*tail = takeInput(head);

    printNodeHead(head);
    printNodeTail(tail);

    return 0;
}