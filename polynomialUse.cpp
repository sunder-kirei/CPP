#include <iostream>
using namespace std;
#include "polynomial_class.cpp"

int main(){
    int n;
    cin>>n;
    int powers[n];
    int coeff[n];
    polynomial p1;
    for(int i = 0; i < n; i++){
        cin>>powers[i];
    }
    for(int i = 0; i < n; i++){
        cin>>coeff[i];
        p1.setCoefficient(coeff[i], powers[i]);
    }

    cin>>n;
    polynomial p2;
    for(int i = 0; i < n; i++){
        cin>>powers[i];
    }
    for(int i = 0; i < n; i++){
        cin>>coeff[i];
        p2.setCoefficient(coeff[i], powers[i]);
    }
    
    cin>>n;
    
    if(n == 1){
        polynomial p3 = p1 + p2;
        p3.print();
    }
    else if(n == 2){
        polynomial p3 = p1 - p2;
        p3.print();
    }
    else if(n == 3){
        polynomial p3 = (p1 * p2);
        p3.print();
    }

    return 0;
}