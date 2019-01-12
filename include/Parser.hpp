#ifndef __LANGUAGE_PARSER_H
#define __LANGUAGE_PARSER_H

#include <iostream>
#include <map>
#include <vector>

class Parser {
  public:
    Parser(std::vector<std::string> tokens);

    const void Parse();

    const void require(std::string args);
    const void init(std::string args);
    const void out(std::string args);
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