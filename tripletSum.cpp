#include <iostream>
#include <algorithm>
using namespace std;

int factorial(int n){
    int i = 1, product = 1;
    while(i<=n){
        product *= i;
        i++;
    }
    return product;
}

int pairSum(int arr[], int n, int check, int si){
    int count = 0, i = si+1, j = n-1;
    if(arr[i] == arr[j]){
        if(i != j){
            return factorial(n-1);
        }
        else{
            return 0;
        }
    }
    else{
        while(i<j){
            if(arr[i] + arr[j] == check){
                int temp = 1, temp2 = 1;
                if(arr[i] == arr[i+1] || arr[j] == arr[j-1]){
                    while(arr[i] == arr[i+1] && i+1 != j){
                        temp++;
                        i++;
                    }
                    while(arr[j] == arr[j-1] && j-1 != i){
                        temp2++;
                        j--;
                    }
                    if(temp == 0){
                        temp ++;
                    }
                    else if(temp2 == 0){
                        temp2++;
                    }
                    i++;
                    j--;
                    count += (temp*temp2);
                }
                else{
                    count++;
                    i++;
                    j--;
                }
            }
            else if(arr[i] + arr[j] < check){
                i++;
            }
            else {
                j--;
            }
        }
        return count;
    }
}

int tripletSum(int arr[], int n, int check){
    int count = 0;
    for(int i = 0; i < n; i++){
        int temp = check - arr[i];
        count += pairSum(arr,n,temp,i);
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        int check;
        cin>>check;
        sort(arr,arr+n);
        
        cout<<tripletSum(arr,n,check)<<endl;;
    }
    return 0;
}