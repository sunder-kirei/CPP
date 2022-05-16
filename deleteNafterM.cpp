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

node* deleteN(node* head, int n){
    while(head != NULL && n--){
        node* temp = head -> next;
        delete head;
        head = temp;
    }
    return head;
}

node* deleteNafterM(node* head, int m, int n){
    int count = 0;
    node* newHead = NULL;
    while(head != NULL){
        while(count < m-1 && head != NULL){
            if(newHead == NULL){
                newHead = head;
            }
            head = head -> next;
            count++;
        }
        if(head != NULL){
            head -> next = deleteN(head->next, n);
            head = head -> next;
        }
        count = 0;
    }

    return newHead;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        node* head = new node;
        takeInput(head);
        int m, n;
        cin >> m >> n;
        printNode(head);

        head = deleteNafterM(head,m,n);
        printNode(head);
    }
    return 0;
}