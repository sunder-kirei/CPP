#include <bits/stdc++.h>
using namespace std;

void subsets(int *arr, vector<int> ans, int n)
{
    if (n == 0)
    {
        if (ans.size() < 8)
            return;
        vector<int>::iterator i = ans.begin();
        for (i; i < ans.end(); i++)
        {
            cout << *i << ' ';
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[0]);
    subsets(arr + 1, ans, n - 1);
    ans.pop_back();
    subsets(arr + 1, ans, n - 1);

    return;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> ans;

    subsets(arr, ans, sizeof(arr) / sizeof(int));
    return 0;
}