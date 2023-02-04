#include <bits/stdc++.h>
#include "bst_node.h"
using namespace std;

int main()
{
    bst b;
    int data;
    cin >> data;
    while (data != -1)
    {
        b.insert(data);
        cin >> data;
    }
    b.print();
    int n;
    cin >> n;
    b.delete_node(n);
    b.print();
    return 0;
}