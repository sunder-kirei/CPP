#include <bits/stdc++.h>
#include <stack>
using namespace std;

bool isBalanced(string s)
{
    stack<char> st;

    string::iterator i;

    for (i = s.begin(); i < s.end(); i++)
    {
        if (st.empty())
        {
            st.push(*i);
            continue;
        }
        if ((*i == '(' && st.top() == ')') || (*i == ')' && st.top() == '('))
        {
            st.pop();
        }
        else
        {
            st.push(*i);
        }
    }

    return st.empty();
}

int main()
{
    string s;
    cin >> s;

    cout << isBalanced(s) << endl;
    return 0;
}