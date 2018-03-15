#ifndef RESIZINGSTACK_H
#define RESIZINGSTACK_H

#include <iostream>

const int STACK_INI = 50;

template <typename T>
class ResizingStack
{
    T* sArr;
    int top;
    int capacity;

    void resizeStack();

public:
    ResizingStack();

    ResizingStack(ResizingStack const&);

    ResizingStack& operator=(ResizingStack const&);

    ~ResizingStack();

    bool isEmpty() const;

    void push(T const&);

    T pop();

    T stackTop() const;

    int stackSize() const;

    void stackSwap(int, int);

    void stackSwapStack(ResizingStack&);

    friend std::ostream& operator <<(std::ostream& os, ResizingStack const& out)
    {
        if(out.top == -1)
        {
            std::cerr << "Stack is empty!\n";
        }
        else
        {
            for(int i = 0; i < out.top + 1; i++)
            {
                os << out.sArr[i] << "\n";
            }
        }

        return os;
    }
};

#endif // RESIZINGSTACK_H
