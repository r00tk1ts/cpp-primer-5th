#ifndef EX14_5_H
#define EX14_5_H

#include <iostream>
#include <string>

class Book {
    friend std::istream& operator>>(std::istream&, Book&);
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);

public:
    Book() = default;
    Book(unsigned _no, std::string _name, std::string _author, std::string _pubdate):no(_no), name(_name), author(_author), pubdate(_pubdate) { }
    Book(std::istream &in) { in >> *this; }
    explicit operator bool(){ return true; }
private:
    unsigned no;
    std::string name;
    std::string author;
    std::string pubdate;
};

std::istream& operator>>(std::istream&, Book&);
std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);


#endif