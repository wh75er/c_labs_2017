#include "libs.h"
#include <dlfcn.h>

typedef int (*count_s)(FILE *f, int* code);
typedef double* (*double_array)(FILE* f, int len, int* code);
typedef int* (*int_array)(FILE* f, int len, int* code);


int main(int argc, char **argv)
{
	void* lib_handle;
	int (*open_file)(char*, count_s, count_s, int*, size_t*);
	void* (*create_dynamic_array)(char*, int, int*, size_t, double_array, int_array);
	void* (*filter)(const char, void*, int*, size_t, int*, double*);
	void (*bubble_sort)(void*, size_t, size_t);
	void (*write_file)(char*, void*, size_t, int, int);
	int (*len_array_int)(FILE*, int*);
	int (*len_array_double)(FILE*, int*);
	int* (*dynamic_array_int)(FILE*, int, int*);
	double* (*dynamic_array_double)(FILE*, int, int*);

	lib_handle = dlopen("libUtils/libdynamic.so", RTLD_LAZY);

	open_file = dlsym(lib_handle, "open_file");
	create_dynamic_array = dlsym(lib_handle, "create_dynamic_array");
	filter = dlsym(lib_handle, "filter");
	bubble_sort = dlsym(lib_handle, "bubble_sort");
	write_file = dlsym(lib_handle, "write_file");
	len_array_int = dlsym(lib_handle, "len_array_int");
	len_array_double = dlsym(lib_handle, "len_array_double");
	dynamic_array_int = dlsym(lib_handle, "dynamic_array_int");
	dynamic_array_double = dlsym(lib_handle, "dynamic_array_double");

	if (!lib_handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	if (argc > 3 && (*argv[3] == '1' || *argv[3] == '0') && argc < 5)
	{
		int code = 0;
		size_t type;
		int len = (*open_file)(argv[1], (*len_array_int), (*len_array_double), &code, &type);
		if ( !code )
		{

			void* array = (*create_dynamic_array)(argv[1], len, &code, type, (*dynamic_array_double), (*dynamic_array_int));

			int* farray = (int*)malloc(sizeof(int) * len);
			double* dfarray = (double*)malloc(sizeof(double) * len);
			void* array_after_filter = (*filter)(*argv[3], array, &len, type, farray, dfarray);

			bubble_sort(array_after_filter, len, type);

			(*write_file)(argv[2], array_after_filter, type, len, code);

			free(farray);
			free(dfarray);
			free(array_after_filter);
        }
		else
		{
			(*write_file)(argv[2], NULL, type, len, code);
		}
	}
	else
		printf("\nProgram parametrs entering error!\n");
	dlclose(lib_handle);
	return 0;
}
