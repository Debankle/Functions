#include "../include/Lexer.hpp"

Lexer::Lexer(std::string rawCode) { this->rawCode = rawCode; }

const void Lexer::Lex() {
    std::string token = "";

    for (char &c : this->rawCode) {
        // look for (. If found current token is the function
        // when ) found, token is function args
        token += c;

        if (c == '\n') {
            token = "";
        } else if (c == '(') {
            std::string funcString = "func:" + token.erase(token.size() - 1);
            this->tokens.push_back(funcString);
            token = "";
        } else if (c == ')') {
            std::string argsString = "args:" + token.erase(token.size() - 1);
            this->tokens.push_back(argsString);
            token = "";
        }
    }
}

std::vector<std::string> Lexer::returnTokens() { return this->tokens; }
