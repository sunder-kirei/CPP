#include <iostream>
using namespace std;

bool isPalindrome(char arr[], int n){
    int ref[26] = {0};
    for(int i = 0; i < n; i+=2) {
        ref[(int)('a' - arr[i])] += 1;
    }
    for(int i = 1; i < n; i+=2){
        ref[(int)('a' - arr[i])] -= 1;
    }

    for(int i = 0; i < 26; i++){
        if(ref[i] != 0){
            return false;
        }
    }
    return true;
}

int main() {
    
}