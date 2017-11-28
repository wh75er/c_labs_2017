#include <stdio.h>
#define MAX_BUFFER_LEN 14

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
	
	int wordLen = 0;
	double wordLenAvarage = 0;
	char* s = fgets(buffer, MAX_BUFFER_LEN, f);
	while(s) {
		printf("%s\n", buffer);
		for(int i = 0; i < MAX_BUFFER_LEN - 1 && buffer[i] != '\0'; i++) {
			if(buffer[i] == ' ') {
				wordLenAvarage += wordLen;
				wordLenAvarage /= 2;
				wordLen = 0;
			}
			else if(buffer[i] != '\0' && buffer[i] != '\n') {
				wordLen++;
			}
			if(buffer[i+1] == '\0' && !s) {
				wordLenAvarage += wordLen;
				wordLenAvarage /= 2;
				wordLen = 0;
			}
		}
//		for(int i = 0; i < MAX_BUFFER_LEN; i++)
//			buffer[i] = '\0';
		s = fgets(buffer, MAX_BUFFER_LEN, f);
	}
	if(!s) {
		wordLen = 0;
		for(int i = 0; i < MAX_BUFFER_LEN - 1 && buffer[i] != '\0'; i++) {
			if(buffer[i] == ' ') {
				wordLen = 0;
			}
			else if(buffer[i] != '\0' && buffer[i] != '\n') {
				wordLen++;
			}
			if(buffer[i+1] == '\0' && !s) {
				wordLenAvarage += wordLen;
				if(wordLenAvarage > wordLen)
					wordLenAvarage /= 2;
				wordLen = 0;
			}
		}
	}
	
	if(wordLenAvarage)
		printf("Result is %lf\n", wordLenAvarage);
	else
		printf("Didnt find a word\n");

	return 0;
}
