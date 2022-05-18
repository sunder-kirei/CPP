#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;

    while (t--){
        // long long int ans = 1;
        int ans = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            char data;
            cin >> data;

            if(data > 'a' && data < 'e'){
                if(data - 'a' == abs(data - 'e')){
                    ans++;
                }
            }
            else if(data > 'e' && data < 'i'){
                if(data - 'e' == abs(data - 'i')){
                    ans++;
                }
            }
            else if(data > 'i' && data < 'o'){
                if(data - 'i' == abs(data - 'o')){
                    ans++;
                }
            }
            else if(data > 'o' && data < 'u'){
                if(data - 'o' == abs(data - 'u')){
                    ans++;
                }
            }
        }
        cout << pow(2,ans) << endl;
    }
    return 0;
}