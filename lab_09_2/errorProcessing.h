#ifndef __ERROR_C__
#define __ERROR_C__

#include "libs.h"
#include "fileWorking.h"

int isError(const int code, const char* fileOut, char** strFree, FILE* fFree);
void memFree(char** str, FILE* f);

#endif
