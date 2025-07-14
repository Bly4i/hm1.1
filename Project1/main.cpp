#include <iostream>
#include <memory> 
#include "ITextBlock.h"
#include "Text.h"
#include "Paragraph.h"
#include "Reversed.h"
#include "Link.h"

int main() {
    std::cout << "--- Paragraph ---" << std::endl;
    std::unique_ptr<ITextBlock> text_block_paragraph = std::make_unique<Paragraph>(std::make_unique<Text>());
    std::cout << text_block_paragraph->render("Hello world") << std::endl;

    std::cout << "\n--- Reversed ---" << std::endl;
    std::unique_ptr<ITextBlock> text_block_reversed = std::make_unique<Reversed>(std::make_unique<Text>());
    std::cout << text_block_reversed->render("Hello world") << std::endl;

    std::cout << "\n--- Link ---" << std::endl;
    auto link_block = new Link(std::make_unique<Text>());
    std::cout << link_block->render("netology.ru", "Hello world") << std::endl;
    delete link_block;

    std::cout << "\n--- Combined Decorators (Paragraph(Reversed(Text))) ---" << std::endl;
    std::unique_ptr<ITextBlock> combined_block = std::make_unique<Paragraph>(
        std::make_unique<Reversed>(
            std::make_unique<Text>()
        )
    );
    std::cout << combined_block->render("Hello world") << std::endl;

    return 0;
}
