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

int pairSum(int arr[], int n, int check){
    int count = 0, i = 0, j = n-1;
    if(arr[i] == arr[j]){
        return factorial(n-1);
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
        cout<<pairSum(arr,n,check)<<endl;
    }
    return 0;
}