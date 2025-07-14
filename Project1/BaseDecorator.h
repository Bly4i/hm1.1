#ifndef BASEDECORATOR_H
#define BASEDECORATOR_H

#include <memory>
#include "ITextBlock.h" 

class BaseDecorator : public ITextBlock 
{
protected:
    std::unique_ptr<ITextBlock> wrappee_;

public:
    BaseDecorator(std::unique_ptr<ITextBlock> wrappee) : wrappee_(std::move(wrappee)) {}

    std::string render(const std::string& text) const override {
        return wrappee_->render(text);
    }
};

#endif
