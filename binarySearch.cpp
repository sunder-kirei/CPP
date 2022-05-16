#include <iostream>
using namespace std;

int search(int arr[], int x, int si, int ei){
    if(si>ei){
        return -1;
    }
    int mi = (si+ei)/2;
    if(arr[mi] == x){
        return mi;
    }
    else if(arr[mi] < x){
       return search(arr,x,mi+1,ei);
    }
    else{
        return search(arr,x,si,mi-1);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;
    cout<<search(arr,x,0,n-1);
    return 0;
}