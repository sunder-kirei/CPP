#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int* data = new int[n];

    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    for(int i = 0; i < n/2; i++){
        cout<< (data[i]+data[n-i-1])/10 << ' ' <<  (data[i]+data[n-i-1])%10 <<endl;
    }
    return 0;
}