#include <bits/stdc++.h>
#include "hash_map.h"
using namespace std;

int main()
{
    hash_map<int> map;
    for (int i = 0; i < 40; i++)
    {
        char j = i + '0';
        string s = "abc";
        s = s + j;
        map.insert(s, i);
    }
    for (int i = 0; i < 40; i++)
    {
        char j = i + '0';
        string s = "abc";
        s = s + j;
        cout << map.getData(s) << endl;
    }
    return 0;
}