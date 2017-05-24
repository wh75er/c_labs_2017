CC := gcc

param := -Wall -Werror -std=c99

OBJS := array_init.o swap.o insertions_sort.o uniq_nums_counter.o

main.out: $(OBJS) main.o
	$(CC) $^ -o $@

main.o: main.c array_init.h swap.h insertions_sort.h uniq_nums_counter.h
	$(CC) -c main.c -o $@

array_init.o: array_init.c array_init.h
	$(CC) -c array_init.c -o $@

insertions_sort.o: swap.h insertions_sort.h insertions_sort.c
	$(CC) -c insertions_sort.c -o $@

swap.o: swap.h swap.c
	$(CC) -c swap.c -o $@

uniq_nums_counter.o: uniq_nums_counter.h uniq_nums_counter.c
	$(CC) -c uniq_nums_counter.c

clean:
	rm *.o *.out
