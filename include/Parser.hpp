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

#ifndef __LANGUAGE_PARSER_H
#define __LANGUAGE_PARSER_H

#include <iostream>
#include <map>
#include <vector>

class Parser {
  public:
    Parser(std::vector<std::string> tokens);

    const void Parse();

    // Basic functions
    const void require(std::string args);
    const void init(std::string args);
    const void set(std::string args);

    // Print function
    const void out(std::string args);

    // Math functions
    const void add(std::string args);
    const void sub(std::string args);
    const void mul(std::string args);
    const void div(std::string args);

    // Return function
    const void done(std::string args);

    const std::string getCode();

  private:
    std::vector<std::string> tokens;
    std::map<std::string, std::string> includes = {{"sys", "stdio.h"}};

    std::string include_section;
    std::string main_section;

    std::string raw_code;
};

#endif // __LANGUAGE_PARSER_H
