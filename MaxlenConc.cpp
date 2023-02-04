#include<bits/stdc++.h>
using namespace std;
int maxLength(vector<string> & arr){
    vector<string> unique;
    int n= arr.size();
    for(int i=0;i<n;i++){
        unordered_set<char> st;
        for(int j=0;j<arr[i].size();j++){
            st.insert(arr[i][j]);
        }
        string str="";
        for(auto x: st){
            str+=x;
        }
        unique.push_back(str);
    }
    unordered_set<char> unq;
    for(int i=0;i<unique.size();i++){
        for(auto x: unique[i]){
            unq.insert(x);
        }
    }
    return unq.size();
}
int main(){
    
}