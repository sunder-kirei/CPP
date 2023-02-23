#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int prev, frames;
        cin >> prev;
        frames = 1;
        for(int i = 0; i < n-1; i++){
            int data;
            cin >> data;

            if(data == prev){
                continue;
            }
            else{
                frames++;
                prev = data;
            }
        }
        cout << frames << endl;
    }
    return 0;
}