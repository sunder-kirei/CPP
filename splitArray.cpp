#include <bits/stdc++.h>
using namespace std;

bool willSplit(int arr[], int n)
{
    int threeSum = 0, fiveSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0 && arr[i] % 5 != 0)
        {
            threeSum += arr[i];
            arr[i] = 0;
        }
        else if (arr[i] % 5 == 0)
        {
            fiveSum += arr[i];
            arr[i] = 0;
        }
    }
    sort(arr, arr + n);

    
}

int main()
{
    int arr[] = {3, 3, 9, 10, 8, 7, 2, 8};
    cout << willSplit(arr, 8) << endl;
}