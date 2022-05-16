#include <iostream>
using namespace std;

int possibleMoves(int position,int x, int movesLeft){
    int count = 0;
    while(movesLeft && position+x < 65 && position+x > 0){
        position += x;
        movesLeft--;
        count++;
    }
    return count;
}

int maxMoves(int position, int movesLeft){
    int count = 0;
    count += possibleMoves(position,9,movesLeft);
    count += possibleMoves(position,-9,movesLeft);
    count += possibleMoves(position,8,movesLeft);
    count += possibleMoves(position,-8,movesLeft);
    count += possibleMoves(position,7,movesLeft);
    count += possibleMoves(position,-7,movesLeft);
    count += possibleMoves(position,1,movesLeft);
    count += possibleMoves(position,-1,movesLeft);
    return count+1;
    // if(movesLeft == 0){
    //     return count;
    // }
    // if(position+9 > 0 &&  position+9 < 65){
    //     count = maxMoves(position+9, count+1,movesLeft-1);
    // }
    // if(position-9 > 0 &&  position-9 < 65){
    //     count = maxMoves(position-9, count+1,movesLeft-1);
    // }
    // if(position+8 > 0 &&  position+8 < 65){
    //     count = maxMoves(position+8, count+1,movesLeft-1);
    // }
    // if(position-8 > 0 &&  position-8 < 65){
    //     count = maxMoves(position-8, count+1,movesLeft-1);
    // }
    // if(position+7 > 0 &&  position+7 < 65){
    //     count = maxMoves(position+7, count+1,movesLeft-1);
    // }
    // if(position-7 > 0 &&  position-7 < 65){
    //     count = maxMoves(position-7, count+1,movesLeft-1);
    // }
    // if(position-1 > 0 &&  position-1 < 65){
    //     count = maxMoves(position-1, count+1,movesLeft-1);
    // }
    // if(position+1 > 0 &&  position+1 < 65){
    //     count = maxMoves(position+1, count+1,movesLeft-1);
    // }
    // return count+1;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,movesLeft;
        cin>>x>>y>>movesLeft;
        cout<<maxMoves(x*y,movesLeft);
    }
    return 0;
}