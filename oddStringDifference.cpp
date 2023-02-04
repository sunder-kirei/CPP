#include <bits/stdc++.h>
using namespace std;

string oddString(vector<string> &words)
{
    string arr[words.size()];

    int idx = 0;
    auto it = words.begin();
    while (it != words.end())
    {
        for (int i = 0; i < (it->size() - 1); i++)
        {
            int temp = ((int)it->at(i + 1) - (int)'a') - ((int)it->at(i) - (int)'a');
            arr[idx] = arr[idx] + to_string(temp);
        }
        it++;
        idx++;
    }

    for (int i = 0; i < words.size() - 1; i++)
    {
        if (arr[i].compare(arr[i + 1]) != 0)
        {
            for (int j = 0; j < words.size() - 1; j++)
            {
                if (j == i || j == i + 1)
                    continue;

                if (arr[j].compare(arr[i]) == 0)
                {
                    return words[i + 1];
                }
                else
                {
                    return words[i];
                }
            }
        }
    }
}

int main()
{
    vector<string> words = {"adc", "wzy", "abc"};
    oddString(words);
}