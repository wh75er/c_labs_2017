CC := gcc

param := -Wall -Werror -std=c99

OBJS := fileWorking.o errorProcessing.o stringProcessing.o

main.out: $(OBJS) main.o
	$(CC) $^ -o $@

main.o: main.c fileWorking.h errorProcessing.h stringProcessing.h
	$(CC) -c main.c -o $@

stringProcessing.o: stringProcessing.c stringProcessing.h
	$(CC) -c stringProcessing.c -o $@

fileWorking.o: fileWorking.c fileWorking.h stringProcessing.h
	$(CC) -c fileWorking.c -o $@

errorProcessing.o: errorProcessing.c errorProcessing.h fileWorking.h
	$(CC) -c errorProcessing.c -o $@

clean:
	rm *.o *.out tests/func/out?.txt tests/unit/*.o tests/unit/*.out

unit_tests:
	tests/unit/unit.sh
