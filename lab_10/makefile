CC := gcc
OBJ := nodeProcessing.o supFunc.o struct.o

#main : main.out


main.out : $(OBJ) main.o
	$(CC) $^ -o $@

%.o : %.c *.h
	$(CC) -c $<

clean:
	rm *.o *.out
