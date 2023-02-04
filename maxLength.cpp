#include <bits/stdc++.h>
using namespace std;

void subArr(string *copyArr, vector<string> &ans, int size, string temp)
{
    if (!size)
    {
        ans.push_back(temp);
        return;
    }

    subArr(copyArr + 1, ans, size - 1, temp + *copyArr);
    subArr(copyArr + 1, ans, size - 1, temp);
    return;
}

int maxLength(vector<string> &arr)
{
    string copyArr[arr.size()];
    auto it = arr.begin();
    int i = 0;

    while (it != arr.end())
    {
        copyArr[i] = *it;
        it++;
        i++;
    }
    vector<string> ans;
    subArr(copyArr, ans, arr.size(), "");

    for (int i = 0; i < ans.size(); i++)
    {
        sort(ans[i].begin(), ans[i].end());
    }
    int maxLength = 0;
    for (int i = 0; i < ans.size(); i++)
    {

        int j = 0;
        for (j = 0; j < ans[i].size() - 1; j++)
        {
            if (ans[i][j] == ans[i][j + 1])
                break;
        }
        if (j == (ans[i].size() - 1))
            maxLength = max((int)ans[i].size(), maxLength);
    }
    return maxLength;
}

int main()
{
    vector<string> arr = {"un", "iq", "ue"};
    cout << maxLength(arr) << endl;
    return 0;
}