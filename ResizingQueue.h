#ifndef RESIZINGQUEUE_H
#define RESIZINGQUEUE_H

#include <iostream>

const int QUEUE_INI = 50;

template <typename T>
class ResizingQueue
{
    T* myQueue;
    int head, tail;
    long capacity, qSize;

    bool isFull() const;

    void resizeQueue(int);

    void copyQueue(ResizingQueue const&);

    void eraseQueue();

public:
    ResizingQueue();

    ResizingQueue(ResizingQueue const&);

    ResizingQueue& operator=(ResizingQueue const&);

    ~ResizingQueue();

    bool isEmpty() const;

    void push(T const&);

    T pop();

    T getHead() const;

    T getTail() const;

    long queueSize() const;

    void swapElements(int, int);

    void swapQueue(ResizingQueue&);

    friend std::ostream& operator <<(std::ostream& os, ResizingQueue const& out)
    {
        if(out.isEmpty())
        {
            std::cerr << "Empty queue!\n";
            return os;
        }
        else
        {
            os << out.myQueue[out.head];

            if(out.head < out.tail)
            {
                for(int i = out.head + 1; i <= out.tail; i++)
                    os << ", " << out.myQueue[i];
            }
            if(out.head > out.tail)
            {
                for(int i = out.head + 1; i < out.capacity; i++)
                    os << ", " << out.myQueue[i];

                for(int i = 0; i <= out.tail; i++)
                    os << ", " << out.myQueue[i];
            }
        }

        return os;
    }
};

#endif // RESIZINGQUEUE_H
