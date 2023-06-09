#include "Author.hpp"
#include "Book.hpp"

Author::Author(const std::string &name) : name(name) {}

void Author::addBook(Book *book) { this->books.insert(book); }

void Author::removeBook(Book *book) { this->books.erase(book); }

bool Author::noBook() { return (this->books.size() == 0); }

Book *Author::findBook(const std::string &name)
{
    for ( const auto &book : this->books )
    {
        if ( book->getName() == name )
            return book;
    }
    return nullptr;
}

const std::set<Book *> &Author::getBooks() const { return this->books; }
