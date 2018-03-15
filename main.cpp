#include <iostream>
#include <cstring>
#include <stdexcept>
#include "ResizingStack.cpp"
#include "ResizingQueue.cpp"
#include "Letter.h"
#include "Post.cpp"

using namespace std;

int main()
{
    //Stack
    cout << "--- Stack ---" << endl;
    ResizingStack<int> def;

    cout << def.stackSize() << endl;
    cout << def.isEmpty() << endl;

    try
    {
       def.stackSwap(1, 62);
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    try
    {
        def.pop();
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    try
    {
        cout << def.stackTop();
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    for(int i = 0; i < 60; i++)
       def.push(i);

    cout << "def: \n" << def << endl;
    cout << "def top: " << def.stackTop() << endl;
    cout << "def empty: " << def.isEmpty() << endl;
    cout << "def size: " <<def.stackSize() << endl;

    try
    {
       def.stackSwap(1, 62);
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    try
    {
       def.stackSwap(0, 3);
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    cout << "def: " << def << endl;

    ResizingStack<char*> random, imposter;
    random.push("I");
    random.push("love");
    random.push("Game");
    random.push("of");
    random.push("Thrones");
    imposter = random;

    cout << "random: \n" << random << endl;
    cout << "imposter: \n" << imposter << endl;

    cout << imposter.pop() << endl;
    cout << "imposter top: " << imposter.stackTop() << endl;
    cout << "imposter size: " << imposter.stackSize() << endl;
    imposter.pop();
    imposter.pop();
    imposter.push("Memes");
    imposter.stackSwapStack(random);

    cout << "random: \n" << random << endl;
    cout << "imposter: \n" << imposter << endl;

    ResizingStack<char*> other(random);
    cout << "other: \n" << other << endl;

    cout << "--- end stack ---" << endl << endl;


    //Queue
    cout << "--- Queue ---" << endl;
    ResizingQueue<int> deff;
    cout << "deff size: " << deff.queueSize() << endl;
    cout << "deff empty: " << deff.isEmpty() << endl;

    try
    {
        deff.pop();
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    try
    {
        cout << deff.getHead() << endl;
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    try
    {
        cout << deff.getTail() << endl;
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    for(int i = 0; i < 60; i++)
        deff.push(i);

    cout << "deff empty: " << deff.isEmpty() << endl;
    cout << "deff size: " << deff.queueSize() << endl;
    cout << "deff head: " << deff.getHead() << endl;
    cout << "deff tail : " << deff.getTail() << endl;

    try
    {
        deff.swapElements(-1, 5);
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    try
    {
        deff.swapElements(1, 62);
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    try
    {
        deff.swapElements(0, 3);
    }
    catch(range_error err)
    {
        cout << err.what() << endl;
    }

    cout << "deff: " << deff << endl;

    ResizingQueue<int> r;

    for(int i = 0; i < 30; i++)
        r.push(i);

    ResizingQueue<int> q = r;
    cout << "q: " << q << endl;
    cout << "q size: " << q.queueSize() << endl;
    cout << "q head: " << q.getHead() << endl;
    cout << "q tail: " << q.getTail() << endl;

    ResizingQueue<int> s(q);
    cout << "s: " << s << endl;
    cout << "s size: " << s.queueSize() << endl;
    cout << "s head: " << s.getHead() << endl;
    cout << "s tail: " << s.getTail() << endl;

    for(int i = 0; i < 15; i++)
        s.push(i + 5);

    s.swapQueue(r);
    cout << "s: " << s << endl;
    cout << "r: " << r << endl;

    cout << "--- end queue ---" << endl << endl;

    //Letter
    cout << "--- Letter ---" << endl;
    Letter a;
    cout << a << endl;

    a.set_receiver("John");
    a.set_content("Hello");
    cout << a << endl;

    Letter b("Jane", "Welcome to FMI");
    a = b;
    cout << a.get_receiver() << endl;
    cout << a.get_content() << endl;

    Letter c;
    c.set_receiver("Danny");
    c.set_content("How are you?");

    Letter d(c);
    cout << d << endl;

    cout << "--- end letter ---" << endl << endl;

    //Post
    cout << "--- Post ---" << endl;
    Post p;
    cout << "post empty: " << p.postIsEmpty() << endl;
    p.sendLetter();

    Letter l("Sam", "very important letter");
    for(int i = 0; i < 3; i++)
        p.addLetter(l);
    cout << "post size: " << p.postSize() << endl;
    cout << p.postTop() << endl;

    p.addLetter(b);

    Post w;
    w = p;
    cout << w << endl;

    return 0;
}
