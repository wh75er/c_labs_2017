#include <stdio.h>
#define MAX_BUFFER_LEN 1000

enum {
	OK = 0,
	BAD = 1,
};


int fileOpen(FILE** f, const char* name)
{
	*f = fopen(name, "r");
	if(!f)
		return BAD;

	return OK;
}



int main(int argc, char** argv)
{
	const char* name = argv[1];
	FILE* f;
	char buffer[MAX_BUFFER_LEN];

	for(int i = 0; i < MAX_BUFFER_LEN; i++)
		buffer[i] = '\0';
	
	int code = fileOpen(&f, name);
	if(code) {
		printf("File open error!\n");
		return 1;
	}
	
	fgets(buffer, MAX_BUFFER_LEN, f);
	printf("%s", buffer);
	int wordLen = 0;
	double wordLenAmount = 0, count = 0;
	for(int i = 0; i < MAX_BUFFER_LEN - 1 && buffer[i] != '\0'; i++) {
		if(buffer[i] == ' ') {
			wordLenAmount += wordLen;
			count++;
			wordLen = 0;
		}
		else if(buffer[i] != '\0' && buffer[i] != '\n') {
			wordLen++;
		}
		if(buffer[i+1] == '\0') {
			wordLenAmount += wordLen;
			count++;
			wordLen = 0;
		}
	}

	
	if(count)
		printf("Result is %lf\n", wordLenAmount/count);
	else
		printf("Didnt find a word\n");

	return 0;
}
