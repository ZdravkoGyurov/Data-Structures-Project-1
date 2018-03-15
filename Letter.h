#ifndef LETTER_H
#define LETTER_H

#include <iostream>

const int MAX_NAME = 50;
const int MAX_CONTENT = 2000;

class Letter
{
    char* receiver;
    char* content;

    void copy_letter(Letter const&);

public:

    Letter();

    Letter(char const*, char const*);

    Letter(Letter const&);

    ~Letter();

    Letter& operator=(Letter const&);

    char* get_receiver() const { return receiver; }

    char* get_content() const { return content; }

    void set_receiver(char const*);

    void set_content(char const*);

    friend std::ostream& operator<<(std::ostream& os, Letter const& out)
    {
        os << "To: " << out.get_receiver() << "\n";
        os << out.get_content();

        return os;
    }

    friend std::istream& operator>>(std::istream& is, Letter& in)
    {
        char receiver[MAX_NAME];
        char content[MAX_CONTENT];
        is.getline(receiver, MAX_NAME);
        is.getline(content, MAX_CONTENT);
        in.set_receiver(receiver);
        in.set_content(content);

        return is;
    }
};

#endif // LETTER_H
