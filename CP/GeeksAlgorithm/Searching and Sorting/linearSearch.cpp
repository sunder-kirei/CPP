#include <bits/stdc++.h>

int main(){
    std::vector<int> arr;
    int data;
    std::cin >> data;
    while(data != -1){
        arr.push_back(data);
        std::cin >> data;        
    }
    int x;
    std::cin >> x;
    for(int i = 0; i < arr.size(); i++){
        if(arr.at(i) == x){
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}