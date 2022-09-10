#include <iostream>
#include <vector>
template <typename T>
using namespace std;

class TreeNode {
    public:
        T data;
        vector <TreeNode*> children;

    TreeNode(T data){
        this -> data = data;
    }
};