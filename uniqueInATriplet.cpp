#include <iostream>
using namespace std;

int setBit(int n, int index){
    return (n | (1<<index));
}

bool getBit(int n, int index){
    return (n & (1<<index));
}

int unique(int arr[], int n) {
    int ans = 0;
    for(int i = 0; i < 64; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){    
            if(getBit(arr[j], i)){
                sum++;
            }
        }

        if(sum%3 != 0){
            ans = setBit(ans, i);
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<unique(arr,n)<<endl;
    return 0;
}
