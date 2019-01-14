/*
// This file is part of Functions.

// Functions is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.

// Functions is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Functions.  If not, see <https://www.gnu.org/licenses/>.
*/

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
