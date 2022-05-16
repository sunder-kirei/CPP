#include <iostream>
using namespace std;

void reverse(int arr[], int si, int ei){
    int i = si, j = ei;
    while(i<j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return;
}

void rotate(int arr[], int n, int num){
    reverse(arr, 0, num-1);
    reverse(arr, num, n-1);
    reverse(arr, 0, n-1);
    
    return;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int num;
        cin>>num;
        rotate(arr,n,num);
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
    }
}