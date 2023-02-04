#include <bits/stdc++.h>
using namespace std;

void towerOfHanoiGeneric(int n, char source, char helper, char destination)
{
    if (!n)
        return;

    towerOfHanoiGeneric(n - 1, source, destination, helper);
    cout << source << " to " << destination << endl;
    towerOfHanoiGeneric(n - 1, helper, source, destination);
    return;
}

int main()
{
    towerOfHanoiGeneric(3, '1', '2', '3');
}