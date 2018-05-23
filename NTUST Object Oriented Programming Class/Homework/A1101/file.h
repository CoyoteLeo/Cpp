#pragma once
#include "document.h"

class File : public Document
{
   public:
    File();
    File(std::string t, std::string p);
    inline void setPathname(std::string s);
    inline std::string getPathname() const;
    File& operator=(File& input);

   private:
    std::string pathname;
};

using namespace std;

File::File()
{
}

File::File(string t, string p) : Document(t), pathname(p)
{
}

inline void File::setPathname(string s)
{
    pathname = s;
}

inline string File::getPathname() const
{
    return pathname;
}

File& File::operator=(File& input)
{
    setText(input.getText());
    pathname = input.pathname;
}

bool ContainsKeyword(const File& fileObject, string keyword)
{
    if (fileObject.getText().find(keyword) != string::npos)
        return true;
    return false;
}