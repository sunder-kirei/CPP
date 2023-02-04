#include <bits/stdc++.h>
#include "QueueArr.cpp"
using namespace std;

int main()
{
    Queue q(3);

    q.push(1);
    cout << q.pop() << endl;
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    q.push(1);
    cout << q.pop() << endl;
    return 0;
}