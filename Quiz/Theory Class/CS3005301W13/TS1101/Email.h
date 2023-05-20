// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 21, 2023
// Last Update: May 21, 2023
// Problem statement: Class Inheritance

#pragma once

#include "Document.h"

#include <string>

class Email : public Document
{
private:
    std::string sender;    // The sender of the email
    std::string recipient; // The recipient of the email
    std::string title;     // The title of the email

public:
    Email(){}; // Default constructor

    // Intent: Constructor that accepts body, sender, recipient, and title parameters
    // Pre: The body parameter contains the text to assign to the email's body
    //      The sender parameter contains the sender of the email
    //      The recipient parameter contains the recipient of the email
    //      The title parameter contains the title of the email
    // Post: Creates a new Email object with the provided body, sender, recipient, and title
    Email(const std::string &body, const std::string &sender,
          const std::string &recipient, const std::string &title)
        : Document(body), sender(sender), recipient(recipient), title(title) {}

    // Intent: Copy constructor
    // Pre: The email parameter is a valid Email object
    // Post: Creates a new Email object with the same body, sender, recipient, and title as the input email
    Email(const Email &email)
    {
        this->text = email.text;
        this->sender = email.sender;
        this->recipient = email.recipient;
        this->title = email.title;
    }

    // Intent: Copy assignment operator
    // Pre: The email parameter is a valid Email object
    // Post: Copies the body, sender, recipient, and title from the input email to the current object and returns a reference to the current object
    inline Email &operator=(const Email &email)
    {
        Document::operator=(email);
        this->sender = email.sender;
        this->recipient = email.recipient;
        this->title = email.title;
        return (*this);
    }

    // Intent: Get the sender of the email
    // Post: Returns the sender of the email
    inline const std::string &getSender() const
    {
        return this->sender;
    }

    // Intent: Get the recipient of the email
    // Post: Returns the recipient of the email
    inline const std::string &getRecipient() const
    {
        return this->recipient;
    }

    // Intent: Get the title of the email
    // Post: Returns the title of the email
    inline const std::string &getTitle() const
    {
        return this->title;
    }

    // Intent: Set the sender of the email
    // Pre: The sender parameter contains the new sender to set for the email
    // Post: Sets the sender of the email to the value of the input sender parameter
    inline void setSender(const std::string &sender)
    {
        this->sender = sender;
    }

    // Intent: Set the recipient of the email
    // Pre: The recipient parameter contains the new recipient to set for the email
    // Post: Sets the recipient of the email to the value of the input recipient parameter
    inline void setRecipient(const std::string &recipient)
    {
        this->recipient = recipient;
    }

    // Intent: Set the title of the email
    // Pre: The title parameter contains the new title to set for the email
    // Post: Sets the title of the email to the value of the input title parameter
    inline void setTitle(const std::string &title)
    {
        this->title = title;
    }
};
