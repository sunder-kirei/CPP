#include <bits\stdc++.h>
using namespace std;

void add(int** arr1, int** arr2, int** arr3, int n, int m){
    int i = 0, j = 0;
    while(i < n){
        while(j < m){
            arr3[i][j] = arr1[i][j] + arr2[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    return;
}

int main(){
    int n, m;
    cin>>n>>m;
    int** arr1 = new int*[n];
    for(int i = 0; i < n; i++){
        arr1[i] = new int[m];
    }
    int** arr2 = new int*[n];
    for(int i = 0; i < n; i++){
        arr2[i] = new int[m];
    }
    int** arr3 = new int*[n];
    for(int i = 0; i < n; i++){
        arr3[i] = new int[m];
    }

    int i = 0, j = 0;
    while(i < n){
        while(j < m){
            cin>>arr1[i][j];
            j++;
        }
        j = 0;
        i++;
    }
    i = 0;
    while(i < n){
        while(j < m){
            cin>>arr2[i][j];
            j++;
        }
        j = 0;
        i++;
    }

    add(arr1,arr2,arr3,n,m);
    i = 0;
    while(i < n){
        while(j < m){
            cout<<arr3[i][j]<<' ';
            j++;
        }
        cout<<endl;
        j = 0;
        i++;
    }
    return 0;
}