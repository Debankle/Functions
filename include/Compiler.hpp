/*
// This file is part of Functions.

// Functions is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// Functions is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with Functions.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __LANGUAGE_COMPILER_H
#define __LANGUAGE_COMPILER_H

#include "Lexer.hpp"
#include "Parser.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Compiler {

  public:
    Compiler(std::string source, std::string destination, std::string gcc_loc);
    const void Compile();

    const void ReadFile();
    const void Lex();
    const void Parse();
    const void WriteToFile();
    const void CompileCFile();

    const std::string getRaw();

  private:
    std::string source;
    std::ifstream sourceFileReader;
    std::string rawCode;

    std::vector<std::string> tokens;
    std::string cCode;

    std::string destination;
    std::ofstream cCodeReader;

    std::string gcc_loc;
};

#endif // __LANGUAGE_COMPILER_H