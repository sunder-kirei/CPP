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

void printNode(node* head){
    while(head != NULL){
        cout<<head -> getData()<<' ';
        head = head -> getNext();
    }
    cout<<endl;
    return;
}

node* reverseLL(node* head){
    if(head == NULL) return NULL;
    if((head -> getNext()) -> getNext() == NULL){
        head -> getNext() -> setNext(head);
        node* temp = head -> getNext();
        head -> setNext(NULL);
        return temp;
    }
    node* tail = reverseLL(head -> getNext());
    (head ->getNext()) -> setNext(head);
    head -> setNext(NULL);
    return tail;
}

bool boolPalindrome(node* head){
    if(head == NULL) return true;
    node* tail = head;
    int size = node :: getSize();
    int i = 0;
    while(i < (size-1)/2){
        tail = tail -> getNext();
        i++;
    }
    node* newHead = tail -> getNext();
    newHead = reverseLL(newHead);
    tail -> setNext(NULL);

    while(head != NULL && newHead !=  NULL){
        if(head -> getData() != newHead -> getData()){
            return false;
        }
        head = head -> getNext();
        newHead = newHead -> getNext();
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        node* head = takeInput();
        if(boolPalindrome(head)){
            cout<<"True"<<endl;
        }
        else cout<<"False"<<endl;
        node :: setSize(0);
    }
    return 0;
}