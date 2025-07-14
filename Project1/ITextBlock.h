#ifndef ITEXTBLOCK_H
#define ITEXTBLOCK_H

#include <string>

class ITextBlock 
{
public:
    virtual ~ITextBlock() = default;
    virtual std::string render(const std::string& text) const = 0;
};

#endif
