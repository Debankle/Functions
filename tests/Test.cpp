#include "../include/Colors.hpp"
#include "../include/Compiler.hpp"
#include <iostream>
#include <string>

using namespace std;

void test(std::string test_file, std::string output_file) {
    cout << Color::FG_MAGENTA << "Test 1: " << test_file << endl;
    cout << Color::FG_MAGENTA << "Compiling " << test_file << Color::FG_DEFAULT << endl;

    std::string compile_command = "../bin/func -f " + test_file + " -o " + output_file;
    system(compile_command.c_str());

    cout << Color::FG_MAGENTA << "\nTesting " << test_file << Color::FG_DEFAULT << endl;
    std::string test_command = "./" + output_file;
    system(test_command.c_str());

    cout << Color::FG_GREEN << "\nTest 1 init_test completed\n" << endl;
    
    std::string delete_command = "rm -rf " + output_file;
    system(delete_command.c_str());
}

int main() {
    test("init_test.func", "init_test");
    test("add_test.func", "add_test");
    test("sub_test.func", "sub_test");
    test("mul_test.func", "mul_test");
    test("set_test.func", "set_test");
    test("bool_test.func", "bool_test");
    test("out_test.func", "out_test");

    return 0;
}
