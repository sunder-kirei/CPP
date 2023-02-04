#include <bits/stdc++.h>
using namespace std;

int findMax(map<string, int> &words)
{
    auto it = words.begin();
    int max = 0;

    while (it != words.end())
    {
        if (it->second > max)
        {
            max = it->second;
        }
        it++;
    }

    return max;
}

vector<string> topKFrequent(vector<string> &words, int k)
{
    map<string, int> newMap;
    for (auto it : words)
    {
        // cout << it << endl;
        newMap[it]++;
    }

    vector<string> ans;
    string str;
    auto ptr = newMap.begin();
    while (ptr != newMap.end())
    {
        int max = findMax(newMap);
        auto j = newMap.begin();
        while (j != newMap.end())
        {
            if (j->second == max)
            {
                str = j->first;
                break;
            }
            j++;
        }
        ans.push_back(str);
        newMap.erase(str);
        ptr++;
    }

    return ans;
}

int main()
{
    vector<string> words;
    // ["i","love","leetcode","i","love","coding"]
    words.push_back("i");
    words.push_back("love");
    words.push_back("leetcode");
    words.push_back("i");
    words.push_back("love");
    words.push_back("coding");

    topKFrequent(words, 2);
    return 0;
}