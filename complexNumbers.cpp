#include <iostream>
using namespace std;
#include "complexNumbers_Class.cpp"

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    complex c1(a,b);
    complex c2(c,d);

    int n;
    cin>>n;
    if(n == 1){
        c1.add(c2);
    }
    else if(n == 2){
        c1.multiply(c2);
    }
    return 0;
}