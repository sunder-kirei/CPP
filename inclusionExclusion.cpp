#include <iostream>
using namespace std;

inline int incExc(int n, int a, int b){
    return ((n/a)+(n/b)-(n/(a*b)));
}

int main(){
    int n, a, b;
    cin>>n>>a>>b;

    cout<<incExc(n,a,b)<<endl;
}