#include <bits/stdc++.h>
using namespace std;

int max_num(int arr[], int n)
{
    map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    int max = 0;
    int max_count = 0;
    auto it = map.begin();
    while (it != map.end())
    {
        if (it->second > max_count)
        {
            max_count = it->second;
            max = it->first;
        }
        it++;
    }
    return max;
}

void print_intersection(int a[], int b[], int n, int m)
{
    map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (map.count(b[i]))
        {
            if (map[b[i]] != 0)
            {
                cout << b[i] << ' ';
                map[b[i]]--;
            }
        }
    }
    cout << endl;
    return;
}

int count_pair(int arr[], int n)
{
    map<int, int> map;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int search = -1 * arr[i];
        if (map.count(search))
        {
            count++;
        }
        map[arr[i]]++;
    }
    return count;
}

// Assignment

string remove_duplicates(string s)
{
    map<char, int> map;
    for (int i = 0; i < s.length(); i++)
    {
        map.insert(make_pair(s[i], 1));
    }
    string ans;
    for (auto i : map)
    {
        ans.push_back(i.first);
    }
    return ans;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return (a.first < b.first);
}

vector<int> consecutive(int arr[], int n)
{
    vector<pair<int, int>> map;
    for (int i = 0; i < n; i++)
    {
        map.push_back(make_pair(i, arr[i]));
    }
    sort(map.begin(), map.end(), compare);
    for (auto x : map)
    {
        cout << x.first << ' ' << x.second << endl;
    }
    vector<int> ans;
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
    consecutive(arr, n);
    return 0;
}