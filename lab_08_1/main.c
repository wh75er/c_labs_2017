#include "main.h"

int main(int argc, char **argv)
{
	if ( ErrorOut( CommandInputChecking(argc, argv), argv ) )
		return 1;
	if ( ErrorOut( ArrayInit(&mtrx1, &mtrx2, argv), argv ) )
		return 1;
	if ( ErrorOut( MatrixProcessing(&mtrx1, &mtrx2, &mtrx3, argv), argv ) )
		return 1;
	if ( ErrorOut( writeResult(&mtrx3, argv), argv ) )
		return 1;
	return OK;
}

