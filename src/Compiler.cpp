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

#include "../include/Compiler.hpp"

Compiler::Compiler(std::string source, std::string destination,
                   std::string gcc_loc) {
    Compiler::source = source;
    Compiler::destination = destination;
    Compiler::gcc_loc = gcc_loc;
}

const void Compiler::Compile() {
    Compiler::ReadFile();
    Compiler::Lex();
    Compiler::Parse();
    Compiler::WriteToFile();
    Compiler::CompileCFile();

    std::cout << "Succesfully compiled " << this->source << " to "
              << this->destination << std::endl;
}

/*
    Open the source file defined in the constructor
    If there is an error return an empty string
*/
const void Compiler::ReadFile() {
    this->sourceFileReader.open(this->source);

    if (!this->sourceFileReader) {
        std::cout << "Error opening " << this->source << std::endl;
        exit(1);
    }

    std::string line;
    if (this->sourceFileReader.is_open()) {
        while (getline(this->sourceFileReader, line)) {
            line += "\n";
            Compiler::rawCode.append(line);
        }
    }

    this->sourceFileReader.close();
}

const void Compiler::Lex() {
    Lexer lexer(this->rawCode);
    lexer.Lex();
    this->tokens = lexer.returnTokens();
}

const void Compiler::Parse() {
    Parser parser(this->tokens);
    parser.Parse();
    this->cCode = parser.getCode();
}

/*
    Open the c main file with the cCodeReader object
    If there is an error return it and exit
    Write the c code from the parser to the file and close it
*/
const void Compiler::WriteToFile() {
    this->cCodeReader.open(this->destination + ".c");
    if (!this->cCodeReader) {
        std::cout << "Error creating c file" << std::endl;
        exit(1);
    }

    this->cCodeReader << this->cCode;
    this->cCodeReader.close();
}

/*
    Uses the gcc defined at compile time, or default if not specified
    attempts to run command to compile it: gcc -o destination destination.c
    If it returns error 256, return compile error and exit
    Now remove the .c file from existence to make it less suss.
    possibly change to .destination.c for discretion
*/
const void Compiler::CompileCFile() {
    std::string str_cmd = this->gcc_loc + " -o " + this->destination + " " +
                          this->destination + ".c > /dev/null";
    const char *cmd = str_cmd.c_str();
    int ret = system(cmd);
    if (ret == 256) {
        std::cout << "Error compiling " << this->source << std::endl;
        std::string str_rm = "rm -rf " + this->destination + ".c > /dev/null";
        system(str_rm.c_str());
        exit(1);
    }
    std::string str_rm = "rm -rf " + this->destination + ".c > /dev/null";
    system(str_rm.c_str());
}

// Probably never used
const std::string Compiler::getRaw() { return this->rawCode; }
