#include <iostream>
using namespace std;

void stair(int n, int& w){
    if(n == 0){
        w = w+1;
        return;
    }
    if(n>=3){
        stair(n-3,w);
        stair(n-2,w);
        stair(n-1,w);
    }
    else if(n==2){
        stair(n-2,w);
        stair(n-1,w);
    }
    else if( n == 1){
        stair(n-1,w);
    }
}

int main(){
    int n;
    cin>>n;
    int w = 0;
    stair(n,w);
    cout<<w<<endl;
    return 0;
}