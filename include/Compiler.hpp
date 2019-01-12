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