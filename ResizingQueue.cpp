#include "ResizingQueue.h"
#include <iostream>
#include <stdexcept>

template <typename T>
ResizingQueue<T>::ResizingQueue()
{
    head = 0;
    tail = -1;
    capacity = QUEUE_INI;
    qSize = 0;
    myQueue = new T[capacity];
}

template <typename T>
bool ResizingQueue<T>::isEmpty() const
{
    return tail == -1;
}

template <typename T>
bool ResizingQueue<T>::isFull() const
{
    return qSize == capacity;
}

template <typename T>
T ResizingQueue<T>::getHead() const
{
    if(isEmpty())
    {
        throw std::range_error("The stack is empty!");
    }

    return myQueue[head];
}

template <typename T>
T ResizingQueue<T>::getTail() const
{
    if(isEmpty())
    {
        throw std::range_error("The stack is empty!");
    }

    return myQueue[tail];
}

template <typename T>
long ResizingQueue<T>::queueSize() const
{
    return qSize;
}

template <typename T>
void ResizingQueue<T>::push(T const& newElement)
{
    if(isFull())
    {
        resizeQueue(capacity * 2);
    }

    if(tail == capacity - 1)
    {
        tail = 0;
        myQueue[tail] = newElement;
    }
    else
        myQueue[++tail] = newElement;

    qSize++;
}

template <typename T>
T ResizingQueue<T>::pop()
{
    if(isEmpty())
    {
        throw std::range_error("The stack is empty!");
    }

    T element = myQueue[head];

    if(head == tail)
    {
        head = 0;
        tail = -1;
    }
    else if(head == capacity - 1)
        head = 0;
    else
        head++;

    qSize--;

    if(qSize <= capacity / 4 && capacity > QUEUE_INI)
        resizeQueue(capacity / 2);

    return element;
}

template <typename T>
void ResizingQueue<T>::copyQueue(ResizingQueue const& other)
{
    head = other.head;
    tail = other.tail;
    capacity = other.capacity;
    qSize = other.qSize;
    myQueue = new T[capacity];

    if(head < tail)
    {
        for(int i = head; i <= tail; i++)
            myQueue[i] = other.myQueue[i];
    }
    else
    {
        for(int i = head; i < capacity; i++)
            myQueue[i] = other.myQueue[i];

        for(int i = 0; i <= tail; i++)
            myQueue[i] = other.myQueue[i];
    }
}

template <typename T>
ResizingQueue<T>::ResizingQueue(ResizingQueue const& other)
{
    copyQueue(other);
}

template <typename T>
void ResizingQueue<T>::swapElements(int first, int second)
{
    if(first < 0 || second < 0 || first < head || second > tail)
    {
        throw std::range_error("Invalid index!");
    }
    else
    {
        int temp = myQueue[first];
        myQueue[first] = myQueue[second];
        myQueue[second] = temp;
    }
}

template <typename T>
void ResizingQueue<T>::swapQueue(ResizingQueue& other)
{
    ResizingQueue<T> temp = other;
    other = *this;
    *this = temp;
}

template <typename T>
ResizingQueue<T>& ResizingQueue<T>::operator=(ResizingQueue const& other)
{
    if(this != &other)
    {
        eraseQueue();
        copyQueue(other);
    }

    return *this;
}

template <typename T>
void ResizingQueue<T>::resizeQueue(int newLenght)
{
    T* temp = myQueue;
    myQueue = new T[newLenght];

    if(head < tail)
    {
        for(int i = head; i <= tail; i++)
            myQueue[i - head] = temp[i];
    }
    else
    {
        int index = 0;
        for(int i = head; i < capacity; i++)
            myQueue[index++] = temp[i];

        for(int i = 0; i <= tail; i++)
            myQueue[index++] = temp[i];
    }

    head = 0;
    tail = queueSize() - 1;
    capacity = newLenght;

    delete[] temp;
}

template <typename T>
void ResizingQueue<T>::eraseQueue()
{
    delete[] myQueue;
}

template <typename T>
ResizingQueue<T>::~ResizingQueue()
{
    eraseQueue();
}
