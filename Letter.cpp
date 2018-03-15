#include "Letter.h"
#include <cstring>

Letter::Letter()
{
   receiver = new char[MAX_NAME];
   receiver = "Unknown";
   content = new char[MAX_CONTENT];
   content = "This letter is empty";
}

Letter::Letter(char const* _receiver, char const* _content)
{
    receiver = new char[strlen(_receiver) + 1];
    strcpy(receiver, _receiver);

    content = new char[strlen(_content) + 1];
    strcpy(content, _content);
}

Letter::Letter(Letter const& other)
{
    copy_letter(other);
}

Letter::~Letter()
{
    delete[] receiver;
    delete[] content;
}

void Letter::copy_letter(Letter const& other)
{
    receiver = new char[strlen(other.receiver) + 1];
    strcpy(receiver, other.receiver);

    content = new char[strlen(other.content) + 1];
    strcpy(content, other.content);
}

Letter& Letter::operator=(Letter const& other)
{
    if(this != &other)
    {
        delete[] receiver;
        delete[] content;

        copy_letter(other);
    }

    return *this;
}

void Letter::set_receiver(char const* _receiver)
{
    delete [] receiver;
    receiver = new char[strlen(_receiver) + 1];
    strcpy(receiver, _receiver);
}

void Letter::set_content(char const* _content)
{
    delete [] content;
    content = new char[strlen(_content)+1];
    strcpy(content, _content);
}
