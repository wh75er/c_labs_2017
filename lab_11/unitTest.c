#include "gtest/gtest.h"
#include <limits.h>
#include <stdlib.h>
#include "libs.h"

const char* TEST_1 = "f 10 hello 0x55";
const char* TEST_2 = "The size of something : 116km and name of it Lorry";
const char* TEST_3 = "This word <test> staying before this";



TEST (my_snprintf, happyPass) {
	const char* format = "%c %d %s %x";
	char* str = (char*)malloc(sizeof(char) * BUFFSIZE);
	my_snprintf(str, 100, format, 'f', 10, "hello", 0x55);

	ASSERT_STREQ(str, TEST_1);

	free(str);
}

TEST (my_snprintf, int_and_str_with_string) {
	const char* format = "The size of something : %dkm and name of it %s";
	char* str = (char*)malloc(sizeof(char) * BUFFSIZE);
	my_snprintf(str, 100, format, 116, "Lorry");

	ASSERT_STREQ(str, TEST_2);

	free(str);
}

TEST (my_snprintf, string_after_format) {
	const char* format = "This word %s staying before this";
	char* str = (char*)malloc(sizeof(char) * BUFFSIZE);
	my_snprintf(str, 100, format, "<test>");

	ASSERT_STREQ(str, TEST_3);

	free(str);
}


int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
