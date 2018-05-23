#pragma once
#include <string>

class Document
{
   public:
    Document();
    Document(std::string t);
    inline void setText(std::string t);
    inline std::string getText() const;
    Document& operator=(Document& input);

   private:
    std::string text;
};

using namespace std;

Document::Document()
{
}

Document::Document(string t)
{
    text = t;
}

inline void Document::setText(std::string t)
{
    text = t;
}

inline string Document::getText() const
{
    return text;
}

Document& Document::operator=(Document& input)
{
    text = input.text;
}

bool ContainsKeyword(const Document& docObject, string keyword)
{
    if (docObject.getText().find(keyword) != string::npos)
        return true;
    return false;
}