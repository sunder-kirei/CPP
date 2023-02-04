#include <vector>
using namespace std;

class tree_node{
    public:
    int data;
    vector<int> children;

    tree_node(int data){
        this->data = data;
    }
};