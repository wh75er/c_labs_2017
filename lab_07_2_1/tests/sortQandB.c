#include <stdlib.h>
#include <stdio.h>

unsigned long long tick(void) {
	unsigned long long d;
	
	__asm__ __volatile__("rdtsc" : "=A" (d));
	
	return d;
}



int main(int argc, char *argv[]) {

	unsigned long long qsort_s, qsort_f, bubble_s, bubble_f;
	
	qsort_s = tick();
	//qsort
	qsort_f = tick();
	
	bubble_s = tick();
	//bubble_sort
	bubble_f= tick();
	
	printf("Qsort time - %llu\nBubble time - %llu \n", (qsort_f - qsort_s), (bubble_f - bubble_s));
	
	return 0;
}
	
	
