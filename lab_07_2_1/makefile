CC := gcc

param := -Wall -Werror -std=c99

OBJS := compare.o counter.o dynamic_arrays.o sort_filter.o swap.o

main.out: $(OBJS) main.o
	$(CC) $^ -o $@

main.o: main.c compare.h counter.h dynamic_arrays.h sort_filter.h swap.h
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

clean:
	rm *.o *.out