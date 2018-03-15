#include "ResizingStack.h"
#include <iostream>
#include <stdexcept>

template <typename T>
ResizingStack<T>::ResizingStack()
{
    top = -1;
    capacity = STACK_INI;
    sArr = new T[capacity];
}

template <typename T>
ResizingStack<T>::ResizingStack(ResizingStack const& other)
{
    capacity = other.capacity;
    top = other.top;
    sArr = new T[capacity];

    for(int i = 0; i < top + 1; i++)
    {
        sArr[i] = other.sArr[i];
    }
}

template <typename T>
ResizingStack<T>::~ResizingStack()
{
    delete [] sArr;
}

template <typename T>
ResizingStack<T>& ResizingStack<T>::operator =(ResizingStack const& other)
{
    if(this != &other)
    {
        delete [] sArr;

        capacity = other.capacity;
        top = other.top;
        sArr = new T[capacity];
        for(int i = 0; i < top + 1; i++)
        {
            sArr[i] = other.sArr[i];
        }
    }

    return *this;
}

template <typename T>
bool ResizingStack<T>::isEmpty() const
{
    return top == -1;
}

template <typename T>
void ResizingStack<T>::resizeStack()
{
    T* temp = new T[capacity * 2];
    for(int i = 0; i < top + 1; i++)
    {
        temp[i] = sArr[i];
    }
    capacity *= 2;
    sArr = new T[capacity];
    for(int i = 0; i < top + 1; i++)
    {
        sArr[i] = temp[i];
    }
    delete[] temp;
}

template <typename T>
void ResizingStack<T>::push(T const& value)
{
    if(top == capacity - 1)
    {
        resizeStack();
    }

    sArr[++top] = value;
}

template <typename T>
T ResizingStack<T>::pop()
{
    if(isEmpty())
    {
        throw std::range_error("The stack is empty!");
    }

    return sArr[top--];
}

template <typename T>
T ResizingStack<T>::stackTop() const
{
    if(isEmpty())
    {
        throw std::range_error("The stack is empty!");
    }

    return sArr[top];
}

template <typename T>
int ResizingStack<T>::stackSize() const
{
    return top + 1;
}

template <typename T>
void ResizingStack<T>::stackSwap(int first, int second)
{
    if(first < 0 || first > top || second < 0 || second > top)
    {
        throw std::range_error("Invalid index!");
    }
    else
    {
        T temp = sArr[first];
        sArr[first] = sArr[second];
        sArr[second] = temp;
    }
}

template <typename T>
void ResizingStack<T>::stackSwapStack(ResizingStack& other)
{
   int temp_len;
    if(top > other.top)
    {
        temp_len = top;
    }
    else
    {
        temp_len = other.top;
    }

    T* temp;
    temp = new T[temp_len + 1];

    if(top > other.top)
    {
        for(int i = 0; i < top + 1; i++)
        {
            temp[i] = sArr[i];
        }
        for(int i = 0; i < other.top + 1; i++)
        {
            sArr[i] = other.sArr[i];
        }
        top = other.top;
        other.top = temp_len;
        for(int i = 0; i < other.top + 1; i++)
        {
            other.sArr[i] = temp[i];
        }
    }
    else
    {
        for(int i = 0; i < other.top + 1; i++)
        {
            temp[i] = other.sArr[i];
        }
        for(int i = 0; i < top + 1; i++)
        {
            other.sArr[i] = sArr[i];
        }
        other.top = top;
        top = temp_len;
        for(int i = 0; i < top + 1; i++)
        {
            sArr[i] = temp[i];
        }
    }
}
