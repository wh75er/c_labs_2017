#include "gtest/gtest.h"
#include <limits.h>
#include <stdlib.h>
#include "func.c"

const char* TEST_1 = "f 10 hello 0x55\n";



TEST (my_snprintf, happyPass) {
	char* format = "%c %d %s %x";
	char* str = NULL;
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
