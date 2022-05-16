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

int nodeSearch(node* head, int check, int count = 0){
    if(head == NULL){
        return -1;
    }

    if(head->data == check){
        return count;
    }
    
    return nodeSearch(head->next, check, count+1);
}

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

int main(){
    node* head = new node;
    takeInput(head);
    printNode(head);

    int n;
    cin >> n;

    cout << nodeSearch(head,n) << endl;
    return 0;
}