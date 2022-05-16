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

node* reverseK(node* head, int n){
    if(n==0){
        return head;
    }
    
    node* newHead = NULL;
    node* newTail = head;
    node* nextNode = head;
    node* prevNode = head;
    
    while(head != NULL){
        int count = 0;
        prevNode = NULL;
        node* temp = NULL;
        while(count < n && head != NULL){
            if(count == 0){
                temp = head;
            }
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
            count++;
        }
        if(newHead == NULL){
            newHead = prevNode;
            prevNode = NULL;
        }
        newTail -> next = prevNode;
        newTail = temp;
    }

    return newHead;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        node* head = new node;
        takeInput(head);

        int n;
        cin >> n;

        head = reverseK(head, n);

        printNode(head);
    }

    return 0;
}