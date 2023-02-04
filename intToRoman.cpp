#include <bits/stdc++.h>
using namespace std;

string intToRoman(int num)
{
    // use const please!!!

    // It will reduce runtime by a TON!!!c
    int integer[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman;
    roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ans = "";

    while (num)
    {
        for (int i = 0; i < sizeof(integer) / sizeof(int); i++)
        {
            if (num >= integer[i])
            {
                num -= integer[i];
                ans += roman[i];
                break;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << intToRoman(n) << endl;
    return 0;
}