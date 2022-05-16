#include <iostream>
using namespace std;

void printSubset(int arr[], int n, string ans){
    if(n == 0){
        cout<<ans;
        cout<<endl;
        return;
    }

    string temp = to_string(*(arr));

    printSubset(arr+1, n-1, ans);
    printSubset(arr+1, n-1, ans+temp+' ');

    return;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    string ans = "";

    printSubset(arr,n,ans);

    return 0;
}