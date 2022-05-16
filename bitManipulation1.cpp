#include <iostream>
using namespace std;

inline bool bitwise(int n, int index){
    return ((1<<index) & n);
}

inline int bitset(int n, int position){
    return ((1<<position) | n);
}

inline int clearBit(int n, int index){
    return ((~(1<<index)) & n);
}

int main(){
    int n, index;
    cin>>n>>index;

    cout<<bitwise(n, index)<<endl;
    cout<<bitset(n, index)<<endl;
    cout<<clearBit(n, index)<<endl;
}