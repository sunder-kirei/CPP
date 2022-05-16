#include <iostream>
using namespace std;

void updateBit(int &n, int index, int update){
    int mask = (n & (~(1<<index)));
    n = (mask | (update<<index));
    return;
}

int main(){
    int n, index, update;
    cin>>n>>index>>update;

    updateBit(n, index, update);
    cout<<n;
    return 0;
}
