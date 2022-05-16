#include <iostream>
#include <cstring>
using namespace std;

void subPrint(string s,string s1){
    if(s.size() == 0){
        cout<<s1<<endl;
        return;
    }
    subPrint(s.substr(1),"" + s1);
    subPrint(s.substr(1), s1 + s[0]);
    return;
}

int main(){
    string s,s1 = {};
    cin>>s;
    subPrint(s,s1);
    return 0;
}