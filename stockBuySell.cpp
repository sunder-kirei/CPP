#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxProfit = 0;

    vector<int>::iterator ptr;
    ptr = prices.begin();

    int minPrice = *ptr;

    while (ptr < prices.end())
    {
        if (*ptr <= minPrice)
        {
            minPrice = *ptr;
            ptr++;
            continue;
        }
        int currentProfit = *ptr - minPrice;

        if (currentProfit > maxProfit)
            maxProfit = currentProfit;

        ptr++;
    }

    return maxProfit;
}

int main()
{
}