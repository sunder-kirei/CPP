#include <iostream>
using namespace std;

template <typename X, typename Y>

class TemplateTest{
    X x;
    Y y;
    public:
        X getX(){
            return x;
        }
        Y getY(){
            return y;
        }

        void setX(X x){
            this->x = x;
            return;
        }
        void setY(Y y){
            this->y = y;
            return;
        }

};

int main(){
    TemplateTest<int,int> t;
    t.setX(1);
    t.setY(1);
    cout << t.getX() << endl;
    cout << t.getY() << endl;
}