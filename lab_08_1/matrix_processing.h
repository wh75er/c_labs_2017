#ifndef __MATRIX_H__
#define __MANTRIX_H__

#include "libs.h"
#include "dependinces.h"
#include "file_working.h"

int ArrayInit(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, const char * fileIn1, const char *fileIn2);
int DynamicInit(struct DoubleArray *mtrx);
void matrixFree(struct DoubleArray * mtrx);
int MatrixAmount(const struct DoubleArray *mtrx1, const struct DoubleArray *mtrx2, struct DoubleArray *mtrx3);
int MatrixMulti(const struct DoubleArray *mtrx1, const struct DoubleArray *mtrx2, struct DoubleArray *mtrx3);
int MatrixGaussian(const struct DoubleArray *mtrx1, struct DoubleArray *mtrx3);
int MatrixProcessing(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, struct DoubleArray *mtrx3, const char *choice);

#endif
