#include <iostream>
#include <cmath>
using namespace std;

void helper(int ref, int **ans, int num){
    for(int i = 0; i<ref; i++){
        int n = ans[i][0];
        n +=1;
        ans[ref+i] = new int [n];
        ans[ref+i][0] = n;
        for(int j = 0; j<n; j++){
            ans[ref+i][j+2] = ans[i][j+1];
        }
        ans[ref+i][1] = num;
    }
    
    return;
}

int subset(int **ans, int ref,int arr[], int n){
    if(n == 1){
        ans[0] = new int[1];
        ans[0][0] = 0;
        return 1;
    }
    ref = subset(ans, ref, arr+1, n-1);

    helper(ref, ans, *(arr));

    return 2*ref;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    int m = pow(2,n);
    int **ans = new int *[m];
    subset(ans, 0, arr, n);

    for(int i = 0; i<m; i++){
        int index = ans[i][0];
        for(int j = 0; j<index; j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }

    for(int i = 0; i<m; i++){
        delete[] ans[i];
    }

    delete[] ans;

    return 0;
}