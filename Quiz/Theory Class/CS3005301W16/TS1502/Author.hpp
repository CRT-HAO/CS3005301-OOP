#pragma once

#include <set>
#include <string>

class Book;

class Author
{

private:
    std::string name;
    std::set<Book *> books;

public:
    Author(const std::string &name);

public:
    inline const std::string &getName() const { return this->name; }

public:
    void addBook(Book *book);
    void removeBook(Book *book);
    bool noBook();
    Book *findBook(const std::string &name);
    const std::set<Book *> &getBooks() const;
};