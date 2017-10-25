#include "main.h"

int main(int argc, char **argv)
{
	args args;
	string text;
	if(isError(argInit(argc, argv, &args), NULL, NULL, NULL))
		return 1;
	if(isError(stringInit(&text), args.fileOut, text.str, text.file))
		return 1;
	if(isError(openFile(args.fileIn, &text.file), args.fileOut, text.str, text.file))
		return 1;
	if(isError(readFile(text.file, text.str), args.fileOut, text.str, text.file))
		return 1;
	if(isError(stringProcessing(args.search, args.replace, text.str), args.fileOut, text.str, text.file))
		return 1;
	printf("%s\n", *text.str);
	if(isError(writeFile(args.fileOut, text.str, OK), args.fileOut, text.str, text.file))
		return 1;
		
	memFree(text.str, text.file);
	return 0;			
}
