#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    vector <int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i+1);
    }
    
    // Vectors
    vector <int>::iterator it;

    for(it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    // Pair
    pair <int, int>p;
    p = make_pair(1,2);
    cout<< p.first << endl;
    return 0;
}