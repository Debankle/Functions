#ifndef __LANGUAGE_LEXER_H
#define __LANGUAGE_LEXER_H

#include <iostream>
#include <vector>
#include <string>

class Lexer {
    public:
        Lexer(std::string rawCode);

        const void Lex();
        std::vector<std::string> returnTokens();

    private:
        std::string rawCode;
        std::vector<std::string> tokens;
};

#endif // __LANGUAGE_LEXER_H
