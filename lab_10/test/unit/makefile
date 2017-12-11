ifndef VERBOSE
.SILENT:
endif
CC := g++

CFLAGS := -lgtest_main -lgtest -pthread -g
OBJC := ../../nodeProcessing.o ../../struct.o ../../smallFunctions/sub_func.o

mainFile: unit_tests.out rm

unit_tests.out: $(OBJC) unit_tests.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: ../../%.c ../../*.h ../../smallFunctions/sub_func.h ../../smallFunctions/sub_func.c
	$(CC) $(CFLAGS) -c $<

rm:
	rm *.o ../../*.o ../../smallFunctions/*.o

clean:
	rm *.out
