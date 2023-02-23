#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> queue;

    void upHeapify()
    {
        int childIdx = queue.size() - 1;

        while (childIdx > 0)
        {
            int parentIdx = (childIdx - 1) / 2;
            int childData = queue[childIdx];
            int parentData = queue[parentIdx];
            if (childData < parentData)
            {
                queue[parentIdx] = childData;
                queue[childIdx] = parentData;
            }

            childIdx = parentIdx;
        }
        return;
    }

    void downHeapify()
    {
        int currentIdx = 0;
        const int size = getSize();
        while (currentIdx < size)
        {
            int left = 2 * currentIdx + 1;
            int right = 2 * currentIdx + 2;
            int minIdx;
            if (right > queue.size())
            {
                right = left;
            }
            if (left > queue.size())
            {
                minIdx = currentIdx;
            }
            else
            {
                minIdx = queue[left] < queue[right] ? left : right;
            }
            if (queue[currentIdx] < queue[minIdx])
            {
                int temp = queue[currentIdx];
                queue[currentIdx] = queue[minIdx];
                queue[minIdx] = temp;
            }
            else
            {
                break;
            }
            currentIdx = minIdx;
        }
        return;
    }

public:
    int getSize()
    {
        return queue.size();
    }

    bool isEmpty()
    {
        return queue.size() == 0;
    }

    void insert(int data)
    {
        queue.push_back(data);
        upHeapify();
    }

    int remove()
    {
        if (isEmpty())
            return 0;
        int ans = queue[0];
        queue[0] = queue[queue.size() - 1];
        queue.pop_back();
        downHeapify();
        return ans;
    }
};