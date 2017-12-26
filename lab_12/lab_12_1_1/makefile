CC := gcc

OBJS := compare.o counter.o dynamic_arrays.o sort_filter.o swap.o main_dynamic_array.o file_write.o file_open.o

mainCreate : main.out cleanObj

main.out: $(OBJS) main.o
	$(CC) $^ -o $@

%.o : %.c *.h
	$(CC) -c $<


cleanObj :
	rm *.o
clean:
	rm *.o *.out *.txt tests/func/out?.txt tests/unit/out?.txt

func_test:
	./func_tests
unit_test:
	./unit_tests
