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

#include "../include/ArgsParser.hpp"

ArgsParser::ArgsParser(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        this->tokens.push_back(string(argv[i]));
    }

    // Convert args to one type for simplicity e.g. --file to -f because they
    // both mean the same thing
    vector<string> new_tokens;
    for (auto i : this->tokens) {
        if (this->token_map.find(i) != this->token_map.end()) {
            new_tokens.push_back(this->token_map.find(i)->second);
        } else {
            new_tokens.push_back(i);
        }
    }
    this->tokens = new_tokens;
}

/*
    Gets the token after the argument provided in option
    Returns as a string, if it doesn't exist returns empty string
*/
const string ArgsParser::getCmdOption(const string option) const {
    // Works, but is inefficient and should be optimized
    bool foundOption = false;
    for (auto i : this->tokens) {
        if (foundOption) {
            return i;
        }
        if (i == option) {
            foundOption = true;
        }
    }
    static const string empty_string("");
    return empty_string;
}

// Looks for the arg string, and returns true if it is in the tokens vector, otherwise returns false
bool ArgsParser::cmdOptionExists(const string &option) const {
    return find(this->tokens.begin(), this->tokens.end(), option) !=
           this->tokens.end();
}
