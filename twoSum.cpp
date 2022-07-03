#include <bits/stdc++.h>
using namespace std;

int minMoves2(vector<int>& nums) {
    vector<int>::iterator ptr;
    int mean = 0;
    for(ptr = nums.begin(); ptr < nums.end(); ptr++){
        mean += *ptr;
    }
    mean = mean / nums.size();
    
    int minMoves = 0;
    for(ptr = nums.begin(); ptr < nums.end(); ptr++){
        minMoves += abs(*ptr - mean);
        cout << minMoves << endl;
    }

    return minMoves;
}

int main(){
    vector<int> nums = {1,0, 0, 8, 6};
    cout << minMoves2(nums) << endl;
}