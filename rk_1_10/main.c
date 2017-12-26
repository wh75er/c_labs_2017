#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LEN 100
enum{
    OK,
    BAD
};


int stringProcessing(FILE* f, char** a)
{
    char line[MAX_STRING_LEN];
    char* z = fgets(line, 100, f);
    printf("%p\n", z);

    int n1, n2;
    sscanf(line, "%d %d", &n1, &n2);
    printf("%d, %d\n", n1, n2);

    int nums[n1][n2];
    int j = 0;
    for(int k = 0; k < n2 + 1; k++){
        fgets(line, 100, f);
        int num;
        char cut[MAX_STRING_LEN];
        char* last_space = line;
        for(char* i = line; *i != '\0'; i++){
            if(*i == ' '){
                strncpy(cut, last_space, i - last_space);
                nums[k][j] = cut - "0";
                last_space = i + 1;
            }
            if(*(i+1) == '\0'){
                strncpy(cut, last_space, i - last_space);
                nums[k][j] = cut - "0";
                printf("%s", cut);
            }
            j++;
        }
    }



    return OK;
}

int writeFile(FILE* f, char** a)
{

}

int main()
{
    char *string[MAX_STRING_LEN];
    FILE* f;
    f = fopen("in.txt", "r");
    printf("%p\n", f);

    stringProcessing(f, string);

    writeFile(f, string);

    return OK;
}
