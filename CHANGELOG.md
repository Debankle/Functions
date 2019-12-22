## 23/1/19

Major problems. Base idea in Parser.cpp init(std::args) written, but for some reason, code from the main_section inited code ends up in the include section, and the define section code is not appearing. For example, the init_test.func code outputs this as the c code:
