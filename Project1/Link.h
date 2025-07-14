#ifndef LINK_H
#define LINK_H

#include "ITextBlock.h"
#include <memory> 


class Link : public ITextBlock 
{
private:
    std::unique_ptr<ITextBlock> wrappee_;

public:
    explicit Link(std::unique_ptr<ITextBlock> wrappee) : wrappee_(std::move(wrappee)) {}

    std::string render(const std::string& text) const override 
    {
        
        return wrappee_->render(text);
    }

    // Специализированный метод для Link
    std::string render(const std::string& href, const std::string& text) const 
    {
        return "<a href=" + href + ">" + wrappee_->render(text) + "</a>";
    }
};

#endif // LINK_H
