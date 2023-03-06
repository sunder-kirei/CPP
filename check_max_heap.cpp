#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (right >= n)
        {
            right = left;
        }
        if (left >= n)
        {
            right = left = i;
        }
        int maxChild = max(arr[right], arr[left]);
        if (arr[i] < maxChild)
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << isMaxHeap(arr, n) << endl;
    return 0;
}