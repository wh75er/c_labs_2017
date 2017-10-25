#ifndef __FILE_C__
#define __FILE_C__

#include "libs.h"
#include "stringProcessing.h"

int openFile(const char* fileIn, FILE** f);
int readFile(FILE* f, char** str);
int writeFile(const char* fileOut, char** str, int code);

#endif
