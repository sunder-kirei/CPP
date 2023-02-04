#include <bits/stdc++.h>
using namespace std;

int decimalToBinary(int n)
{
    int mask = 1, pow = 1;
    int ans = 0;
    while (n > 0)
    {
        ans += ((mask & n) * pow);
        pow *= 10;
        n = n >> 1;
    }
    return ans;
}

int main()
{
    cout << decimalToBinary(9) << endl;
}