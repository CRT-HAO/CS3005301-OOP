#pragma once

#include <set>
#include <string>

class Author;

class Book
{
private:
    std::string name;
    Author *author;
    std::set<int> editions;

public:
    // Book(const std::string &name);
    Book(const std::string &name, Author *author);

public:
    inline const std::string &getName() const { return this->name; }
    inline const std::set<int> &getEditions() const { return this->editions; }
    inline const Author *getAuthor() const { return this->author; }

public:
    void addEdition(int edition);
    void removeEdition(int edition);
    bool hasEdition(int edition) const;
    bool noEditions() const;
};