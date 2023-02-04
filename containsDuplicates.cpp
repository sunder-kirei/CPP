#include <bits/stdc++.h>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    vector<pair<int, int>> numIdx;

    for (int i = 0; i < nums.size(); i++)
    {
        numIdx.push_back(make_pair(nums[i], i));
    }

    sort(numIdx.begin(), numIdx.end());

    auto ptr = numIdx.begin();
    while (ptr != numIdx.end())
    {
        if ((ptr + 1) == numIdx.end())
            return false;
        if (ptr->first == (ptr + 1)->first && ptr->second - (ptr + 1)->second <= k)
        {
            return true;
        }
        ptr++;
    }

    return false;
}

int main()
{
}