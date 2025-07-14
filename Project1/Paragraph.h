#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include "BaseDecorator.h"

class Paragraph : public BaseDecorator 
{
public:
    explicit Paragraph(std::unique_ptr<ITextBlock> wrappee) : BaseDecorator(std::move(wrappee)) {}

    std::string render(const std::string& text) const override 
    {
        return "<p>" + wrappee_->render(text) + "</p>";
    }
};

#endif
