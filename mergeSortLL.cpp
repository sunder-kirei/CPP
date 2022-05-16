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

void deleteNode(node* head){
    while(head != NULL){
        node* temp = head;
        head = head -> getNext();
        delete temp;
    }
}

node* merge(node* head1, node* head2){
    node* finalHead = (head1 -> getData() < head2 -> getData()) ? head1 : head2;
    node* finalTail = finalHead;

    if(finalHead == head1){
        head1 = head1 -> getNext();
    }
    else head2 = head2 -> getNext();

    while(head1 != NULL && head2 != NULL){
        if(head1 -> getData() < head2 -> getData()){
            finalTail -> setNext(head1);
            finalTail = finalTail -> getNext();
            head1 = head1 -> getNext();
        }
        else{
            finalTail -> setNext(head2);
            finalTail = finalTail -> getNext();
            head2 = head2 -> getNext();
        }
    }

    if(head1 == NULL){
        finalTail -> setNext(head2);
    }
    else finalTail -> setNext(head1);

    return finalHead;
}

node* midPoint(node* head){
    if(head == NULL) return head;

    node* slow = head;
    node* fast = head -> getNext();

    while(fast != NULL && fast -> getNext() != NULL){
        slow = slow -> getNext();
        fast = fast -> getNext() -> getNext();
    }
    return slow;
}

node* mergeSort(node* head){
    if(head == NULL) return head;
    
    if(head -> getNext() == NULL){
        return head;
    }
    node* enode = midPoint(head);
    node* snode = enode -> getNext();
    enode -> setNext(NULL);
    node* newHead1 = mergeSort(head);
    node* newHead2 = mergeSort(snode);

    node* newHead = merge(newHead1, newHead2);
    return newHead;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        node* head = takeInput();
        head = mergeSort(head);
        head -> printNode();
        deleteNode(head);
    }
    return 0;
}