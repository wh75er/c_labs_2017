CC := gcc

param := -Wall -Werror -std=c99

OBJS := dependinces.o errors_processing.o file_working.o matrix_processing.o

main.out: $(OBJS) main.o
	$(CC) $^ -o $@

main.o: main.c dependinces.h errors_processing.h file_working.h matrix_processing.h errors_processing.h
	$(CC) -c main.c -o $@

dependinces.o: dependinces.c dependinces.h
	$(CC) -c dependinces.c -o $@

errors_processing.o: errors_processing.h errors_processing.c
	$(CC) -c errors_processing.c -o $@

file_working.o: file_working.h file_working.c matrix_processing.h
	$(CC) -c file_working.c -o $@

matrix_processing.o: matrix_processing.h matrix_processing.c dependinces.h file_working.h
	$(CC) -c matrix_processing.c -o $@

clean:
	rm *.o tests/*.txt *.out tests/*.out

func_test:
	make
	tests/cmpScr
	make clean
