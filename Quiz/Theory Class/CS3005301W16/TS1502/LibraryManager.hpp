#pragma once

#include "Author.hpp"
#include "Book.hpp"

#include <set>
#include <vector>

class LibraryManager
{
private:
    std::set<Author *> authors;

public:
    LibraryManager() {}

public:
    bool insert(const std::string &name, const std::string &author, int edition)
    {
        Author *a = this->findAuthor(author);

        // If the author not found, create a new one
        if ( a == nullptr )
        {
            a = new Author(author);
            this->authors.insert(a);
        }

        Book *b = a->findBook(name);

        // If the book not found, create a new one
        if ( b == nullptr )
        {
            b = new Book(name, a);
            a->addBook(b);
        }

        if ( b->hasEdition(edition) )
            return false;

        b->addEdition(edition);
        return true;
    }

    bool deleteEdition(const std::string &name, const std::string &author,
                       int edition)
    {
        Author *a = this->findAuthor(author);

        // If the author not found,
        if ( a == nullptr )
            return false;

        Book *b = this->findBook(name, author);

        // If the book not found
        if ( b == nullptr )
            return false;

        if ( !b->hasEdition(edition) )
            return false;

        b->removeEdition(edition);

        // If there are no any editions in the book, delete it
        if ( b->noEditions() )
        {
            a->removeBook(b);
            delete b;
        }

        return true;
    }

    bool deleteBook(const std::string &name, const std::string &author)
    {
        Author *a = this->findAuthor(author);

        // If the author not found
        if ( a == nullptr )
            return false;

        Book *b = a->findBook(name);

        // If the book not found
        if ( b == nullptr )
            return false;

        a->removeBook(b);
        delete b;

        return true;
    }

    Author *findAuthor(const std::string &name)
    {
        for ( const auto &author : authors )
        {
            if ( author->getName() == name )
                return author;
        }
        return nullptr;
    }

    Book *findBook(const std::string &name, Author *author)
    {
        if ( author == nullptr )
            return nullptr;

        return author->findBook(name);
    }

    Book *findBook(const std::string &name, const std::string &author)
    {
        Author *a = this->findAuthor(author);

        // If the author not found
        if ( a == nullptr )
            return nullptr;

        return a->findBook(name);
    }

    std::vector<Author *> getAuthors()
    {
        std::vector<Author *> r;
        for ( const auto &author : authors )
            r.push_back(author);

        return r;
    }

    std::vector<Book *> getBooks()
    {
        std::vector<Book *> r;
        for ( const auto &author : this->getAuthors() )
        {
            for ( const auto &book : author->getBooks() )
                r.push_back(book);
        }

        return r;
    }
};