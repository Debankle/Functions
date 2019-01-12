#include "../include/ArgsParser.hpp"
#include "../include/Compiler.hpp"
#include <fstream>
#include <iostream>
#include <string>

#ifndef GCC_LOC
#define GCC_LOC "/usr/bin/gcc"
#endif // GCC_LOC

using namespace std;

int main(int argc, char *argv[]) {
    string filename;
    string destination = "main";

    ArgsParser parser(argc, argv);
    if (parser.cmdOptionExists("-h")) {
        cout << "TODO add help options" << endl;
        return 0;
    }
    if (parser.cmdOptionExists("-o")) {
        destination = parser.getCmdOption("-o");
    }
    if (parser.cmdOptionExists("-f")) {
        filename = parser.getCmdOption("-f");
        if (filename.empty()) {
            cerr << "Please specify a file after -f" << endl;
            return 0;
        }
    } else {
        cerr << "No file was specified. Please use the -f option" << endl;
        return 0;
    }

    Compiler compiler(filename, destination, GCC_LOC);
    compiler.Compile();

    return 0;
}