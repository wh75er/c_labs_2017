#!/bin/bash

make -f tests/unit/makefile
tests/unit/unitDel.out
make clean
