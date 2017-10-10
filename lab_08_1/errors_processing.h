#ifndef __ERRORS_H__
#define __ERRORS_H__

#include "libs.h"

int CommandInputChecking(struct args *args, const int argc, char** argv);
int ErrorOut(const int code, const char* fileName);

#endif
