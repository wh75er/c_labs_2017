#include "gtest/gtest.h"
#include <limits.h>
#include "../../stringProcessing.h"
#include <stdlib.h>

const char* test_1 = "Happy birthday 30\n";
const char* test_2 = "LetsTryThis\n";
const char* test_3 = "You have to realize that those men where\n"
                         "way over their prime at that moment and still\n";
const char* test_4 = "\0\n";

FILE *streamInit(const char *string, void *buf) {
	FILE *f = fmemopen(buf, strlen(string) + 1, "w+");
	fprintf(f, "%s", string);
	rewind(f);

	return f;
}



TEST (my_getdelim, spacesPass) {
	char* str = NULL;
	size_t buffsize = 0;
	void* buff = malloc(2048);
	FILE* stream = streamInit(test_1, buff);	
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	memset(result, '\0', 4096);

	while(my_getdelim(&str, &buffsize, ' ', stream) > 0) {
		result = strcat(result, str);
		free(str);
		str = NULL;
		buffsize = 0;
	}

	ASSERT_STREQ("Happy birthday 30\n", result);

	free(str);
	free(result);
	free(buff);
	fclose(stream);
}

TEST (my_getdelim, withoutSpacesPass) {
	char* str = NULL;
	size_t buffsize = 0;
	void* buff = malloc(2048);
	FILE* stream = streamInit(test_2, buff);	
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	memset(result, '\0', 4096);

	while(my_getdelim(&str, &buffsize, ' ', stream) > 0) {
		result = strcat(result, str);
		free(str);
		str = NULL;
		buffsize = 0;
	}

	ASSERT_STREQ("LetsTryThis\n", result);

	free(str);
	free(result);
	free(buff);
	fclose(stream);
}

TEST (my_getdelim, LinePass) {
	char* str = NULL;
	size_t buffsize = 0;
	void* buff = malloc(4096);
	FILE* stream = streamInit(test_3, buff);	
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	memset(result, '\0', 4096);

	while(my_getdelim(&str, &buffsize, '\n', stream) > 0) {
		result = strcat(result, str);
		free(str);
		str = NULL;
		buffsize = 0;
	}

	 
	ASSERT_STREQ("You have to realize that those men where\n"
                         "way over their prime at that moment and still\n", result);

	free(str);
	free(result);
	free(buff);
	fclose(stream);
}


TEST (my_getdelim, LineStages_part_by_part) {
	char* str = NULL;
	size_t buffsize = 0;
	void* buff = malloc(2048);
	FILE* stream = streamInit(test_3, buff);	
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	memset(result, '\0', 4096);

	my_getdelim(&str, &buffsize, '\n', stream);
	result = strcat(result, str);
	free(str);
	str = NULL;
	buffsize = 0;
	
	ASSERT_STREQ("You have to realize that those men where\n", result);

	my_getdelim(&str, &buffsize, '\n', stream);
	result = strcat(result, str);
	free(str);
	str = NULL;
	buffsize = 0;
	 
	ASSERT_STREQ("You have to realize that those men where\n"
                         "way over their prime at that moment and still\n", result);
						 

	free(str);
	free(result);
	free(buff);
	fclose(stream);
}

TEST (my_getdelim, NULL_thing_inside) {
	char* str = NULL;
	size_t buffsize = 0;
	void* buff = malloc(2048);
	FILE* stream = streamInit(test_4, buff);	
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	memset(result, '\0', 4096);

	while(my_getdelim(&str, &buffsize, ' ', stream) > 0) {
		result = strcat(result, str);
		free(str);
		str = NULL;
		buffsize = 0;
	}

	ASSERT_STREQ("\0", result);

	free(str);
	free(result);
	free(buff);
	fclose(stream);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
