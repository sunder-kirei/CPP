#include <iostream>
#include "max_priority_queue.h"
using namespace std;

int main()
{
    PriorityQueue p;

    p.insert(10);
    p.insert(11);
    p.insert(9);

    cout << p.removeMax() << endl;
    cout << p.removeMax() << endl;
    cout << p.removeMax() << endl;
    cout << p.removeMax() << endl;
}