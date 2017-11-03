#include "gtest/gtest.h"
#include <limits.h>
#include "../../stringProcessing.h"
#include <stdlib.h>

const char* test_1 = "Happy birthday 30\n";
const char* test_2 = "LetsTryThis\n";
const char* test_3 = "You have to realize that those men where"
                         "way over their prime at that moment and still"
                         "were able to create such incredible song, with"
                         "such harmony, power and individuality. RIP to"
                         "these both unforgettable legends. You will be"
                         "ever timeless.\n";
const char* test_4 = "\0\n";

FILE *streamInit(const char *string, void *buf) {
	FILE *f = fmemopen(buf, strlen(string) + 1, "w+");
	fprintf(f, "%s", string);
	rewind(f);

	return f;
}



TEST (my_getdelim, spacesPass) {
	char* str = NULL;
	size_t buffsize = 1024;
	void* buff = malloc(2048);
	FILE* stream = streamInit(test_1, buff);	
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	memset(result, '\0', 4096);

	while(my_getdelim(&str, &buffsize, ' ', stream) > 0) {
		result = strcat(result, str);
		free(str);
		str = NULL;
		buffsize = 1024;
	}

	ASSERT_STREQ("Happy birthday 30\n", result);

	free(str);
	free(result);
	fclose(stream);
}

TEST (my_getdelim, withoutSpacesPass) {
	char* str = NULL;
	size_t buffsize = 1024;
	void* buff = malloc(2048);
	FILE* stream = streamInit(test_2, buff);	
	ssize_t status = 0;
	char* result = (char*)malloc(4096);
	memset(result, '\0', 4096);

	while(my_getdelim(&str, &buffsize, ' ', stream) > 0) {
		printf("%s\n", str);
		result = strcat(result, str);
		free(str);
		str = NULL;
		buffsize = 1024;
	}

	ASSERT_STREQ("LetsTryThis\n", result);

	free(str);
	free(result);
	fclose(stream);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
