ifdef _SILENCE
.SILENT:
endif

static : static.out cleanObj

dynamic : dynamic.out cleanObj

static.out: main.o
	cd libUtils/ && make static
	gcc -c main.c
	gcc *.o -o $@ libUtils/libstatic.a

dynamic.out: main.o
	cd libUtils/ && make dynamic
	gcc -c main.c
	gcc *.o -o $@ libUtils/libdynamic.so


cleanObj :
	rm *.o 2> /dev/null
clean:
	rm *.o *.out *.txt tests/func/out?.txt tests/unit/out?.txt 2> /dev/null

func_test:
	./func_tests
unit_test:
	./unit_tests
