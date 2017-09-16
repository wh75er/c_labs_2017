#include "file_write.h"

void write_file(char* file_out_name, void* array, size_t type, int len)
{

    FILE *fo = fopen(file_out_name, "w");

    if(type == 4)
    {
        for(int* pa = (int*)array; pa < (int*)array + len; pa++)
            fprintf(fo, "%d ", *pa);
    }
    else if(type == 8)
    {
        for(double* pa = (double*)array; pa < (double*)array + len; pa++)
            fprintf(fo, "%lf ", *pa);
    }
    else if(type == -1)
    {
		fprintf(fo, "File reading error!\n");
    }
    fclose(fo);
}
