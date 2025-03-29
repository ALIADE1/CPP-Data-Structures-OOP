#pragma once
#include <iostream>
using namespace std;

template<class T>
struct Node
{
    T value;
    Node<T>* next;

    Node(T val) : value(val), next(nullptr) {}
};

template<class T>
class LinkedList
{
private:
    Node<T>* head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}

    ~LinkedList()
    {
        Node<T>* current = head;
        while (current)
        {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    void Add(T item)
    {
        Node<T>* temp = new Node<T>(item);
        temp->next = head;
        head = temp;
        count++;
    }

    void PrintAll()
    {
        Node<T>* temp = head;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    int GetCount() const
    {
        return count;
    }
};
