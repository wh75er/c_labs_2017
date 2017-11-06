#ifndef __DEP_H__
#define __DEP_H__

#include "libs.h"

int copyMatrix(const struct DoubleArray *mtrx_in, struct DoubleArray *mtrx_out);
void maxFindingMatrix(double* max, int* tmp, const int indent, const struct DoubleArray *mtrx, const int j);
void linesSwitch(int* indent, int* tmp, struct DoubleArray *mtrx);

#endif
