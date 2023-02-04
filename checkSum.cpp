#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] %= k;
    }

    auto it = nums.begin();
    int currentSum = 0;
    while (it != nums.end() - 1)
    {
        if (currentSum + *it + *(it + 1) < k)
        {
            currentSum += (*it + *(it + 1));
            it++;
            continue;
        }
        if (currentSum + *it + *(it + 1) > k)
        {
            currentSum = 0;
            it++;
            continue;
        }
        return true;
    }

    return false;
}

int main()
{
}