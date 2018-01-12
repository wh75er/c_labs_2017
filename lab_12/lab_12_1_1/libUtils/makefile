CC := gcc

static : staticLib cleanObj

dynamic : dynamicLib cleanObj

staticLib:
	$(CC) -c *.c
	ar -scq libstatic.a *.o

dynamicLib:
	$(CC) -fPIC -c *.c
	$(CC) -shared -o libdynamic.so *.o


cleanObj :
	rm *.o
