#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
    vector<int> queue;

    void upHeapify()
    {
        int childIdx = queue.size() - 1;

        while (childIdx)
        {
            int parentIdx = (childIdx - 1) / 2;
            if (queue.at(parentIdx) < queue.at(childIdx))
            {
                // Swap parent and child
                const int temp = queue[parentIdx];
                queue[parentIdx] = queue[childIdx];
                queue[childIdx] = temp;
                // Update childIdx
                childIdx = parentIdx;
            }
            else
                break;
        }
        return;
    }

    void downHeapify()
    {
        int parentIdx = 0;
        const int size = queue.size() - 1;

        while (parentIdx < size)
        {
            int left = 2 * parentIdx + 1;
            int right = 2 * parentIdx + 2;

            // Check if left and right are in range
            if (right > size)
                right = left;
            if (left > size)
                left = right = parentIdx;

            const int maxIdx = queue.at(left) > queue.at(right) ? left : right;
            if (queue.at(maxIdx) > queue.at(parentIdx))
            {
                // Swap parent and max
                const int temp = queue.at(parentIdx);
                queue[parentIdx] = queue.at(maxIdx);
                queue[maxIdx] = temp;
                // Update parentIdx
                parentIdx = maxIdx;
            }
            else
                break;
        }
    }

public:
    int getSize()
    {
        return queue.size();
    }

    bool isEmpty()
    {
        return !queue.size();
    }

    void insert(int data)
    {
        queue.push_back(data);
        upHeapify();
        return;
    }

    int getMax()
    {
        if (!queue.size())
            return 0;
        return queue.at(0);
    }

    int removeMax()
    {
        const int size = queue.size();
        if (!size)
            return 0;

        const int ans = queue.at(0);
        queue[0] = queue.at(size - 1);
        queue[size - 1] = ans;

        queue.pop_back();
        downHeapify();
        return ans;
    }
};