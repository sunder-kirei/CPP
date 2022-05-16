#include <iostream>
using namespace std;

class dynamicArray
{
private:
    int size = 5;
    int index = 0;
    int *array = new int[5] {0};
    
public:
    dynamicArray()
    {
    }

    dynamicArray(int n)
    {
        size = n;
        array = new int[size];
    }

    dynamicArray(dynamicArray const &arr)
    {
        size = arr.size;
        index = arr.index;
        array = new int[size];
        for (int i = 0; i <= index; i++)
        {
            array[i] = arr.array[i];
        }
    }

    void operator= (dynamicArray const& arr)
    {
        size = arr.size;
        index = arr.index;
        array = new int[size];
        for (int i = 0; i <= index; i++)
        {
            array[i] = arr.array[i];
        }
        return;
    }

    int getsize() const
    {
        return size;
    }

    int getindex() const
    {
        return index;
    }

    void append(int n, int index = -1)
    {
        if (index == -1)
        {
            index = this->index;
        }
        else if (index > this->index)
        {
            return;
        }
        if (index < size)
        {
            array[index] = n;
            if (index == this->index)
            {
                this->index++;
            }
        }
        else
        {
            int *temp = new int[size * 2];
            for (int i = 0; i < size; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            size = size * 2;
            array[index] = n;
            if (index == this->index)
            {
                this->index++;
            }
        }
    }

    void operator+ (int n){
        append(n);
        return;
    }

    void operator+= (int n)
    {
        append(n);
        return;
    }

    int print(int index) const
    {
        return array[index];
    }
};