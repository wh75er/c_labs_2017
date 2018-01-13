ifdef _SILENCE
.SILENT:
endif

static : static.out cleanObj

dynamic : dynamic.out cleanObj

dynamicLoad : dynamicLoad.out cleanObj

static.out: main.o
	cd libUtils/ && make static
	gcc -c main.c
	gcc *.o -o $@ libUtils/libstatic.a 

dynamic.out: main.o
	cd libUtils/ && make dynamic
	gcc -c main.c
	gcc *.o -o $@ libUtils/libdynamic.so

dynamicLoad.out: mainLoad.o
	cd libUtils/ && make dynamic
	gcc -c mainLoad.c
	gcc *.o -o $@ -ldl


cleanObj :
	rm *.o 2> /dev/null
clean:
	rm *.o *.out *.txt tests/func/out?.txt tests/unit/out?.txt 2> /dev/null

func_test:
	./func_tests
