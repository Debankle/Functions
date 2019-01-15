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

// Concept for what I want to do
// This is what the c code should be converted to
// Or somewhat similar

#include <stdio.h>

typedef enum { false, true } bool;

typedef enum { TYPE_INT, TYPE_STRING, TYPE_BOOL, TYPE_NULL };

typedef struct {
    char *s;
    size_t len;
} string_t;

typedef union {
    int i;
    string_t s;
    bool b;
} values_t;

typedef struct {
    values_t value;
    int type;
} variable_t;


int main() {
    variable_t a;
    a.type = TYPE_INT;
    a.value.i = 4;

    variable_t b;
    b.type = TYPE_BOOL;
    b.value.b = false;

    variable_t c;
    c.type = TYPE_STRING;
    c.value.s.s = "Hello";
    c.value.s.len = strlen(c.value.s.s);

    variable_t d;
    d.type = TYPE_NULL;

    printf("%d\n", a.value);
    printf("%d\n", b.value);
    printf("%d\n", c.value.s.len);
    printf("%p\n", d.value);
}
