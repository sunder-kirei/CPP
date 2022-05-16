#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int data){
            this->data = data;
            next = NULL;
        }

        node(){
            this->data = 0;
            next = NULL;
        }
};

void takeInput(node* head){
    int data;
    cin>>data;

    if(data == -1){
        return;
    }
    else{
        head->data = data;
    }
    cin>>data;
    while(data != -1){
        node* newNode = new node(data);
        head -> next = newNode;
        head = newNode;

        cin>>data;
    }

    return;
}

void printNode(node* head){
    while(head != NULL){
        cout<<head->data<<' ';
        head = head->next;
    }
    cout << endl;
    return;
}

node* evenAfterOdd(node* head){
    node* oddHead = NULL;
    node* evenHead = NULL;
    node* oddTail = NULL;
    node* evenTail = NULL;
    
    while(head != NULL){
        if((head->data) % 2 == 0){
            if(evenHead == NULL){
                evenHead = head;
                evenTail = head;
            }
            else{
                evenTail -> next = head;
                evenTail = head;
            }
        }
        else{
            if(oddHead == NULL){
                oddHead = head;
                oddTail = head;
            }
            else{
                oddTail -> next = head;
                oddTail = head;
            }
        }
        head = head -> next;
    }
    if(oddHead != NULL && evenTail != NULL){
        oddTail -> next = evenHead;
        evenTail -> next = NULL;
        return oddHead;
    }
    else if(oddHead == NULL){
        evenTail -> next = NULL;
        return evenHead;
    }
    else{
        oddTail -> next = NULL;
        return oddHead;
    }
}

int main(){
    int t;
    cin >> t;

    while(t--) {
        node* head = new node;
        takeInput(head);

        printNode(head);

        head = evenAfterOdd(head);

        printNode(head);
    }

    return 0;
}