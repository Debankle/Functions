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

#ifndef __FUNCTIONS_ARGS_PARSER_H
#define __FUNCTIONS_ARGS_PARSER_H

// Credit to stackoverflow users/85381 and users/1031417 for this
// Some changes have been made, but the concept originated from there
// https://stackoverflow.com/questions/865668/how-to-parse-command-line-arguments-in-c

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class ArgsParser {
  public:
    ArgsParser(int argc, char *argv[]);

    const string getCmdOption(const string option) const;
    bool cmdOptionExists(const std::string &option) const;

  private:
    vector<string> tokens;
    const map<string, string> token_map = {{"--file", "-f"}, {"--help", "-h"}};
};

#endif // __FUNCTIONS_ARGS_PARSER_H