#ifndef REVERSED_H
#define REVERSED_H

#include "BaseDecorator.h"
#include <algorithm>

class Reversed : public BaseDecorator 
{
public:
    explicit Reversed(std::unique_ptr<ITextBlock> wrappee) : BaseDecorator(std::move(wrappee)) {}

    std::string render(const std::string& text) const override 
    {
        std::string reversed_text = wrappee_->render(text);
        std::reverse(reversed_text.begin(), reversed_text.end());
        return reversed_text;
    }
};

#endif
