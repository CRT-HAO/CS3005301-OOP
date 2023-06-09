// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: June 10, 2023
// Last Update: June 10, 2023
// Problem statement: Library Database

#include "LibraryManager.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

// (1)	Insert: Insert "title" "author" "edition"
// (2)	Delete Edition: Delete Edition "title" "author" "edition"
// (3)	Delete Book: Delete Book "title" "author"
// (4)	Find Book: Find Book "title" "author"
// (5)	Find Author: Find Author "author"
// (6)	Sort by Title: Sort by "title"
// (7)	Sort by Author: Sort by "author"

string parseArg(istringstream &iss)
{
    string arg;
    char first = 0;

    if ( iss.eof() )
        return arg;

    if ( (iss >> first) && first == '"' )
    {
        getline(iss, arg, '"');
    }
    else
    {
        getline(iss, arg, ' ');
        arg = first + arg;
    }
    return arg;
}

int main()
{
    LibraryManager library;

    // Read command, until EOF
    for ( string command; getline(cin, command) && !cin.eof(); )
    {
        istringstream iss(command);
        string action;
        iss >> action;

        if ( action == "Insert" )
        {
            string name = parseArg(iss);
            string author = parseArg(iss);
            string edition = parseArg(iss);
            if ( name.length() <= 0 || author.length() <= 0 ||
                 edition.length() <= 0 )
            {
                cout << "Incomplete Command." << endl;
                continue;
            }

            bool success = library.insert(name, author, stoi(edition));

            if ( success )
                cout << "Insert " << author << "'s " << name
                     << ", Edition: " << edition << "." << endl;
            else
                cout << "Datum already exist." << endl;
        }
        else if ( action == "Delete" )
        {
            string subAction;
            iss >> subAction;
            if ( subAction == "Edition" )
            {
                string name = parseArg(iss);
                string author = parseArg(iss);
                string edition = parseArg(iss);
                if ( name.length() <= 0 || author.length() <= 0 ||
                     edition.length() <= 0 )
                {
                    cout << "Incomplete Command." << endl;
                    continue;
                }

                bool success =
                    library.deleteEdition(name, author, stoi(edition));

                if ( success )
                    cout << "Delete " << author << "'s " << name
                         << ", Edition: " << edition << "." << endl;
                else
                    cout << "Datum doesn't exist." << endl;
            }
            else if ( subAction == "Book" )
            {
                string name = parseArg(iss);
                string author = parseArg(iss);
                if ( name.length() <= 0 || author.length() <= 0 )
                {
                    cout << "Incomplete Command." << endl;
                    continue;
                }

                bool success = library.deleteBook(name, author);

                if ( success )
                    cout << "Delete " << author << "'s " << name << "." << endl;
                else
                    cout << "Book doesn't exist." << endl;
            }
            else
            {
                cout << "Unknown Command." << endl;
                continue;
            }
        }
        else if ( action == "Find" )
        {
            string subAction;
            iss >> subAction;
            if ( subAction == "Book" )
            {
                string name = parseArg(iss);
                string author = parseArg(iss);
                if ( name.length() <= 0 || author.length() <= 0 )
                {
                    cout << "Incomplete Command." << endl;
                    continue;
                }

                Book *book = library.findBook(name, author);

                if ( book != nullptr )
                {
                    cout << "Title: " << book->getName() << "\t"
                         << "Author: " << book->getAuthor()->getName() << "\t"
                         << "Edition: ";
                    size_t i = 0, n = book->getEditions().size();
                    for ( const int &e : book->getEditions() )
                    {
                        cout << e;
                        if ( i != n - 1 )
                            cout << ", ";
                        ++i;
                    }
                    cout << endl;
                }
                else
                    cout << "Book doesn't exist." << endl;
            }
            else if ( subAction == "Author" )
            {
                string author = parseArg(iss);
                if ( author.length() <= 0 )
                {
                    cout << "Incomplete Command." << endl;
                    continue;
                }

                Author *a = library.findAuthor(author);

                if ( a != nullptr )
                {
                    if ( !a->noBook() )
                    {
                        cout << a->getName() << "'s Books: ";

                        vector<Book *> books(a->getBooks().begin(),
                                             a->getBooks().end());

                        sort(books.begin(), books.end(),
                             [](Book *a, Book *b) -> bool
                             { return a->getName() < b->getName(); });

                        size_t i = 0, n = books.size();
                        for ( const auto &book : books )
                        {
                            cout << book->getName();
                            if ( i != n - 1 )
                                cout << ", ";
                            ++i;
                        }
                        cout << endl;
                    }
                    else
                        cout << "No book found." << endl;
                }
                else
                    cout << "No book found." << endl;
            }
            else
            {
                cout << "Unknown Command." << endl;
                continue;
            }
        }
        else if ( action == "Sort" )
        {
            string by, sortBy;
            iss >> by >> sortBy;
            if ( sortBy == "Title" )
            {
                vector<Book *> books = library.getBooks();

                sort(books.begin(), books.end(),
                     [](Book *a, Book *b) -> bool
                     {
                         if ( a->getName()[0] == b->getName()[0] )
                         {
                             return a->getAuthor()->getName()[0] <
                                    b->getAuthor()->getName()[0];
                         }
                         else
                             return a->getName()[0] < b->getName()[0];
                     });

                for ( const auto &book : books )
                {
                    cout << "Title: " << book->getName() << "\t"
                         << "Author: " << book->getAuthor()->getName() << "\t"
                         << "Edition: ";

                    size_t i = 0, n = book->getEditions().size();
                    for ( const int &e : book->getEditions() )
                    {
                        cout << e;
                        if ( i != n - 1 )
                            cout << ", ";
                        ++i;
                    }
                    cout << endl;
                }
            }
            else if ( sortBy == "Author" )
            {
                vector<Book *> books = library.getBooks();

                sort(books.begin(), books.end(),
                     [](Book *a, Book *b) -> bool
                     {
                         if ( a->getAuthor()->getName()[0] ==
                              b->getAuthor()->getName()[0] )
                         {
                             return a->getName()[0] < b->getName()[0];
                         }
                         else
                             return a->getAuthor()->getName()[0] <
                                    b->getAuthor()->getName()[0];
                     });

                for ( const auto &book : books )
                {
                    cout << "Title: " << book->getName() << "\t"
                         << "Author: " << book->getAuthor()->getName() << "\t"
                         << "Edition: ";

                    size_t i = 0, n = book->getEditions().size();
                    for ( const int &e : book->getEditions() )
                    {
                        cout << e;
                        if ( i != n - 1 )
                            cout << ", ";
                        ++i;
                    }
                    cout << endl;
                }
            }
            else
            {
                cout << "Unknown Command." << endl;
                continue;
            }
        }
        else
        {
            cout << "Unknown Command." << endl;
            continue;
        }
    }

    return 0;
}