#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int sum = 0;
        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int data;
                cin>>data;
                if(i == 0 || i == (n-1) || j == 0|| j == (n-1)){
                    sum += data;
                }
                else if(i == j){
                    sum += data;
                }
            }
        }
        cout<<sum<<endl;
    }
}