#ifndef __STRING_C__
#define __STRING_C__

#include "libs.h"

ssize_t my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream);
char* strReplace(const char *source, const char *search, const char *replace);
int strLen(const char *str);
int stringProcessing(const char *search, const char *replace, char** str);

int stringInit(string *text);
int argInit(const int argc, char** argv, args *args);

#endif
