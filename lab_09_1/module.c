#include "module.h"

int main()
{
	int count = 1;

	char* test_1_finding_chr = "afqwehfqi1245";
	char test_1_chr = 'i';
	
	char* myRsl = my_strchr(test_1_finding_chr, test_1_chr);
	char* rsl = strchr(test_1_finding_chr, test_1_chr);
	if (myRsl == rsl)
		printf("Test %d is OK\n", count);
	else
		printf("Test %d is BAD\n", count);
	count++;

	char* test_2_finding_chr = "afqwehfqi1245";
	char test_2_chr = '5';
	
	myRsl = my_strchr(test_2_finding_chr, test_2_chr);
	rsl = strchr(test_2_finding_chr, test_2_chr);
	if (myRsl == rsl)
		printf("Test %d is OK\n", count);
	else
		printf("Test %d is BAD\n", count);
	count++;

	char* test_3_finding_chr = "afqwehfqi1245";
	char test_3_chr = 'a';
	
	myRsl = my_strchr(test_3_finding_chr, test_3_chr);
	rsl = strchr(test_3_finding_chr, test_3_chr);
	if (myRsl == rsl)
		printf("Test %d is OK\n", count);
	else
		printf("Test %d is BAD\n", count);
	count++;

	char* test_4_null = "afqwehfqi1245";
	char test_4_chr = 'm';
	
	myRsl = my_strchr(test_4_null, test_4_chr);
	rsl = strchr(test_4_null, test_4_chr);
	if (myRsl == rsl)
		printf("Test %d is OK\n", count);
	else
		printf("Test %d is BAD\n", count);
	count++;

	return 0;
}
