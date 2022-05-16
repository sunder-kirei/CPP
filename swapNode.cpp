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

node* swapNode(node* head, int idx1, int idx2){
    int count = 0;
    node* newNode = head;
    node* swap = NULL;
    while(head != NULL){
        if(count >= idx1-1 || count >= idx2-1){
            swap = head;
            head = head->next;
            count++;
            break;
        }
        head = head->next;
        count++;
    }
    while(head != NULL){
        if(count == idx1-1 || count == idx2-1 || idx1){
            if(idx1 == 0 || idx2 == 0){
                newNode = head -> next;
                node* temp = swap -> next;
                swap -> next = head -> next -> next;
                head -> next -> next = temp;
                head -> next = swap;
            }
            else{
                node* temp = swap->next;
                swap->next = head->next;
                head -> next = temp;
                temp = temp->next;
                head -> next -> next = swap->next->next;
                swap -> next -> next = temp;
                count++;
                break;
            }
        }
        head = head ->next;
        count++;
    }
    return newNode;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        node* head = new node;
        takeInput(head);
        int m, n;
        cin >> m >> n;

        head = swapNode(head,m,n);
        printNode(head);
    }
    return 0;
}