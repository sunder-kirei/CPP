#include <iostream>
using namespace std;

class polynomial
{
private:
    int size;
    int *array;

public:
    polynomial(int size)
    {
        this->size = size;
        array = new int[size]{0};
    }

    polynomial()
    {
        size = 5;
        array = new int[size]{0};
    }

    polynomial(polynomial const &p)
    {
        this->size = p.size;
        this->array = new int[size]{0};
        for (int i = 0; i < size; i++)
        {
            this->array[i] = p.array[i];
        }
    }

    polynomial operator=(polynomial const &p)
    {
        this->size = p.size;
        this->array = new int[size]{0};
        for (int i = 0; i < size; i++)
        {
            this->array[i] = p.array[i];
        }
        return *this;
    }

    void setCoefficient(int coef, int power)
    {
        if (power < size)
        {
            array[power] = coef;
        }
        else
        {
            int *temp = new int[2 * size]{0};
            for (int i = 0; i < size; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            size *= 2;
            array[power] = coef;
        }
        return;
    }

    int getCoefficient(int index) const
    {
        return array[index];
    }

    polynomial operator+(polynomial const &p) const
    {
        int temp, smaller;
        int *tempArr;
        if (this->size >= p.size)
        {
            temp = this->size;
            smaller = p.size;
            tempArr = this->array;
        }
        else
        {
            temp = p.size;
            smaller = this->size;
            tempArr = p.array;
        }
        polynomial ans(temp);
        int i = 0, j = 0;
        while (i < smaller)
        {
            ans.array[i] = p.array[i] + this->array[i];
            i++;
            j++;
        }
        while (j < temp)
        {
            ans.array[j] = tempArr[j];
            j++;
        }

        return ans;
    }

    polynomial operator-(polynomial const &p) const
    {
        int temp, smaller;

        if (this->size >= p.size)
        {
            temp = this->size;
            smaller = p.size;
        }
        else
        {
            temp = p.size;
            smaller = this->size;
        }
        polynomial ans(temp);
        int i = 0;
        while (i <= temp)
        {
            if (i < size && i < p.size)
            {
                ans.array[i] = this->array[i] - p.array[i];
                i++;
            }
            else if (i > size)
            {
                ans.array[i] = 0 - p.array[i];
                i++;
            }
            else
            {
                ans.array[i] = array[i];
                i++;
            }
        }
        return ans;
    }

    void print() const
    {
        int i = 0;
        while (i < this->size)
        {
            if (array[i] != 0)
            {
                cout << array[i] << 'x' << i << ' ';
            }
            i++;
        }
        cout << endl;
        return;
    }

    polynomial operator*(polynomial const &p) const
    {
        int temp = this->size + p.size +1;
        polynomial ans(temp);
        int i = 0, j = 0;
        while (i < this -> size)
        {
            j = 0;
            while (j < p.size)
            {
                ans.array[i+j] += (array[i] * p.array[j]);
                j++;
            }
            i++;
        }

        return ans;
    }
};