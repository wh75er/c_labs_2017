#include "main.h"

int main(int argc, char **argv)
{
    if (argc > 3 && (*argv[3] == '1' || *argv[3] == '0'))
    {
        FILE *f = fopen(argv[1], "r");

        int code = 0;
        size_t type = sizeof(int);              //Type of varAr (int)

        int len = len_array_int(f, &code);
        if (code)
        {
            type = sizeof(double);
            code = 0;
            rewind(f);
            len = len_array_double(f, &code);
        }
        if ( !code )
        {
            if (type == 4)                      //int branch work
            {
                int* array = dynamic_array_int(f, len, &code);
                if (*argv[3] == '1')
                    array = filter_int(array, &len);

                bubble_sort(array, len, type);

                FILE *fo = fopen(argv[2], "w");
                for(int* pa = array; pa < array + len; pa++)
                    fprintf(fo, "%d ", *pa);

                free(array);
            }
            else                                //double branch work
            {
                double* array = dynamic_array_double(f, len, &code);
                if (*argv[3] == '1')
                    array = filter_double(array, &len);
                char flag = compare( (array), array +  2, type);
                printf("\n%lf %c %lf", *(array), flag, *(array + 2));

                bubble_sort(array, len, type);

                FILE *fo = fopen(argv[2], "w");
                for(double* pa = array; pa < array + len; pa++)
                    fprintf(fo, "%lf ", *pa);

                free(array);
            }

        }
        else
            printf("\nFile reading error!\n");
        fclose(f);
    }
    else
        printf("\nProgram parametrs entering error!\n");
    return 0;
}
