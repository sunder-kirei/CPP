#include <bits/stdc++.h>
using namespace std;

vector<int> k_smallest(int arr[], int n, int k)
{
    priority_queue<int> queue;
    int i = 0;
    while (i < k)
    {
        queue.push(arr[i]);
        i++;
    }
    while (i < n)
    {
        if (arr[i] < queue.top())
        {
            queue.pop();
            queue.push(arr[i]);
        }
        i++;
    }
    vector<int> ans;
    while (!queue.empty())
    {
        ans.push_back(queue.top());
        queue.pop();
    }
    return ans;
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
    int k;
    cin >> k;
    auto ans = k_smallest(arr, n, k);
    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}