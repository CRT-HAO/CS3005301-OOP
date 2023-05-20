// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 21, 2023
// Last Update: May 21, 2023
// Problem statement: Class Inheritance

#pragma once

#include <string>

class Document
{
protected:
    std::string text; // The text of the document

public:
    Document() {} // Default constructor

    // Intent: Constructor that accepts a text parameter
    // Pre: The text parameter contains the text to assign to the document
    // Post: Creates a new Document object with the same text as the input document
    Document(const std::string &text) : text(text) {}

    // Intent: Copy constructor
    // Pre: The document parameter is a valid Document object
    // Post: Creates a new Document object with the same text as the input document
    Document(const Document &document)
    {
        this->text = document.text;
    }

    // Intent: Copy assignment operator
    // Pre: The document parameter is a valid Document object
    // Post: Copies the text from the input document to the current object's text and returns a reference to the current object
    inline Document &operator=(const Document &document)
    {
        this->text = document.text;
        return (*this);
    }

    // Intent: Get the text of the document
    // Post: Returns the text of the document
    inline const std::string &getText() const
    {
        return this->text;
    }

    // Intent: Set the text of the document
    // Pre: The text parameter contains the new text to set for the document
    // Post: Sets the text of the document to the value of the input text parameter
    inline void setText(const std::string &text)
    {
        this->text = text;
    }
};
