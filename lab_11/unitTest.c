#include "gtest/gtest.h"
#include <limits.h>
#include <stdlib.h>
#include "libs.h"

const char* TEST_1 = "f 10 hello 0x55\n";



TEST (my_snprintf, happyPass) {
	const char* format = "%c %d %s %x";
	char* str = (char*)malloc(sizeof(char) * BUFFSIZE);
	my_snprintf(str, 100, format, 'f', 10, "hello", 0x55);

	ASSERT_STREQ(str, TEST_1);

	free(str);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
