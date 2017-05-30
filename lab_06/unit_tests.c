#include <stdio.h>
#include <string.h>

#include "insertions_sort.h"
#include "uniq_nums_counter.h"
#include "array_init.h"

#define size_of_string 6

char unit_array_init();
char unit_uniq_nums_counter();
char unit_insertions_sort();

int main()
{
    unit_array_init();
}

char unit_array_init()
{
    // Test 1
    char file_name_in[size_of_string] = "in_0.txt";
    FILE *f = fopen(file_name_in, "r");
    int* pa;
    int code = 0;
    int* pa_fin = array_init(pa, f, &code);

    //not finished

}
