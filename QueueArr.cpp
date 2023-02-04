class Queue
{
    int* data;
    int entry;
    int exit;
    int size;

public:
    Queue(int n) {
        int* data = new int[n] {0};
        this->data = data;
        this->entry = 0;
        this->exit = -1;
        this->size = n;
    }

    void push(int data) {
        if (this->exit == -1)
        {
            this->data[this->entry] = data;
            this->entry++;
            this->exit = 0;
            return;
        }

        if (this->entry == this->size)
        {
            if (!this->exit)
                return;
            this->entry = 0;
        }

        this->data[this->entry] = data;
        this->entry++;
        return;
    }

    int pop()
    {
        if (this->exit == -1)
            return 0;

        if (this->entry == this->exit && !this->data[this->entry])
            return 0;

        if (this->entry < this->exit)
        {
            if (this->exit == this->size)
                this->exit = 0;
        }
        int ans = this->data[this->exit];
        this->data[this->exit++] = 0;
        return ans;
    }
};