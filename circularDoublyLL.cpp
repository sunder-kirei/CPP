#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;
        
        node(int data){
            this->data = data;
            next = this;
            prev = this;
        }

        node(){
            data = 0;
            next = this;
            prev = this;
        }
};

node* takeInput(node* head){
    node* permaHead = head;
    int data;
    cin >> data;
    if(data == -1){
        return NULL;
    }
    else{
        head -> data = data;
    }

    cin>>data;
    while(data != -1){
        node* newNode = new node(data);
        head -> next = newNode;
        newNode -> prev = head;
        newNode -> next = permaHead;
        head = newNode;

        cin>>data;
    }

    return head;
}

void printNode(node* head){
    node* permaHead = head;
    cout<<head->data<<' ';
    head = head->next;
    
    while(head != permaHead){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
    return;
}

int main(){
    node* head = new node;
    node* tail = takeInput(head);

    printNode(head);
    printNode(tail);
    
    return 0;
}