#!/bin/bash

make

for ((i = 0; i < 6; i++))
do
	./main.out	test/in_0$i test/out
	if cmp -s test/out_0$i test/out
	then
		echo "Test $i is PASSED"
	else
		echo "Test $i FAILED"
	fi
done

make clean
