#ifndef TEXT_H
#define TEXT_H

#include "ITextBlock.h"
#include <string>

class Text : public ITextBlock 
{
public:
    std::string render(const std::string& text) const override 
    {
        return text;
    }
};

#endif
