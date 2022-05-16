#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i = 0; i <t; i++){
        int n;
        cin>>n;
        int arr[n];
        for(int j = 0; j <n; j++){
            cin>>arr[j];
        }
        int ans[n-1] = {0};
        for(int k = 0; k<n; k++){
            if(ans[arr[k]] == 1){
                cout<<arr[k]<<endl;
                break;
            }
            else{
                ans[arr[k]] +=1;
            }
        }
    }
    return 0;
}