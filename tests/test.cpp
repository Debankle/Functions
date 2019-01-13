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

// Work in progress, not yet working.
// Still planning the idea for how it works
// Thinking a function that takes source, destination and compiles,
// runs and returns result

#include <iostream>
#include <string>

inline std::string formatCmd(const char* fmt, ...){
    int size = 512;
    char* buffer = 0;
    buffer = new char[size];
    va_list vl;
    va_start(vl, fmt);
    int nsize = vsnprintf(buffer, size, fmt, vl);
    if(size<=nsize){ //fail delete buffer and try again
        delete[] buffer;
        buffer = 0;
        buffer = new char[nsize+1]; //+1 for /0
        nsize = vsnprintf(buffer, size, fmt, vl);
    }
    std::string ret(buffer);
    va_end(vl);
    delete[] buffer;
    return ret;
}

int main() {
    std::string cmd;
    std::cout << "Running tests now\n" << std::endl; 

    // Test 1 - basic test
    std::cout << "Test 1: basic test" << std::endl;
    cmd = formatCmd("./bin/func -f %s -o %s", "tests/basic_test.func", "tests/basic_test");
    int result = system(cmd.c_str());
    if (result == 0) {
        std::cout << "Test 1: compiled succesfully" << std::endl;
    } else {
        std::cout << "Test 2: failed to compile" << std::endl;
    }

    return 0;
}
