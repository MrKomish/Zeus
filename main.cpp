#include <iostream>
#include "lexer.h"

int main() {
    auto code = R"(
        a: u8 = 2
        b = true
        c = false
        x = 32
        z = create();
    )";

    auto tokens = Lexer(code).getTokens();

    uint32_t lastLine = 1;

    for (auto& token : tokens) {
        uint32_t currentLine = token.position().line;

        if (currentLine > lastLine) {
            std::cout << "\n";
        }
        std::cout << *token.value() << " ";

        lastLine = currentLine;
    }

    return 0;
}
