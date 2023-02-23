#include <bits/stdc++.h>
using namespace std;

void k_sort(int arr[], int n, int k)
{
    priority_queue<int> queue;
    int i = 0, j = 0;
    while (i < k)
    {
        queue.push(arr[i]);
        i++;
    }
    while (i < n)
    {
        arr[j] = queue.top();
        queue.pop();
        queue.push(arr[i]);
        i++;
        j++;
    }
    while (!queue.empty())
    {
        arr[j] = queue.top();
        queue.pop();
        j++;
    }
    return;
}

int main()
{
    int arr[] = {10, 12, 6, 7, 9};
    int k = 3;
    k_sort(arr, 5, 3);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}