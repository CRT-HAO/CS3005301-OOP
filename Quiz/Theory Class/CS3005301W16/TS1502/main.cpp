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
    char first;
    if ( iss >> first && first == '"' )
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
            if ( name.empty() || author.empty() || edition.empty() )
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
                if ( name.empty() || author.empty() || edition.empty() )
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
                if ( name.empty() || author.empty() )
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
                if ( name.empty() || author.empty() )
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
                    for ( const int &e : book->getEditions() )
                    {
                        cout << e;
                        if ( e != *book->getEditions().end() )
                            cout << ", ";
                    }
                    cout << "." << endl;
                }
                else
                    cout << "Book doesn't exist." << endl;
            }
            else if ( subAction == "Author" )
            {
                string author = parseArg(iss);
                if ( author.empty() )
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
                        for ( const auto &book : a->getBooks() )
                        {
                            cout << book->getName();
                            if ( book != *a->getBooks().end() )
                                cout << ", ";
                        }
                        cout << "." << endl;
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
            string by;
            iss >> by;
            string sortBy = parseArg(iss);
            if ( sortBy.empty() )
            {
                cout << "Incomplete Command." << endl;
                continue;
            }
            if ( sortBy == "title" )
            {
                vector<Book *> books = library.getBooks();

                sort(books.begin(), books.end(),
                     [](Book *a, Book *b) -> bool {return a->getName()[0] > b->getName()[0];});
            }
            else if ( sortBy == "author" )
            {
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