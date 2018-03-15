#include <iostream>
#include <cstring>
#include <stdexcept>
#include "ResizingStack.h"
#include "Letter.h"

class Post
{
    ResizingStack<Letter> post;

public:
    void addLetter(Letter l)
    {
        char* fmi = strstr(l.get_content(), "FMI");
        if(strlen(l.get_content()) > 1281 || fmi != NULL)
            std::cerr << "The letter can not be longer than 1280 symbols and can not contain the word \"FMI\"!\n";
        else
        {
            post.push(l);
            std::cout << "A letter was received!\n";
        }
    }

    void sendLetter()
    {
        try
        {
            post.pop();
            std::cout << "A letter was sent!\n";
        }
        catch(std::range_error err)
        {
            std::cerr <<  "The post is empty!\n";
        }
    }

    bool postIsEmpty() const
    {
        post.isEmpty();
    }

    int postSize() const
    {
        return post.stackSize();
    }

    Letter postTop() const
    {
        return post.stackTop();
    }

    friend std::ostream& operator << (std::ostream& os, Post const& out)
    {
        os << out.post;

        return os;
    }
};
