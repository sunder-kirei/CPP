#include <iostream>
#include "fractionClass.cpp"
using namespace std;

int main(){
    fraction f1(10,2);
    fraction f2(15,4);
    f1.display();
    f2.display();
    fraction f3 = f1 + f2;
    fraction f4 = f1 * f2;
    f3.display();
    f4.display();
    f1.add(f2);
    cout << (f3 == f1) << endl;
    f1.multiply(f2);
    cout << (f4 == f1) << endl;
    f4 = (++(++f1));
    f1.display();
    f4.display();
    f4++;
    f4.display();
    (f1+=f4) += f4;
    f1.display();
    return 0;
}