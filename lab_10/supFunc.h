#ifndef __SUP_FUNC_H__
#define __SUP_FUNC_H__

#include "libs.h"
#include "supFunc.c"

int fileOpen(FILE **f, const char *name);
int initNode(node_t **head, FILE *f);

void writeToFile(int code, node_t* head, const char* name);

int argsInit(int argc);
int isError(int code, node_t **head, const char* name);


#endif
