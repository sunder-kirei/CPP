#include <iostream>
#include <cstring>
using namespace std;

bool checkAB(string s){
    if(s.size() == 1){
        return true;
    }
    if(s[0] == 'a'){
        if(s[1] != 'a'){
            if(s[1] == 'b' ){
                if(s[2] != 'b'){
                    return false;
                }
            }
        }
    }
    else if(s[0] == 'b'){
        if(s[1] == 'b'){
            if(s[2] != 'a' && s[2] != '\0'){
                return false;
            }
        }
    }

    return checkAB(s.substr(1));
    
}

int main(){
    string s;
    cin>>s;

    if(s[0] != 'a'){
        cout<<"false"<<endl;
    }
    else{ 
        if(checkAB(s)){
            cout<<"true"<<endl;
        }
        else{
            cout<<"false"<<endl;
        }
    }
    
    return 0;
}