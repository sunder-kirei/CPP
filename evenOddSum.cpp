#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int data;
    int oddSum = 0, evenSum = 0;
    for(int i = 0; i < n; i++){
        cin>>data;
        if(i % 2 == 0 && data % 2 == 0){
            evenSum += data;
        }
        else if(i % 2 != 0 && data % 2 != 0){
            oddSum += data;
        }
    }
    cout<<evenSum<<" "<<oddSum<<endl;
}