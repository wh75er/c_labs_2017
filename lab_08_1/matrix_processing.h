#ifndef __MATRIX_H__
#define __MANTRIX_H__

#include "libs.h"
#include "dependinces.h"
#include "file_working.h"

int ArrayInit(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, char **argv);
int DynamicInit(struct DoubleArray *mtrx);
int MatrixAmount(const struct DoubleArray *mtrx1, const struct DoubleArray *mtrx2, struct DoubleArray *mtrx3);
int MatrixMulti(const struct DoubleArray *mtrx1, const struct DoubleArray *mtrx2, struct DoubleArray *mtrx3);
int MatrixGaussian(const struct DoubleArray *mtrx1, struct DoubleArray *mtrx3);
int MatrixProcessing(struct DoubleArray *mtrx1, struct DoubleArray *mtrx2, struct DoubleArray *mtrx3, char **choice);

#endif
