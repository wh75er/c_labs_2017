#!/bin/bash

make

echo Func tests:
echo
for ((i = 0; i < 5; i++))
	do
		./main.out tests/func/in$i.txt tests/func/out$i.txt -s 2 -r av 
		if cmp -s tests/func/out$i.txt tests/func/out_$i.txt
		then
			echo "Test $i is OK"
		else
			echo "Test $i is BAD"
		fi
		if [ $i == 4 ]; then
			echo "Tests PASSED"
		fi
	done

make clean
