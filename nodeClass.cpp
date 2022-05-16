#include <iostream>
using namespace std;

class node{
    int data;
    node *next;
    static int size;
    public:

        node(){

        }
        node (node* head){
            this->data = head->data;
            this->next = head->next;
        }

        node (int data){
            this -> data = data;
            next = NULL;
            size++;
        }

        void setNext (node* n){
            next = n;
            return;
        }

        node* getNext() const{
            return next;
        }

        int getData() const{
            return data;
        }

        void setData (int data){
            this -> data = data;
            return;
        }

        static int getSize(){
            return size;
        }

        static void setSize(int size){
            node :: size = size;
            return;
        }

        void takeInput(node *head = NULL)
        {
            node *tail = head;
            int data;
            cin >> data;
            while (data != -1)
            {
                node *newNode = new node(data);
                if (head == NULL)
                {
                    head = newNode;
                    tail = newNode;
                }
                else
                {
                    while (tail->getNext() != NULL)
                    {
                        tail = tail->getNext();
                    }
                    tail->setNext(newNode);
                }
                cin >> data;
            }
            this -> data = head -> data;
            this -> next = head -> next;
            return;
        }

        void printNode(node *head = NULL)
        {
            head = this;
            node *pos = head;
            while (pos != NULL)
            {
                cout << pos->getData() << ' ';
                pos = pos->getNext();
            }
            cout << endl;
            return;
        }
};

int node :: size = 0;