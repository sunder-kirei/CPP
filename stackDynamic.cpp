#include <iostream>
using namespace std;

class Stack{
    int* data;
    int capacity;
    int nxtIdx;
    public:
        Stack(int capacity = 5){
            this->capacity = capacity;
            this->data = new int[capacity];
            nxtIdx = 0;
        }
        void push(int data){
            if(nxtIdx < capacity){
                this->data[nxtIdx++] = data;
            }
            else{
                int* newData = new int[capacity*2];
                for(int i = 0; i < capacity; i++){
                    newData[i] = this->data[i];
                }
                this->capacity = this->capacity*2;
                delete[] this->data;
                this->data = newData;
                this->data[nxtIdx++] = data;
            }
        }

        int getCapacity(){
            return this->capacity;
        }

        int getFilledSize(){
            return this->nxtIdx;
        }

        int pop(){
            if(nxtIdx > 0){
                nxtIdx = nxtIdx-1;
                return this->data[nxtIdx];
            }
            else{
                return -1;
            }
        }
        int getTop(){
            if(nxtIdx > 0){
                return this->data[nxtIdx-1];
            }
            else{
                return -1;
            }
        }
        bool isEmpty(){
            return (nxtIdx == 0);
        }
};

int main(){
    Stack s1(3);
    for(int i=0;i<10;i++){
        s1.push(i);
    }
    cout<<s1.getTop()<<endl;
    for(int i=0;i<11;i++){
        cout<<s1.pop()<<endl;
    }
    cout<<s1.isEmpty()<<endl;
    cout<<s1.getCapacity()<<endl;
    cout<<s1.getFilledSize()<<endl;
}