#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPresent(string s, string t){
    if(s.size() == 0){
        if(t.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
    if(s[0] != t[0]){
        return isPresent(s.substr(1),t);
    }
    else if(s[0] == t[0]){
        return isPresent(s.substr(1),t.substr(1));
    }
}

int main(){
    string s,t;
    cin>>s>>t;

    cout<<isPresent(s,t)<<endl;
    return 0;
}