#include <stdio.h>

enum { TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_BOOL, TYPE_STRING, TYPE_NULL };

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
    int type;
    char *name;
} variable_t;