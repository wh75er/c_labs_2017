ifndef VERBOSE
.SILENT:
endif

CC := gcc
OBJ := libs.o

mainFile : main.out rmObjc

main.out : $(OBJ) func.o
	$(CC) $^ -o $@
	@echo "Compiling finished"

%.o : %.c *.h
	$(CC) -c $<
	@echo "-DONE"

rmObjc:
	rm *.o

clean:
	rm *.out *.o
