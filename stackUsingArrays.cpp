#include <iostream>
#include <limits>
using namespace std;

class stackUsingArrays{
    int* data;
    int capacity;
    int nxtIdx;

    public:
        stackUsingArrays(int capacity){
            data = new int[capacity];
            this->capacity = capacity;
            nxtIdx = 0;
        }

        void push(int data){
            if(nxtIdx == capacity){
                cout<< "Stack Full!"<<endl;
                return;
            }
            this->data[nxtIdx++]=data;
            return;
        }

        int pop(){
            if(nxtIdx <= 0){
                cout<< "Stack Empty!"<<endl;
                return -1;
            }
            return this->data[(nxtIdx--)-1];
        }

        int top(){
            return data[nxtIdx];
        }

        int size(){
            return nxtIdx;
        }

        bool isEmpty(){
            return (nxtIdx == 0);
        }
};

int main(){
    stackUsingArrays s(10);
    for(int i = 0; i< 11; i++){
        s.push(i);
    }

    for(int i = 0; i < 11; i++){
        cout<<s.pop()<<endl;
    }

    cout<<s.isEmpty()<<endl;
    return 0;
}