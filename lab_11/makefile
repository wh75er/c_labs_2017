ifndef VERBOSE
.SILENT:
endif

CC := g++
OBJ := libs.o func.o

CFLAGS := -lgtest_main -lgtest -pthread -g

mainFile : test.out rmObjc

test.out : $(OBJ) unitTest.o
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Compiling finished"

%.o : %.c *.h
	$(CC) $(CFLAGS) -c $<
	@echo "-DONE"

rmObjc:
	rm *.o

clean:
	rm *.out *.o
