#pragma once
#include <exception>
using namespace std;

template <class T>
class ArrayList {

    T* InternalArray;
    int size;
    int capacity;

    void ResizeArray()
    {
        T* temp = new T[capacity + 10];
            
        for (int i = 0; i < size; i++)
        {
            temp[i] = InternalArray[i];
        }

        delete[] InternalArray;
        InternalArray = temp;
        capacity += 10;
    }

public:

    ArrayList(int capacity = 10) {
        size = 0;
        this->capacity = capacity;
        InternalArray = new T[capacity];
    }

    ~ArrayList() {
        delete[] InternalArray;
        InternalArray = nullptr;
    }

    void Add(T X)
    {
        if (size >= capacity)
        {
            ResizeArray();
        }
        InternalArray[size++] = X;
    }

    T& operator[](int i)
    {
        if (i >= size || i < 0)
        {
            throw exception("Out of range.");
        }
        return InternalArray[i];
    }

    int GetSize() {
        return size;
    }

    int GetCapacity() {
        return capacity;
    }

    void Insert(int index, T item)
    {
        if (index < 0 || index > size)
        {
            throw exception("Index out of bounds.");
        }

        if (size >= capacity)
        {
            ResizeArray();
        }

        for (int i = size; i > index; i--)
        {
            InternalArray[i] = InternalArray[i - 1];
        }
        InternalArray[index] = item;
        size++;
    }

    void Delete(int index)
    {
        if (index < 0 || index >= size)
        {
            throw exception("Index out of bounds.");
        }

        for (int i = index; i < size - 1; i++)
        {
            InternalArray[i] = InternalArray[i + 1];
        }
        size--;
    }
};