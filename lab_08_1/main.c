#include "main.h"

int main(int argc, char **argv)
{
	if ( ErrorOut( CommandInputChecking(&cmd, argc, argv), cmd.out ) )
		return 1;
	if ( ErrorOut( ArrayInit(&mtrx1, &mtrx2, cmd.in_1, cmd.in_2), cmd.out ) )
		return 1;
	if ( ErrorOut( MatrixProcessing(&mtrx1, &mtrx2, &mtrx3, cmd.choice), cmd.out ) )
		return 1;
	if ( ErrorOut( writeResult(&mtrx3, &cmd), cmd.out ) )
		return 1;
	return OK;
}

