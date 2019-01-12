#ifndef __LANGUAGE_ARGS_PARSER_H
#define __LANGUAGE_ARGS_PARSER_H

// Credit to stackoverflow users/85381 and users/1031417 for this
// Some changes have been made, but it was taken from them

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

#endif // __LANGUAGE_ARGS_PARSER_H