#include <string>
using namespace std;

template <typename T>
class map_data
{
public:
    T data;
    string key;
    map_data *next;

    map_data(string key, T data)
    {
        this->key = key;
        this->data = data;
        next = NULL;
    }

    ~map_data()
    {
        delete next;
    }
};

template <typename T>
class hash_map
{
    map_data<T> **bucket_arr;
    int size;
    int count;

    int hashing_function(string key)
    {
        int index = 0;
        int current_coeffecient = 19;
        for (int i = 0; i < key.length(); i++)
        {
            index += (int)key[i] * current_coeffecient;
            index %= size;
            current_coeffecient *= 19;
            current_coeffecient %= size;
        }
        index %= size;
        return index;
    }

    void rehashing_function()
    {
        int old_size = size;
        this->size = (2 * size);
        this->count = 0;
        auto new_bucket = new map_data<T> *[size];
        for (int i = 0; i < size; i++)
        {
            new_bucket[i] = NULL;
        }
        auto old_bucket = bucket_arr;
        this->bucket_arr = new_bucket;

        for (int i = 0; i < old_size; i++)
        {
            auto head = old_bucket[i];
            while (head != NULL)
            {
                insert(head->key, head->data);
                head = head->next;
            }
        }

        for (int i = 0; i < old_size; i++)
        {
            delete old_bucket[i];
        }
        delete[] old_bucket;
        return;
    }

    double get_load_factor()
    {
        return (1.0 * count) / size;
    }

public:
    hash_map()
    {
        size = 20;
        bucket_arr = new map_data<T> *[size];
        for (int i = 0; i < size; i++)
        {
            bucket_arr[i] = NULL;
        }
        count = 0;
    }

    ~hash_map()
    {
        for (int i = 0; i < size; i++)
        {
            delete bucket_arr[i];
        }
        delete[] bucket_arr;
    }

    void insert(string key, T value)
    {
        int index = hashing_function(key);
        map_data<T> *newNode = new map_data<T>(key, value);
        auto head = bucket_arr[index];
        while (head != NULL && head->key != key)
        {
            head = head->next;
        }
        if (head == NULL)
        {
            newNode->next = bucket_arr[index];
            bucket_arr[index] = newNode;
        }
        else
        {
            head->data = value;
        }
        count++;
        if (get_load_factor() > 0.7)
        {
            rehashing_function();
        }
        return;
    }

    T getData(string key)
    {
        int index = hashing_function(key);
        if (bucket_arr[index] == NULL)
            return 0;

        auto head = bucket_arr[index];
        while (head != NULL && head->key != key)
        {
            head = head->next;
        }
        if (head == NULL)
        {
            return 0;
        }
        return head->data;
    }

    void removeData(string key)
    {
        auto index = hashing_function(key);
        auto head = bucket_arr[index];
        auto prev = head;
        while (head != NULL && head->key != key)
        {
            prev = head;
            head = head->next;
        }
        if (head == NULL)
            return;
        prev->next = head->next;
        head->next = NULL;
        delete head;
        return;
    }
};