#pragma once
#include "document.h"
#include <string>

class Email : public Document
{
   public:
    Email();
    Email(std::string t, std::string s, std::string r, std::string title_);
    inline void setSender(string s);
    inline std::string getSender() const;
    inline void setRecipient(string s);
    inline std::string getRecipient() const;
    inline void setTitle(string s);
    inline std::string getTitle() const;
    Email& operator=(Email& input);

   private:
    std::string sender;
    std::string recipient;
    std::string title;
};

using namespace std;

Email::Email()
{
}

Email::Email(string t, string s, string r, string title_) : Document(t), sender(s), recipient(r), title(title_)
{
}

inline void Email::setSender(string s)
{
    sender = s;
}

inline string Email::getSender() const
{
    return sender;
}

inline void Email::setRecipient(string s)
{
    recipient = s;
}

inline string Email::getRecipient() const
{
    return recipient;
}

inline void Email::setTitle(string s)
{
    title = s;
}

inline string Email::getTitle() const
{
    return title;
}

Email& Email::operator=(Email& input)
{
    setText(input.getText());
    sender = input.sender;
    recipient = input.recipient;
    title = input.title;
}

bool ContainsKeyword(const Email& emailObject, string keyword)
{
    if (emailObject.getText().find(keyword) != string::npos)
        return true;
    return false;
}