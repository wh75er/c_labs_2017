#include "main.h"



int main(int argc, char **argv)
{
    if (argc > 3 && (*argv[3] == '1' || *argv[3] == '0'))
    {
        int code = 0;
        size_t type;
        int len = open_file(argv[1], len_array_int, len_array_double, &code, &type);
        if ( !code )
        {

            void* array = create_dynamic_array(argv[1], len, &code, type, dynamic_array_double, dynamic_array_int);
            void* array_after_filter = filter(argv[3], array, &len, type);

            bubble_sort(array_after_filter, len, type);

            write_file(argv[2], array_after_filter, type, len);

            free(array_after_filter);
        }
        else
            printf("\nFile reading error!\n");
    }
    else
        printf("\nProgram parametrs entering error!\n");
    return 0;
}
