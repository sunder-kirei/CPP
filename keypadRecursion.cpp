#include <iostream>
#include <cstring>
using namespace std;

string ref[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int permute=0;
void keypad_help(string m, string *arr,string curr)
{
    if(m.size()==0){
        arr[permute]=curr;
        permute++;
        return;
    }
    int idx=m[0]-'1';
    string s=m.substr(1);
    for(int i=0;i<ref[idx].size();i++){
        keypad_help(s,arr,curr+ref[idx][i]);
    }
    return;

}

int keypad(int n){
    string s=to_string(n);
    int arr_size=1;
    for(int i=0;i<s.size();i++){
        arr_size*=ref[s[i]-'1'].size();
    }
    string arr[arr_size];
    keypad_help(s,arr,"");

    for(int i=0;i<arr_size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    return arr_size;

}


int main()
{
    int n;
    cin >> n;
    int ans = keypad(n);
    cout<<ans<<endl;
    return 0;
}