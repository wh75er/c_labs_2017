#include "unit_tests.h"

int main(int argc, char **argv)
{
	if (argc > 3 && (*argv[3] == 'f' || *argv[3] == 's') && argc < 5)
	{
		if(*argv[3]  == 's')
		{
			int code = 0;
			size_t type;
			int len = open_file(argv[1], len_array_int, len_array_double, &code, &type);
			if (!code)
			{
				void* array_after_filter = create_dynamic_array(argv[1], len, &code, type, dynamic_array_double, dynamic_array_int);
				bubble_sort(array_after_filter, len, type);
				write_file(argv[2], array_after_filter, type, len);

				free(array_after_filter);
			}
			else
			{
				type = -1;
				void* empty;
				write_file(argv[2], empty, type, len);
			}
		}
		else
		{
			int code = 0;
			size_t type;
			int len = open_file(argv[1], len_array_int, len_array_double, &code, &type);
			if (!code)
			{
				void* array = create_dynamic_array(argv[1], len, &code, type, dynamic_array_double, dynamic_array_int);
				char one = ONE;
				char* choice = &one;
				void* array_after_filter = filter(choice, array, &len, type);
				write_file(argv[2], array_after_filter, type, len);

				free(array_after_filter);
			}
			else
			{
				type = -1;
				void* empty;
				write_file(argv[2], empty, type, len);
			}
		}
	}
	else
		printf("\nProgram parametrs entering error!\n");
	return 0;
}
