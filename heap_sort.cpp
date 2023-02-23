#include <bits/stdc++.h>
using namespace std;

void upHeapify(int arr[], int ei)
{
    int childIdx = ei;

    while (childIdx)
    {
        int parentIdx = (childIdx - 1) / 2;
        if (arr[parentIdx] < arr[childIdx])
        {
            // Swap parent with child
            const int temp = arr[parentIdx];
            arr[parentIdx] = arr[childIdx];
            arr[childIdx] = temp;
            // Update childIdx
            childIdx = parentIdx;
        }
        else
            break;
    }
    return;
}

void downHeapify(int arr[], int ei)
{
    int parentIdx = 0;
    const int size = ei;

    while (parentIdx < ei)
    {
        int left = 2 * parentIdx + 1;
        int right = 2 * parentIdx + 2;

        if (right > size)
        {
            right = left;
        }
        if (left > size)
        {
            left = right = parentIdx;
        }
        const int maxIdx = arr[left] > arr[right] ? left : right;
        if (arr[maxIdx] > arr[parentIdx])
        {
            // Swap parent with child
            const int temp = arr[parentIdx];
            arr[parentIdx] = arr[maxIdx];
            arr[maxIdx] = temp;
            // Update childIdx
            parentIdx = maxIdx;
        }
        else
            break;
    }
    return;
}

void heapSort(int arr[], int n)
{
    int i = 0;
    // Upheapify the array one at a time;
    while (i < n)
    {
        upHeapify(arr, i);
        i++;
    }
    // Here i = n
    // place the top of the heap at the end, and then downHeapify the remaining array one at a time
    while (i > 0)
    {
        const int ei = i - 1;
        // Swap the top of the heap with the last element
        const int temp = arr[ei];
        arr[ei] = arr[0];
        arr[0] = temp;
        // Downheapify the rest of the array, except the last element
        downHeapify(arr, ei - 1);
        i--;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int i = 0;
    while (i < n)
    {
        cin >> arr[i];
        i++;
    }
    heapSort(arr, n);
    i = 0;
    while (i < n)
    {
        cout << arr[i++] << " ";
    }
    cout << endl;
    return 0;
}