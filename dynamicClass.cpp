#include <iostream>
using namespace std;
#include "dynamicArray_class.cpp"

int main(){
    dynamicArray arr1;
    
    for(int i = 0; i < 16; i++){
        arr1.append(i);
    }
    arr1 += 27;
    for(int i = 0; i < 17; i++){
        cout << arr1.print(i) << ' ';
    }
    cout << endl;
    cout << arr1.getindex() << endl;
    dynamicArray arr2;
    arr2 = arr1;
    arr1.append(101,16);
    cout << arr1.print(16) << endl;
    cout << "arr2: " << arr2.print(16) << ' ' << arr2.getindex() << endl;
}