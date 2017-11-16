#ifndef __FILE_WORK_H__
#define __FILE_WORK_H__

#include "libs.h"
#include "matrix_processing.h"
#include "matrix_processing.h"

int ReadingFile(FILE* f, struct DoubleArray *mtrx);
FILE* WorkingFile(const char *name, int* code);
int fileWriteMatrix(struct DoubleArray *mtrx, const char* outFile, const char option);
int writeResult(struct DoubleArray *mtrx, struct args * args);

#endif
