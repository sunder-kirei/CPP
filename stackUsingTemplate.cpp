#include <iostream>
using namespace std;
template <typename T>

class Stack{
    T* data;
    int nxtIdx;
    int totalSize;

    public:
        Stack(int size){
            T* data = new T[size];
            nxtIdx = 0;
            totalSize = size;
        }

        int getNxtIdx(){
            return nxtIdx;
        }

        void push(T data){
            if(nxtIdx < totalSize){
                this -> data[nxtIdx] = data;
                nxtIdx++;
            }
            return;
        }

        T pop(){
            if(nxtIdx == 0){
                return 0;
            }
            nxtIdx--;
            return this -> data[nxtIdx];
        }

        bool isEmpty(){
            if(nxtIdx == 0){
                return true;
            }
            return false;
        }
};


int main(){
    Stack<int> s(10);
    for(int i = 0; i < 10; i++){
        s.push(i);
        cout<<s.getNxtIdx();
    }
    cout<<endl;
    cout << s.isEmpty() << endl;

    for(int i = 0; i < 10; i++){
        cout<<s.pop()<<' ';
        cout<<s.getNxtIdx();
    }
    cout<<endl;
    cout << s.isEmpty() << endl;
    return 0;
}