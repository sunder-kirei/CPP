#include <bits/stdc++.h>
#include "trie.h"
using namespace std;

int main()
{
    Trie root;
    string one = "one";
    string i = "I";
    string am = "am";
    root.insert(one);
    root.insert(i);

    cout << root.search(one) << endl;
    cout << root.search(am) << endl;
    return 0;
}