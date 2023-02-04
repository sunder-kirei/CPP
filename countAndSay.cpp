#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    if (n == 1)
        return "1";

    string count = countAndSay(n - 1);
    string ::iterator ptr;
    ptr = count.begin();

    string newString;

    while (ptr < count.end())
    {
        auto it = ptr;
        int num = 0;

        while (it < count.end() && ptr < count.end())
        {
            if (*ptr != *it)
            {
                ptr = it - 1;
                break;
            }

            num++;
            it++;
        }
        num += 48;
        newString.push_back((char)num);
        newString.push_back(*ptr);
        ptr = it;
    }

    return newString;
}

int main()
{
    int n;
    cin >> n;

    cout << countAndSay(n) << endl;
    return 0;
}