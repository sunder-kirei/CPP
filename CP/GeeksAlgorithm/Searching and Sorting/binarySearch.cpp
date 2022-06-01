#include <bits/stdc++.h>

int midIdx(int si, int ei){
    return (si + (ei - si) / 2);
}

int main(){
    std::vector<int> arr;
    int data;
    std::cin>>data;

    while(data != -1){
        arr.push_back(data);
        std::cin >> data;
    }

    int x;
    std::cin>> x;

    int si = 0;
    int ei = (arr.size() - 1);
    int mi = midIdx(si, ei);

    while(arr.at(mi) != x && si != mi && ei != mi){
        if(arr.at(mi) > x){
           ei = mi;
           mi = midIdx(si, ei);
        }
        else{
            si = mi;
            mi = midIdx(si, ei);
        }
    }    

    if(arr.at(mi) == x){
        std::cout << mi << std::endl;
    }
    else{
        std::cout << -1 << std::endl;
    }
    return 0;
}