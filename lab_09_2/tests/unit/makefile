ifndef VERBOSE
.SILENT:
endif
CC := g++

CFLAGS := -lgtest_main -lgtest -pthread


tests/unit/unitDel.out: stringProcessing.o tests/unit/unit_getdelim.o
	$(CC) $(CFLAGS) $^ -o $@

tests/unit/%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o *.out
