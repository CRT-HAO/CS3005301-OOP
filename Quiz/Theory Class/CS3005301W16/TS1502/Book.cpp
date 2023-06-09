#include "Book.hpp"

#include "Author.hpp"

// Book::Book(const std::string &name) : name(name) {}

Book::Book(const std::string &name, Author *author) : name(name), author(author)
{
}

void Book::addEdition(int edition) { this->editions.insert(edition); }

void Book::removeEdition(int edition) { this->editions.erase(edition); }

bool Book::hasEdition(int edition) const
{
    return (this->editions.find(edition) != this->editions.end());
}

bool Book::noEditions() const { return this->editions.size() == 0; }