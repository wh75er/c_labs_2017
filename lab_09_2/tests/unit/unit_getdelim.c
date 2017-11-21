#include "gtest/gtest.h"
#include <limits.h>
#include "../../stringProcessing.h"
#include <stdlib.h>

const char* TEST_1 = "Happy birthday 30\n";
const char* TEST_2 = "LetsTryThis\n";
const char* TEST_3 = "You have to realize that those men where\n"
                         "way over their prime at that moment and still\n";
const char* TEST_4 = "\0\n";

FILE *streamInit(const char *string, void *buf) {
	FILE *f = fmemopen(buf, strlen(string) + 1, "w+");
	if(!f)
		return NULL;
	fprintf(f, "%s", string);
	rewind(f);

	return f;
}



TEST (my_getdelim, spacesPass) {
	char* str = NULL;
	size_t buffsize = 0;
	void* buff = malloc(2048);
	if(!buff)
		return;
	FILE* stream = streamInit(TEST_1, buff);	
	if(!stream)
		return;
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	if(!result)
		return;
	memset(result, '\0', 4096);

	while(my_getdelim(&str, &buffsize, ' ', stream) > 0) {
		result = strcat(result, str);
		free(str);
		str = NULL;
		buffsize = 0;
	}

	ASSERT_STREQ(TEST_1, result);

	free(str);
	free(result);
	free(buff);
	fclose(stream);
}

TEST (my_getdelim, withoutSpacesPass) {
	char* str = NULL;
	size_t buffsize = 0;
	void* buff = malloc(2048);
	if(!buff)
		return;
	FILE* stream = streamInit(TEST_2, buff);	
	if(!stream)
		return;
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	if(!result)
		return;
	memset(result, '\0', 4096);

	while(my_getdelim(&str, &buffsize, ' ', stream) > 0) {
		result = strcat(result, str);
		free(str);
		str = NULL;
		buffsize = 0;
	}

	ASSERT_STREQ(TEST_2, result);

	free(str);
	free(result);
	free(buff);
	fclose(stream);
}

TEST (my_getdelim, LinePass) {
	char* str = NULL;
	size_t buffsize = 0;
	void* buff = malloc(4096);
	if(!buff)
		return;
	FILE* stream = streamInit(TEST_3, buff);	
	if(!stream)
		return;
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	if(!result)
		return;
	memset(result, '\0', 4096);

	while(my_getdelim(&str, &buffsize, '\n', stream) > 0) {
		result = strcat(result, str);
		free(str);
		str = NULL;
		buffsize = 0;
	}

	 
	ASSERT_STREQ(TEST_3, result);

	free(str);
	free(result);
	free(buff);
	fclose(stream);
}


TEST (my_getdelim, LineStages_part_by_part) {
	char* str = NULL;
	size_t buffsize = 0;
	void* buff = malloc(2048);
	if(!buff)
		return;
	FILE* stream = streamInit(TEST_3, buff);	
	if(!stream)
		return;
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	if(!result)
		return;
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
	 
	ASSERT_STREQ(TEST_3, result);
						 

	free(str);
	free(result);
	free(buff);
	fclose(stream);
}

TEST (my_getdelim, NULL_thing_inside) {
	char* str = NULL;
	size_t buffsize = 0;
	void* buff = malloc(2048);
	if(!buff)
		return;
	FILE* stream = streamInit(TEST_4, buff);	
	if(!stream)
		return;
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	if(!result)
		return;
	memset(result, '\0', 4096);

	while(my_getdelim(&str, &buffsize, ' ', stream) > 0) { result = strcat(result, str);
		free(str);
		str = NULL;
		buffsize = 0;
	}

	ASSERT_STREQ(TEST_4, result);

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
