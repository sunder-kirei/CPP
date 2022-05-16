#include <iostream>
#include <cstring>
using namespace std;

string helper(int n){
    string ref[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string temp = ref[n];
    return temp;
}

void keyPrint(int n, string output){
    if(n == 0){
        cout<<output<<endl;
        return;
    }

    string temp = helper(n%10);
    for(int i = 0; i < temp.length(); i++){
        keyPrint(n/10, output + temp[i]);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    string output = {};
    keyPrint(n,output);
    return 0;
}