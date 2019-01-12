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
            } else if (this->tokens[n].substr(5, -1) == "done") {
                done(this->tokens[++n].substr(5, -1));
            } else if (this->tokens[n].substr(5, -1) == "out") {
                out(this->tokens[++n].substr(5, -1));
            } else if (this->tokens[n].substr(5, -1) == "add") {
                add(this->tokens[++n].substr(5, -1));
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

const void Parser::init(std::string args) {
    std::string define_string = "int " + args + ";\n";
    this->main_section.append(define_string);
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

const void Parser::done(std::string args) {
    if (args == "") {
        args = "0";
    }
    std::string done_string = "return " + args + ";\n";
    this->main_section.append(done_string);
}

const std::string Parser::getCode() { return this->raw_code; }
