#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void sortColors(vector<int> &nums)
{
    int size = nums.size();

    int low = 0, med = 0, high = size - 1;

    while (med <= high)
    {
        if (nums.at(med) == 1)
        {
            med++;
            continue;
        }

        if (nums.at(med) == 0)
        {
            swap(&nums[med], &nums[low]);
            med++;
            low++;
            continue;
        }

        if (nums.at(med) == 2)
        {
            swap(&nums[med], &nums[high]);
            med++;
            high++;
            continue;
        }
    }

    return;
}

int main()
{
}