#include <iostream>
#include <cstring>
using namespace std;

string ref[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int n, string *arr, int count){
    if(n/10 == 0){
        for(int i = 0; i< ref[n].size(); i++){
            arr[i] = ref[n][i];
        }
        return ref[n].size();
    } 

    int coun = keypad(n/10, arr, count);

    int j = 0, k = 0;
    for(int i = 1; i < ref[n%10].size(); i++){
        for(j; j<(i)*coun; j++){
            arr[coun + j] = ref[n%10][i] + arr[k];
            k++;
        }
        k = 0;
    }
    for(int i = 0; i< coun; i++){
        arr[i] = ref[n%10][0] + arr[i];
    }
    return coun+j;
}

int main(){
    int n;
    cin>>n;
    
    string* arr = new string[100];
    int ans = keypad(n,arr,0);
    for(int i = 0; i<ans; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}