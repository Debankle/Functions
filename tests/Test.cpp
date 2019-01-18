#include "../include/Colors.hpp"
#include "../include/Compiler.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << Color::FG_MAGENTA << "Test 1: tests/init_test.func" << endl;
    cout << Color::FG_MAGENTA << "Compiling init_test" << Color::FG_DEFAULT << endl;
    system("./bin/func -f tests/init_test.func -o tests/init_test > /dev/null");
    cout << Color::FG_MAGENTA << "\nTesting init_test" << Color::FG_DEFAULT << endl;
    system("./tests/init_test");
    cout << Color::FG_GREEN << "\nTest 1 init_test completed\n" << endl;

    return 0;
}
