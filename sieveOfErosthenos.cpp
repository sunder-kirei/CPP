#include <iostream>
using namespace std;

void sieve(int n){
    int arr[n+1] = {0};
    int i = 2;
    int j = 2;
    int k = 2;
    while(k<=n){
        if(arr[k] == 0){
            i = k*k;
            while(i <= n){
                arr[i] = 1;
                i += k;
            }
        }
        k++;
    }

    for(int i = 2; i <= n; i++){
        if(arr[i] == 0){
            cout<<i<<endl;
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;

    sieve(n);
    return 0;
}