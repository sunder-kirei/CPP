#include <iostream>
#include "queueLL.h"
using namespace std;

int main()
{
    queue q1;
    q1.enqueue(1);
    cout << q1.front() << endl;
    cout << q1.dequeue() << endl;
    cout << q1.dequeue() << endl;
}