#include <iostream>
#include <algorithm>
using namespace std;

int GCD(int n, int m){
    if(n % m == 0){
        return m;
    }
    return GCD(m,n%m);
}

int main(){
    int n, m;
    cin>>n>>m;

    cout<<GCD(max(n,m),min(n,m))<<endl;
    return 0;
}