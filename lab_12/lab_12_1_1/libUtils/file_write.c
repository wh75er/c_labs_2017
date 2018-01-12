#include "file_write.h"

void write_file(char* file_out_name, void* array, size_t type, int len, int code)
{

    FILE *fo = fopen(file_out_name, "w");

	if(type == 4 && !code)
    {
        for(int* pa = (int*)array; pa < (int*)array + len; pa++)
            fprintf(fo, "%d ", *pa);
    }
	else if(type == 8 && !code)
    {
        for(double* pa = (double*)array; pa < (double*)array + len; pa++)
            fprintf(fo, "%lf ", *pa);
    }
	else if(code)
    {
		fprintf(fo, "File reading error!\n");
    }
    fclose(fo);
}
