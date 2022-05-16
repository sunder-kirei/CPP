#include <iostream>
using namespace std;

class complex{
    private:
        int a;
        int b;

    public:
    complex(int a, int b){
        this->a = a;
        this->b = b;
    }

    void display(){
        cout<<a<<'+'<<b<<'i'<<endl;
        return;
    }

    void add(complex & c2){
        a += c2.a;
        b += c2.b;
        display();
    }

    void multiply(complex & c2){
        int temp1 = (a*c2.a) - (b*c2.b);
        int temp2 = (a*c2.b) + (b*c2.a);
        
        a = temp1;
        b = temp2;

        display();
    }
};