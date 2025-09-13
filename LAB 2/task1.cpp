#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int *arr;
    int size;
    int capacity;

    void resize()
    {
        capacity *= 2;
        int *newArr = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

public:
    DynamicArray(int initCapacity = 2)
    {
        capacity = initCapacity;
        size = 0;
        arr = new int[capacity];
    }

    ~DynamicArray()
    {
        delete[] arr;
    }

    void push_back(int value)
    {
        if (size == capacity)
        {
            resize();
        }
        arr[size++] = value;
    }

    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray da;

    da.push_back(10);
    da.push_back(20);
    da.push_back(30);
    da.push_back(40);

    cout << "Array elements: ";
    da.print();

    return 0;
}
