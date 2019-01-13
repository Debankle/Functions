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

#include "../include/Parser.hpp"

Parser::Parser(std::vector<std::string> tokens) { this->tokens = tokens; }

// Add a function for every call for the language. This file will get very long
// and complicated Possibly create seperate files for types, e.g. all maths in
// one file
const void Parser::Parse() {
    for (size_t n = 0; n < this->tokens.size(); n++) {
        if (this->tokens[n].substr(0, 4) == "func") {
            if (this->tokens[n].substr(5, -1) == "require") {
                require(this->tokens[++n].substr(5, -1));
            } else if (this->tokens[n].substr(5, -1) == "init") {
                init(this->tokens[++n].substr(5, -1));
            } else if (this->tokens[n].substr(5, -1) == "set") {
                set(this->tokens[++n].substr(5, -1));
            } else if (this->tokens[n].substr(5, -1) == "done") {
                done(this->tokens[++n].substr(5, -1));
            } else if (this->tokens[n].substr(5, -1) == "out") {
                out(this->tokens[++n].substr(5, -1));
            } else if (this->tokens[n].substr(5, -1) == "add") {
                add(this->tokens[++n].substr(5, -1));
            } else if (this->tokens[n].substr(5, -1) == "sub") {
                sub(this->tokens[++n].substr(5, -1));
            } else if (this->tokens[n].substr(5, -1) == "mul") {
                mul(this->tokens[++n].substr(5, -1));
            } else if (this->tokens[n].substr(5, -1) == "div") {
                div(this->tokens[++n].substr(5, -1));
            } else {
                std::cout << "Unknown function! Kachow!" << std::endl;
                exit(1);
            }
        } else if (this->tokens[n].substr(0, 4) == "args") {
            // should not get here
        } else {
            std::cout << "Should not have reached this point! Kachow!"
                      << std::endl;
            exit(1);
        }
    }
    this->raw_code =
        this->include_section + "int main() {\n" + this->main_section + "}";
}

const void Parser::require(std::string args) {
    std::string require_string =
        "#include <" + this->includes.find(args)->second + ">\n";
    this->include_section.append(require_string);
}

/*
    Init function. Requires one or two arguments, seperated by a comma
    If one arg is provided, it is initialized with no value, otherwise it is
   initialised by the second value e.g. init(a) or init(a, 4)
*/
const void Parser::init(std::string args) {
    std::string define_string;
    if (args.find(',') != std::string::npos) {
        std::string token1, token2;
        for (char c : args) {
            if (c == ',') {
                token2 = token1;
                token1 = "";
            } else {
                token1 += c;
            }
        }
        define_string = "int " + token2 + " = " + token1;
    } else {
        define_string = "int " + args;
    }
    define_string += ";\n";
    this->main_section.append(define_string);
}

/*
    Set function. Requires two parameters
    sets the second arg as a value to the first
    e.g. set(a, 4)  =>  a = 4
    set(a, b)  => a = b
*/
const void Parser::set(std::string args) {
    if (args.find(',') != std::string::npos) {
        std::string token1, token2;
        for (char c : args) {
            if (c == ',') {
                token2 = token1;
                token1 = "";
            } else {
                token1 += c;
            }
        }
        std::string assign_str = token2 + "=" + token1 + ";\n";
        this->main_section.append(assign_str);
    } else {
        std::cerr << "Two arguments must be provided" << std::endl;
        exit(1);
    }
}

const void Parser::out(std::string args) {
    std::string print_string = "printf(\"%d\\n\"," + args + ");\n";
    this->main_section.append(print_string);
}

/*
    Add function. Requires two arguments of the same type
    adds the second argument to the first
    e.g add(a, b)       =>      a = a + b
*/
const void Parser::add(std::string args) {
    if (args.find(',') != std::string::npos) {
        std::string token1, token2;
        for (char c : args) {
            if (c == ',') {
                token2 = token1;
                token1 = "";
            } else {
                token1 += c;
            }
        }
        std::string add_str = token2 + "=" + token2 + "+" + token1 + ";\n";
        this->main_section.append(add_str);
    } else {
        std::cerr << "No comma or two args provided" << std::endl;
        exit(1);
    }
}

/*
    Subtract function. Requires two arguments of the same type
    adds the second argument to the first
    e.g add(a, b)       =>      a = a - b
*/
const void Parser::sub(std::string args) {
    if (args.find(',') != std::string::npos) {
        std::string token1, token2;
        for (char c : args) {
            if (c == ',') {
                token2 = token1;
                token1 = "";
            } else {
                token1 += c;
            }
        }
        std::string add_str = token2 + "=" + token2 + "-" + token1 + ";\n";
        this->main_section.append(add_str);
    } else {
        std::cerr << "No comma or two args provided" << std::endl;
        exit(1);
    }
}

/*
    Mul function. Requires two arguments of the same type
    adds the second argument to the first
    e.g add(a, b)       =>      a = a * b
*/
const void Parser::mul(std::string args) {
    if (args.find(',') != std::string::npos) {
        std::string token1, token2;
        for (char c : args) {
            if (c == ',') {
                token2 = token1;
                token1 = "";
            } else {
                token1 += c;
            }
        }
        std::string add_str = token2 + "=" + token2 + "*" + token1 + ";\n";
        this->main_section.append(add_str);
    } else {
        std::cerr << "No comma or two args provided" << std::endl;
        exit(1);
    }
}

/*
    Divide function. Requires two arguments of the same type
    adds the second argument to the first
    e.g add(a, b)       =>      a = a / b
*/
const void Parser::div(std::string args) {
    if (args.find(',') != std::string::npos) {
        std::string token1, token2;
        for (char c : args) {
            if (c == ',') {
                token2 = token1;
                token1 = "";
            } else {
                token1 += c;
            }
        }
        std::string add_str = token2 + "=" + token2 + "/" + token1 + ";\n";
        this->main_section.append(add_str);
    } else {
        std::cerr << "No comma or two args provided" << std::endl;
        exit(1);
    }
}

const void Parser::done(std::string args) {
    if (args == "") {
        args = "0";
    }
    std::string done_string = "return " + args + ";\n";
    this->main_section.append(done_string);
}

const std::string Parser::getCode() { return this->raw_code; }
