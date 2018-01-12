#include "file_open.h"

int open_file(char* name, count_s len_array_int, count_s len_array_double, int* code_1, size_t* type)
{
    assert(fopen(name, "r"));

    FILE *f = fopen(name, "r");

    int code = *code_1;
    *type = sizeof(int);              //Type of varAr (int)

    int len = len_array_int(f, &code);
    if (code)
    {
        *type = sizeof(double);
        code = 0;
        rewind(f);
        len = len_array_double(f, &code);
    }
    *code_1 = code;
    fclose(f);
    return len;
}
