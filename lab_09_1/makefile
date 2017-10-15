#!/bin/bash

CC := gcc

param := -Wall -Werror -std=c99

OBJS := my_strchr.o

module.out: $(OBJS) module.o
	$(CC) $^ -o $@

module.o: module.c my_strchr.h module.h
	$(CC) -c module.c -o $@

my_strchr.o: my_strchr.c my_strchr.h
	$(CC) -c my_strchr.c -o $@

clean:
	rm *.o *.out
