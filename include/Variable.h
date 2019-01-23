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

#ifndef __FUNCTIONS_VARIABLE_H
#define __FUNCTIONS_VARIABLE_H

#include <stdio.h>

typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_BOOL, TYPE_STRING, TYPE_NULL } type_t;

typedef enum { false, true } bool;

typedef struct {
    char *s;
    int len;
} custom_string;

typedef union {
    int i;
    float f;
    double d;
    bool b;
    custom_string s;
} values;

typedef struct {
    values value;
    type_t type;
    char *name;
} variable_t;

#endif // __FUNCTIONS_VARIABLE_H