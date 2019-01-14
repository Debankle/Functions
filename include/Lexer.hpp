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

#ifndef __FUNCTIONS_LEXER_H
#define __FUNCTIONS_LEXER_H

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

#endif // __FUNCTIONS_LEXER_H
