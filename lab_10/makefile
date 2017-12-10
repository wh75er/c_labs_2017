ifndef VERBOSE
.SILENT:
endif

CC := gcc
OBJ := nodeProcessing.o supFunc.o struct.o

mainFile : main.out rmObjc

main.out : $(OBJ) main.o
	$(CC) $^ -o $@
	@echo "Compiling finished"

%.o : %.c *.h
	$(CC) -c $<
	@echo "-DONE"

rmObjc:
	rm *.o

clean:
	rm *.out
