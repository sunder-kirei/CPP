#include <bits/stdc++.h>
using namespace std;

int getSetBitMask(const int n)
{
    int mask = 1;
    while ((mask & n) == 0)
    {
        mask = mask << 1;
    }
    return mask;
}

int uniqueOne(vector<int> &nums)
{
    int cummulative_xor = 0;
    for (int x : nums)
    {
        cummulative_xor ^= x;
    }
    return cummulative_xor;
}

vector<int> uniqueTwo(vector<int> &nums)
{
    vector<int> ans(2);

    int cummulative_xor = 0;
    for (const int x : nums)
    {
        cummulative_xor = cummulative_xor ^ x;
    }
    int mask = getSetBitMask(cummulative_xor);
    int setOne = 0;
    for (const int x : nums)
    {
        if ((x & mask) > 0)
        {
            setOne = setOne ^ x;
        }
    }
    ans[0] = setOne;
    ans[1] = cummulative_xor ^ setOne;
    return ans;
}

int uniqueThree(vector<int> &nums)
{
    vector<int> bitCount(32, 0);
    for (const int x : nums)
    {
        for (int i = 0; i < 32; i++)
        {
            i << 1;
            if (x & i)
            {
                bitCount[i]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if (bitCount[i] %= 3)
        {
            ans += (1 << i);
        }
    }
    return ans;
}