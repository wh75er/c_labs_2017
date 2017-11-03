#!/bin/bash

make -f tests/unit/makefile
tests/unit/unitDel.out
make -f tests/unit/makefile clean
