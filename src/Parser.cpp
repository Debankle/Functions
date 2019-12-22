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

#include "../include/Parser.hpp"

Parser::Parser(std::vector<std::string> tokens) {
    this->tokens = tokens;
    this->type_definitions.append("typedef enum { false, true } bool;\n");
    this->type_definitions.append(
        "typedef enum { TYPE_INT, TYPE_BOOL, TYPE_STRING } types_t;\n");
    this->type_definitions.append(
        "typedef struct { char *s; size_t len; } string_t;\n");
    this->type_definitions.append(
        "typedef union { int i; string_t s; bool b; } values_t;\n");
    this->type_definitions.append(
        "typedef struct { values_t value; int type; } variable_t;\n");
}

/*
    returns type detected in variable as an int from the type enum
*/
const int Parser::getType(std::string token) {
    // Return type from type enum
    return Parser::TYPE_INT;
}

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
                std::cout << "Unknown function "
                          << this->tokens[n].substr(5, -1) << "! Kachow!"
                          << std::endl;
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
    this->raw_code = this->include_section + this->type_definitions +
                     "int main() {\n" + this->define_section +
                     this->main_section + "}";
}

const void Parser::require(std::string args) {
    std::string require_string =
        "#include <" + this->includes.find(args)->second + ">\n";
    this->include_section.append(require_string);
}

/*
    Init function. Requires one or two arguments, seperated by a comma
    If one arg is provided, it is initialized with no value as an int, otherwise
    it is initialised by the second value e.g. init(a) or init(a, 4)
*/
const void Parser::init(std::string args) {
    /*
       TODO: Rewrite function
       If the args have a comma, get token 1 and 2. Token 1 is the value,
       token2 is the variable name Get they type of token1, it it has "\"" it is
       a string_t, it it has false or true it is a bool, otherwise it is an int
       create a new variable_t with name of token2. Set the value to token1, set
       variable_t.type to type enum and set variable_t.print_key to the print
       key If there is no comma, create a variable_t with name args
    */

    std::string define_string;
    if (args.find(',') != std::string::npos) {
        std::string token1, token2;

        for (char c : args) {
            if (c == ',') {
                token1 = token2;
                token2 = "";
            } else {
                token2 += c;
            }
        }

        if (token2.find("\"") != std::string::npos) {
            define_string = "variable_t " + token1 + ";\n";
            define_string += token1 + ".type = TYPE_STRING;\n";
            define_string += token1 + ".value.s.s = " + token2 + ";\n";
            define_string += token1 + ".value.s.len = " +
                              std::to_string(token2.length() + 1) + ";\n";
        } else if (token2.find("false") != std::string::npos ||
                   token2.find("true") != std::string::npos) {
            define_string = "variable_t " + token1 + ";\n";
            define_string += token1 + ".type = TYPE_BOOL;\n";
            define_string += token1 + ".value.b = " + token2 + ";\n";
        } else {
            define_string = "variable_t " + token1 + ";\n ";
            define_string += token1 + ".type = TYPE_INT;\n ";
            define_string += token1 + ".value.b = " + token2 + ";\n ";
        }
    } else {
        define_string = "variable_t " + args + ";\n";
    }

    this->main_section.append(define_string);

    /*
    std::string define_string;
    if (args.find(',') != std::string::npos) {
        std::string token1, token2, type;

        for (char c : args) {
            if (c == ',') {
                token2 = token1;
                token1 = "";
            } else {
                token1 += c;
            }
        }

        if (token1.find("\"") != std::string::npos) {
            type = "char";
            token2 += "[]";
        } else if (token1.find("false") != std::string::npos ||
                   token1.find("true") != std::string::npos) {
            type = "bool";
        } else {
            type = "int";
        }
        define_string = type + " " + token2 + " = " + token1;

    } else {
        define_string = "int " + args;
    }
    define_string += ";\n";
    this->main_section.append(define_string);
    */
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
