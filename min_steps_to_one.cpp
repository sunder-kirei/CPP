#include <bits/stdc++.h>
using namespace std;

// Brute
int minSteps(int n)
{
    if (n == 1)
        return 0;

    int oneLess = minSteps(n - 1);
    int twoLess = n % 2 ? INT_MAX : minSteps(n / 2);
    int threeLess = n % 3 ? INT_MAX : minSteps(n / 3);

    return (1 + min(min(oneLess, twoLess), threeLess));
}

// Memoization
int minStepsMemo(int n, int *memo)
{
    if (n == 1)
    {
        return 0;
    }

    int oneLess, twoLess, threeLess;
    oneLess = twoLess = threeLess = INT_MAX;

    oneLess = memo[n - 1] != -1 ? memo[n - 1] : minStepsMemo(n - 1, memo);

    if (n % 2 == 0)
    {
        twoLess = memo[n / 2] != -1 ? memo[n / 2] : minStepsMemo(n / 2, memo);
    }
    if (n % 3 == 0)
    {
        threeLess = memo[n / 3] != -1 ? memo[n / 3] : minStepsMemo(n / 3, memo);
    }

    memo[n] = 1 + min(min(oneLess, twoLess), threeLess);

    return memo[n];
}

int minStepsMemo(int n)
{
    int *memo = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        memo[i] = -1;
    }

    return minStepsMemo(n, memo);
}

// Dynamic Programming
int minStepsDP(int n)
{
    int *memo = new int[n + 1];
}

int main()
{
    cout << minStepsMemo(4) << endl;
    cout << minStepsMemo(7) << endl;
    return 0;
}