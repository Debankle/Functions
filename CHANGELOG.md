## 23/1/19

Major problems. Base idea in Parser.cpp init(std::args) written, but for some reason, code from the main_section inited code ends up in the include section, and the define section code is not appearing. For example, the init_test.func code outputs this as the c code:

```
#include <stdio.h>
variable_t a;
.value.b =  4;
.print_key = "%d";
c.value.s.len = 15;
c.print_key = "%s";
int main() {
variable_t b;
b.type = TYPE_INT;
.value.b =  4;
variable_t c;
c.type = TYPE_STRING;
c.value.s.s =  "hello world";
printf("%d\n",a);
printf("%d\n",b);
printf("%d\n",c);
return 0;
}
```