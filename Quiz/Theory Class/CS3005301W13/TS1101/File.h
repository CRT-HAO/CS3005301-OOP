// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 21, 2023
// Last Update: May 21, 2023
// Problem statement: Class Inheritance

#pragma once

#include "Document.h"

#include <string>

class File : public Document
{
private:
    std::string pathname; // The pathname of the file

public:
    File() {} // Default constructor

    // Intent: Constructor that accepts text and pathname parameters
    // Pre: The text parameter contains the text to assign to the file
    //      The pathname parameter contains the pathname of the file
    // Post: Creates a new File object with the provided text and pathname
    File(const std::string &text, const std::string &pathname)
        : Document(text), pathname(pathname) {}

    // Intent: Copy constructor
    // Pre: The file parameter is a valid File object
    // Post: Creates a new File object with the same pathname as the input file
    File(const File &file)
    {
        this->pathname = file.pathname;
    }

    // Intent: Copy assignment operator
    // Pre: The file parameter is a valid File object
    // Post: Copies the text and pathname from the input file to the current object and returns a reference to the current object
    inline File &operator=(const File &file)
    {
        Document::operator=(file);
        this->pathname = file.pathname;
        return (*this);
    }

    // Intent: Get the pathname of the file
    // Post: Returns the pathname of the file
    inline const std::string &getPathname() const
    {
        return this->pathname;
    }

    // Intent: Set the pathname of the file
    // Pre: The pathname parameter contains the new pathname to set for the file
    // Post: Sets the pathname of the file to the value of the input pathname parameter
    inline void setPathname(const std::string &pathname)
    {
        this->pathname = pathname;
    }
};
