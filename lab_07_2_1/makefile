CC := gcc

param := -Wall -Werror -std=c99

OBJS := compare.o counter.o dynamic_arrays.o sort_filter.o swap.o main_dynamic_array.o file_write.o file_open.o

main.out: $(OBJS) main.o
	$(CC) $^ -o $@

main.o: main.c compare.h counter.h dynamic_arrays.h sort_filter.h swap.h main_dynamic_array.h file_write.h file_open.h
	$(CC) -c main.c -o $@

sort_filter.o: swap.h compare.h sort_filter.h sort_filter.c
	$(CC) -c sort_filter.c -o $@

counter.o: counter.h counter.c
	$(CC) -c counter.c -o $@

dynamic_arrays.o: dynamic_arrays.h dynamic_arrays.c
	$(CC) -c dynamic_arrays.c -o $@

swap.o: swap.h swap.c
	$(CC) -c swap.c -o $@

compare.o: compare.h compare.c
	$(CC) -c compare.c -o $@

main_dynamic_array.o: dynamic_arrays.h main_dynamic_array.h main_dynamic_array.c
	$(CC) -c main_dynamic_array.c -o $@

file_write.o: file_write.h file_write.c
	$(CC) -c file_write.c -o $@

file_open.o: counter.h file_open.h file_open.c
	$(CC) -c file_open.c -o $@

clean:
	rm *.o *.out *.txt tests/func/out?.txt tests/unit/out?.txt
func_test:
	./func_tests
unit_test:
	./unit_tests
