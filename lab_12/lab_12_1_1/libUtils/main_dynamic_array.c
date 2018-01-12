#include "main_dynamic_array.h"

void* create_dynamic_array(char *name_of_file, int len, int *code_1, size_t type, double_array dynamic_array_double, int_array dynamic_array_int)
{
    assert(fopen(name_of_file, "r"));

    FILE *f = fopen(name_of_file, "r");

    int code = *code_1;
    void* array;
    if (type == 4)
        array = dynamic_array_int(f, len, &code);
    else
        array = dynamic_array_double(f, len, &code);

    *code_1 = code;
    fclose(f);
    return array;
}
