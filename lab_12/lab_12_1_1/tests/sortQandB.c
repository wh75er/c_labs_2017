#include "sortQandB.h"

unsigned long long tick(void);

int cmp (const void * a, const void * b);





int main(int argc, char *argv[]) {

	if (argc > 1 && argc < 3)
	{
		unsigned long long qsort_s, qsort_f, bubble_s, bubble_f;

		int code = 0;
		size_t type;
		int len = open_file(argv[1], len_array_int, len_array_double, &code, &type);

		void* array = create_dynamic_array(argv[1], len, &code, type, dynamic_array_double, dynamic_array_int);
		void* array1 = malloc(len * type);
		array1 = memcpy(array1, array, len*type);

		qsort_s = tick();
		qsort(array, len, type, cmp);
		qsort_f = tick();

		bubble_s = tick();
		bubble_sort(array1, len, type);
		bubble_f= tick();

		printf("Qsort time - %llu\nBubble time - %llu \n", (qsort_f - qsort_s), (bubble_f - bubble_s));
	}
	else
		printf("Parameters entering error!");
	
	return 0;
}
	









unsigned long long tick(void)
{
	unsigned long long d;

	__asm__ __volatile__("rdtsc" : "=A" (d));

	return d;
}

int cmp (const void * a, const void * b)
{
   return ( *(double*)a - *(double*)b );
}
