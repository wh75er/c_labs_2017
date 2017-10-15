#include "my_strchr.h"

char *my_strchr(const char *s, int i)
{
	const char *pa;
	for (pa = s; *pa != '\0' && *pa != i; pa++);
	if (*pa == '\0')
		return NULL;
	return (char*)pa;
}

