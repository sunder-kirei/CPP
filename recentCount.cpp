#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        map <string, int> m;
        m["START38"] = 0;
        m["LTIME108"] = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            m[s]++;
        }
        cout << m["START38"] << ' ' << m["LTIME108"] << endl;
    }
    return 0;
}