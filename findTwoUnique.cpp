#include <iostream>
using namespace std;

bool index(int n, int i){
    return (n & (1<<i));
}

void unique(int arr[], int n, int ans[]){
    int xorsum = 0;
    int temp = 0;
    for(int i = 0; i < n; i++){
        xorsum = xorsum ^ arr[i];
    }
    int idx = 0;
    while(!(index(xorsum, idx))){
        idx++;
    }
    for(int i = 0; i < n; i++){
        if(index(arr[i], idx)){
            temp = temp ^ arr[i];
        }
    }

    ans[0] = temp;
    ans[1] = (xorsum ^ temp);
    
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int* ans = new int [2];
    unique(arr,n,ans);
    cout<<ans[0]<<'\n'<<ans[1]<<endl;
    return 0;
}